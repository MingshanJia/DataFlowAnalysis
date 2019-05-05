/*
 * SIFDS.h
 *
 */

#ifndef INCLUDE_WPA_SIFDS_H
#define INCLUDE_WPA_SIFDS_H


#include "Util/ICFG.h"
#include "WPA/Andersen.h"
#include <iostream>

class SIFDS {

private:
    SVFG* svfg;  // using svfg in sparsed version
    PAG* pag;
    PointerAnalysis *pta;
public:
    class PathNode;
    class StartPathNode;
    class PathEdge;

    typedef std::pair<const PAGNode*, bool> MarkedVar;   // false is initialised, true is uninitialised, ex: <PAGNodeID 1, true>
    typedef std::set<MarkedVar> Datafact; //ex: {<PAGNode 1, true>, <PAGNode 2, false>}
    typedef std::pair<Datafact, CallSiteID > DFwithCS;

    typedef std::set<DFwithCS> Facts;       //different datafacts from different path
    typedef std::set<const SVFGNode *> SVFGNodeSet;
    typedef std::list<PathEdge *> PathEdgeSet;
    typedef std::map<const SVFGNode *, Facts> SVFGNodeToDataFactsMap;
    typedef std::map<CallSiteID, SVFG::SVFGEdgeSetTy> CSID2SVFGEdgesMapTy;
    typedef std::map<double, SVFG::SVFGEdgeSetTy> SVFGNodeWithCS2SVFGRetEdgesMapTy;

protected:
    PathEdgeSet WorkList;         //worklist used during the tabulation algorithm
    PathEdgeSet PathEdgeList;     //used to restore all PathEdges (result)
    PathEdgeSet SummaryEdgeList;  //used to restore all SummaryEdges
    PathEdgeSet SubSummaryEdgeList;
    SVFGNodeSet SVFGDstNodeSet;
    SVFGNodeSet SummarySVFGNodeSet;
    SVFGNodeToDataFactsMap SVFGNodeToFacts;
    SVFGNodeToDataFactsMap SummarySVFGNodeToFacts;
    int totalVar;
    SVFG::SVFGEdgeSetTy SVFGCallEdges;
    CSID2SVFGEdgesMapTy CSID2SVFGEdgesMap;
    SVFGNodeWithCS2SVFGRetEdgesMapTy SVFGNodeWithCS2SVFGRetEdgesMap;

public:
    inline SVFG *getSVFG() const {
        return svfg;
    }

    inline PAG *getPAG() const {
        return svfg->getPAG();
    }

    //constructor
    SIFDS(SVFG *svfg);

    //procedures in Tabulation Algorithm
    void initialize();

    void forwardTabulate();

    //add new PathEdge components into PathEdgeList and WorkList
    void propagate(StartPathNode *srcPN, const SVFGNode *succ, Datafact& d);
    void PEPropagate(StartPathNode *srcPN, const SVFGNode *succ, Datafact& d);
    void SEPropagate(PathEdge *e);
    PathEdgeSet isInSummaryEdgeListForDir(const SVFGNode *node, Datafact& d);
    PathEdgeSet isInSummaryEdgeListForIndir(const SVFGNode *node, Datafact& d);
    void checkAndUseSummaryEdge(CallSiteID cs, StartPathNode *srcPN, const SVFGNode* succ, Datafact &d);
    //transfer function of given ICFGNode
    Datafact transferFun(const SVFGNode *svfgNode, Datafact& fact);
    Datafact FilterDatafact(Datafact& d, const PointsTo &PTset);

    //whether the variable is initialized
    bool isInitialized(const PAGNode *pagNode, Datafact& datafact);
    bool isUninitialized(const PAGNode *pagNode, Datafact& datafact);
    bool isUnknown(const PAGNode *pagNode, Datafact& datafact);
    void goViaSummaryEdge(const SVFGNode *SEdstNode, Datafact& d, StartPathNode* srcPN, CallSiteID cs);

    //print ICFGNodes and theirs datafacts
    void getIFDSStat();
    void printRes();
    void printPathEdgeList();
    void printSummaryEdgeList();
    void validateTests(const char *fun);
    void printPTset(u32_t id);

    void printFacts(Facts facts, bool ObjNodeOnly = false);

    //Get points-to set of given PAGNode
    inline PointsTo &getPts(NodeID id) {
        return pta->getPts(id);
    }


    class PathNode{
        const SVFGNode *svfgNode;
        Datafact datafact;

    public:

        PathNode(const SVFGNode *node, const Datafact& fact) {
            svfgNode = node;
            datafact = fact;
        }

        void setSVFGNode(SVFGNode *node) {
            svfgNode = node;
        }

        void setDataFact(Datafact &fact) {
            datafact = fact;
        }

        const SVFGNode *getSVFGNode() const {
            return svfgNode;
        }

        Datafact &getDataFact() {
            return datafact;
        }
    };

    class StartPathNode : public PathNode {

        CallSiteID callsiteID;               // use callsite ID to match call and return
        StartPathNode *upperLvlStartPN;   // Upper Level Start PathNode, to deal with Function call

    public:
        //Constructor
        StartPathNode(const SVFGNode *node, const Datafact& fact) : PathNode(node, fact), upperLvlStartPN (NULL) ,callsiteID(0){
        }

        StartPathNode(const SVFGNode *node, const Datafact& fact, CallSiteID csId, StartPathNode *upper) : PathNode(node, fact){
            upperLvlStartPN = upper;
            callsiteID = csId;
        }

        void setUpperLvlStartPN(StartPathNode *pathNode){
            upperLvlStartPN = pathNode;
        }

        StartPathNode* getUpperLvlStartPN(){
            return upperLvlStartPN;
        }

        CallSiteID getCallSiteID(){
            return callsiteID;
        }

        void setCallSiteID(CallSiteID csId){
            callsiteID = csId;
        }
    };

// in order to denote : <node1, d1> --> <node2, d2>
    class PathEdge {
        StartPathNode *srcNode;
        PathNode *dstNode;

    public:
        PathEdge();

        PathEdge(StartPathNode *src, PathNode *dst) {
            srcNode = src;
            dstNode = dst;
        }

        void setStartPathNode(StartPathNode *node) {
            srcNode = node;
        }

        void setEndPathNode(PathNode *node) {
            dstNode = node;
        }

        PathNode *getDstPathNode() const {
            return dstNode;
        }

        StartPathNode *getSrcPathNode() const {
            return srcNode;
        }
    };
};

#endif //INCLUDE_WPA_SIFDS_H
