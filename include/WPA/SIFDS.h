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

    ICFG *icfg;
    PointerAnalysis *pta;

public:
    class PathNode;
    class StartPathNode;
    class PathEdge;

    typedef std::pair<const PAGNode*, bool> MarkedVar;   // false is initialised, true is uninitialised, ex: <PAGNodeID 1, true>
    typedef std::set<MarkedVar> Datafact; //ex: {<PAGNode 1, true>, <PAGNode 2, false>}


    //typedef std::set<const PAGNode *> Datafact;    //set of uninitialized variables at ICFGNode
    typedef std::set<Datafact> Facts;       //different datafacts from different path
    typedef std::set<const SVFGNode *> SVFGNodeSet;
    typedef std::list<PathEdge *> PathEdgeSet;    //to do : list -> vector (faster)
    typedef std::map<const SVFGNode *, Facts> SVFGNodeToDataFactsMap;
    typedef std::map<CallSiteID, SVFG::SVFGEdgeSetTy> CSID2SVFGEdgesMapTy;

protected:
    PathEdgeSet WorkList;         //worklist used during the tabulation algorithm
    PathEdgeSet PathEdgeList;     //used to restore all PathEdges (result)
    PathEdgeSet SummaryEdgeList;  //used to restore all SummaryEdges
    SVFGNodeSet SVFGDstNodeSet;
    SVFGNodeSet SummarySVFGDstNodeSet;
    SVFGNodeToDataFactsMap SVFGNodeToFacts;
    SVFGNodeToDataFactsMap SummarySVFGNodeToFacts;
    Facts FinalFacts;
    int32_t estimatedDatafacts;
    SVFG::SVFGEdgeSetTy SVFGCallEdges;
    CSID2SVFGEdgesMapTy CSID2SVFGEdgesMap;

public:
    inline VFG *getSVFG() const {
        return icfg->getSVFG();
    }

    inline ICFG *getICFG() const {
        return icfg;
    }

    inline PAG *getPAG() const {
        return icfg->getPAG();
    }

    //constructor
    SIFDS(ICFG *i);

    //procedures in Tabulation Algorithm
    void initialize();

    void forwardTabulate();

    //add new PathEdge components into PathEdgeList and WorkList
    void propagate(StartPathNode *srcPN, const SVFGNode *succ, Datafact& d);
    void PEPropagate(StartPathNode *srcPN, const SVFGNode *succ, Datafact& d);
    void SEPropagate(PathEdge *e);
    PathEdge* isInSummaryEdgeList(const SVFGNode *node, Datafact& d);
    //transfer function of given ICFGNode
    Datafact transferFun(const SVFGNode *svfgNode, Datafact& fact);

    //whether the variable is initialized
    bool isInitialized(const PAGNode *pagNode, Datafact& datafact);
    bool isUninitialized(const PAGNode *pagNode, Datafact& datafact);
    bool isUnknown(const PAGNode *pagNode, Datafact& datafact);

    //print ICFGNodes and theirs datafacts
    void getIFDSStat();
    void printRes();
    void printPathEdgeList();
    void printSummaryEdgeList();
    void validateTests(const char *fun);

    void printFacts(Facts facts, bool ObjNodeOnly = false);
    Datafact concernedDatafact();

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

        StartPathNode(const SVFGNode *node, const Datafact& fact, StartPathNode *upper, CallSiteID csId) : PathNode(node, fact){
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
