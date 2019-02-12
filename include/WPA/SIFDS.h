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
    ICFG *icfg;
    PointerAnalysis *pta;

public:
    class PathNode;
    class PathEdge;

    typedef std::set<const PAGNode *> Datafact;    //set of uninitialized variables at ICFGNode
    typedef std::set<Datafact> Facts;       //different datafacts from different path
    typedef std::set<const ICFGNode *> ICFGNodeSet;
    typedef std::list<PathEdge *> PathEdgeSet;    //to do : list -> vector (faster)
    typedef std::map<const ICFGNode *, Facts> ICFGNodeToDataFactsMap;

protected:
    PathEdgeSet WorkList;         //worklist used during the tabulation algorithm
    PathEdgeSet PathEdgeList;     //used to restore all PathEdges (result)
    PathEdgeSet SummaryEdgeList;  //used to restore all SummaryEdges
    ICFGNodeSet ICFGDstNodeSet;
    ICFGNodeSet SummaryICFGDstNodeSet;
    ICFGNodeToDataFactsMap ICFGNodeToFacts;
    ICFGNodeToDataFactsMap SummaryICFGNodeToFacts;
    ICFGNode *mainEntryNode;
    Facts MainExitFacts;
    int32_t estimatedDatafacts;

public:
    inline VFG *getVFG() const {
        return icfg->getVFG();
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
    void propagate(PathNode *srcPN, ICFGNode *succ, Datafact& d);
    void PEPropagate(PathNode *srcPN, ICFGNode *succ, Datafact& d);
    //transfer function of given ICFGNode
    Datafact& transferFun(const ICFGNode *icfgNode, Datafact& fact);

    //whether the variable is initialized
    bool isInitialized(const PAGNode *pagNode, Datafact& datafact);

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

    // in order to denote : <node, d> , d here is datafact before the execution of node
    class PathNode {
        const ICFGNode *icfgNode;
        Datafact datafact;
        PathNode *caller;   // for sp node

        //Constructor
    public:
        PathNode(){
        }

        PathNode(const ICFGNode *node, const Datafact& fact) : caller (NULL){
            icfgNode = node;
            datafact = fact;
        }

        void setCaller(PathNode *caller){
            this->caller = caller;
        }

        PathNode* getCaller(){
            return this->caller;
        }

        void setICFGNode(ICFGNode *node) {
            icfgNode = node;
        }

        void setDataFact(Datafact &fact) {
            datafact = fact;
        }

        const ICFGNode *getICFGNode() const {
            return icfgNode;
        }

        Datafact &getDataFact() {
            return datafact;
        }

    };

// in order to denote : <node1, d1> --> <node2, d2>
    class PathEdge {
        PathNode *srcNode;
        PathNode *dstNode;

    public:
        PathEdge();

        PathEdge(PathNode *src, PathNode *dst) {
            srcNode = src;
            dstNode = dst;
        }

        void setStartPathNode(PathNode *node) {
            srcNode = node;
        }

        void setEndPathNode(PathNode *node) {
            dstNode = node;
        }

        PathNode *getDstPathNode() const {
            return dstNode;
        }

        PathNode *getSrcPathNode() const {
            return srcNode;
        }
    };
};

#endif //INCLUDE_WPA_SIFDS_H