//
// Created by mingshan on 15/01/19.
//

/*
 * SIFDS.cpp
 *
 */

#include "WPA/SIFDS.h"
#include "Util/ICFGStat.h"

using namespace std;
using namespace SVFUtil;

//constructor
SIFDS::SIFDS(ICFG *i) : icfg(i){  //only need SVFG?
    svfg = icfg->getSVFG();
    pta = AndersenWaveDiff::createAndersenWaveDiff(getPAG()->getModule());
    icfg->updateCallgraph(pta);
    icfg->getVFG()->updateCallGraph(pta);
    getIFDSStat();
    initialize();
    forwardTabulate();
    printRes();
}

/*initialization
    PathEdgeList = {<ds_1, 0> --> <ds_1,0>, <ds_2, 0> --> <ds_2,0>, ... <ds_n, 0> --> <ds_n,0>}
    WorkList = {<ds_1, 0> --> <ds_1,0>, <ds_2, 0> --> <ds_2,0>, ... <ds_n, 0> --> <ds_n,0>}
    SummaryEdgeList = {}
*/
void SIFDS::initialize() {
    Datafact datafact = {};    // datafact = 0;
    for(SVFG::const_iterator it = svfg->begin(), eit = svfg->end(); it != eit; ++it ){
        const SVFGNode *node = it->second;
        if(const DummyStoreSVFGNode* dsNode = SVFUtil::dyn_cast<DummyStoreSVFGNode>(node)){
            StartPathNode * srcPN = new StartPathNode(dsNode, datafact);
            PathNode *dstPN = new PathNode(dsNode, datafact);
            PathEdge *startPE = new PathEdge(srcPN, dstPN);
            PathEdgeList.push_back(startPE);
            WorkList.push_back(startPE);
            SVFGDstNodeSet.insert(dsNode);  //will be used when propagate?
        }
    }
    //initialize SVFGNodeToFacts
    for(SVFG::const_iterator it = svfg->begin(), eit = svfg->end(); it != eit; ++it ){
        const SVFGNode *node = it->second;
        if(node->hasOutgoingEdge() || node->hasIncomingEdge()){
            SVFGNodeToFacts[node] = {};
            SummarySVFGNodeToFacts[node] = {};
        }
    }
    SummaryEdgeList = {};
    FinalFacts = {};    //final facts after caculation
}

void SIFDS::forwardTabulate() {
    while (!WorkList.empty()) {
        PathEdge *e = WorkList.front();
        WorkList.pop_front();
        StartPathNode *srcPN = e->getSrcPathNode();
        const SVFGNode *sa = srcPN->getSVFGNode();
        Datafact& d1 = srcPN->getDataFact();
        PathNode *dstPN = e->getDstPathNode();
        const SVFGNode *n = e->getDstPathNode()->getSVFGNode();
        Datafact& d2 = dstPN->getDataFact();

        if (isa<StmtSVFGNode>(n) || isa<BinaryOPSVFGNode>(n) || isa<CmpSVFGNode>(n) || isa<IntraMSSAPHISVFGNode>(n)) {

            Datafact d = transferFun(n, d2);     //caculate datafact after execution of n
            if(!d.empty()){      // empty means unknown
                if (n->hasOutgoingEdge()){
                    const SVFGEdge::SVFGEdgeSetTy &outEdges = n->getOutEdges();
                    for (SVFGEdge::SVFGEdgeSetTy::iterator it = outEdges.begin(), eit =
                            outEdges.end(); it != eit; ++it) {

                        SVFGNode *succ = (*it)->getDstNode();

                        if (succ != n) //excludes the edge going back to itself(for dummy store)
                            propagate(srcPN, succ, d);
                    }
                }else
                    FinalFacts.insert(d);
            }
        }
    }
}

//add new PathEdge into PathEdgeList and WorkList
void SIFDS::propagate(StartPathNode *srcPN, SVFGNode *succ, Datafact& d) {
    if (SVFGDstNodeSet.find(succ) == SVFGDstNodeSet.end()) {
        PEPropagate(srcPN, succ, d);
        SVFGDstNodeSet.insert(succ);
    } else {
        if (SVFGNodeToFacts[succ].find(d) == SVFGNodeToFacts[succ].end()) {
            PEPropagate(srcPN, succ, d);
        }
    }
}

void SIFDS:: PEPropagate(StartPathNode *srcPN, SVFGNode *succ, Datafact& d){
    PathNode *newDstPN = new PathNode(succ, d);
    PathEdge *e = new PathEdge(srcPN, newDstPN);
    WorkList.push_back(e);
    PathEdgeList.push_back(e);
    SVFGNodeToFacts[succ].insert(d);
}

bool SIFDS::isUnknown(const PAGNode *pagNode, Datafact& datafact) {
    Datafact::iterator it = datafact.find({pagNode,false});
    Datafact::iterator it2 = datafact.find({pagNode,true});
    if (it == datafact.end() && it2 == datafact.end())
        return true;
    else
        return false;
}

bool SIFDS::isInitialized(const PAGNode *pagNode, Datafact& datafact) {
    Datafact::iterator it = datafact.find({pagNode,false});
    if(pagNode->isConstantData())
        return true;
    else if (it == datafact.end())
        return false;
    else
        return true;
}

bool SIFDS::isUninitialized(const PAGNode *pagNode, Datafact& datafact) {
    Datafact::iterator it = datafact.find({pagNode,true});
    if (it == datafact.end())
        return false;
    else
        return true;
}

// StmtNode(excludes cmp and binaryOp)
// Addr: srcNode is unknown, dstNode is initialiazed
// copy: dstNode depends on srcNode
// Store: dstNode->obj depends on srcNode
// Load: dstNode depends on scrNode->obj
// Gep : same as Copy

// PHINode: resNode depends on operands -> getPAGNode
// Cmp & Binary

SIFDS::Datafact SIFDS::transferFun(const SVFGNode *svfgNode, Datafact& fact_before) {

    Datafact fact = fact_before;

    if (const StmtSVFGNode *stmtNode = SVFUtil::dyn_cast<StmtSVFGNode>(svfgNode)) {
        PAGNode *dstPagNode = stmtNode->getPAGDstNode();
        PAGNode *srcPagNode = stmtNode->getPAGSrcNode();
        // DummyStore: dstNode's points-to set is uninitialized, dstNode is initialiazed
        if (SVFUtil::isa<DummyStoreSVFGNode>(stmtNode)) {

            PointsTo &PTset = SIFDS::getPts(dstPagNode->getId());
            for (PointsTo::iterator it = PTset.begin(), eit = PTset.end(); it != eit; ++it) {
                PAGNode *node = getPAG()->getPAGNode(*it);
                fact.insert({node,true});
                fact.erase({node,false});
            }
        }
        // Copy/Gep: dstNode depends on srcNode
        else if (SVFUtil::isa<CopySVFGNode>(stmtNode) || SVFUtil::isa<GepSVFGNode>(stmtNode)) {
            if (isInitialized(srcPagNode, fact)){
                fact = {};
                fact.insert({dstPagNode,false});
                fact.erase({dstPagNode, true});
            }
            else if (isUninitialized(srcPagNode, fact)){
                fact = {};
                fact.insert({dstPagNode,true});
                fact.erase({dstPagNode,false});
            }
            else if (isUnknown(srcPagNode, fact))
                fact = {};
        }
        // Store：dstNode->obj depends on srcNode
        else if (SVFUtil::isa<StoreSVFGNode>(stmtNode)) {
            PointsTo &PTset = SIFDS::getPts(dstPagNode->getId());
            if (isInitialized(srcPagNode, fact)) {
                for (PointsTo::iterator it = PTset.begin(), eit = PTset.end(); it != eit; ++it) {
                    fact = {};
                    PAGNode *node = getPAG()->getPAGNode(*it);
                    fact.insert({node,false});
                    fact.erase({node,true});
                }
            } else if (isUninitialized(srcPagNode, fact)) {
                for (PointsTo::iterator it = PTset.begin(), eit = PTset.end(); it != eit; ++it) {
                    fact = {};
                    PAGNode *node = getPAG()->getPAGNode(*it);
                    fact.insert({node,true});
                    fact.erase({node,false});
                }
            } else if (isUnknown(srcPagNode, fact))
                fact = {};
        }
        // Load：Load: dstNode depends on scrNode->obj
        // if all obj are initialized, dstPagNode is initialized, otherwise dstPagNode is Unini
        else if (SVFUtil::isa<LoadSVFGNode>(stmtNode)) {
            PointsTo PTset = SIFDS::getPts(srcPagNode->getId());
            u32_t sum_ini = 0;
            u32_t sum_unknown = 0;
            u32_t sum_unini = 0;

            for (PointsTo::iterator it = PTset.begin(), eit = PTset.end(); it != eit; ++it) {
                PAGNode *node = getPAG()->getPAGNode(*it);
                sum_ini += isInitialized(node, fact);
                sum_unknown += isUnknown(node, fact);
                sum_unini += isUninitialized(node, fact);
            }
            if(sum_unknown == PTset.count())
                fact = {};
            else if (sum_ini + sum_unknown == PTset.count()){
                fact = {};
                fact.insert({dstPagNode,false});
                fact.erase({dstPagNode,true});
            }
            else{
                fact = {};
                fact.insert({dstPagNode,true});
                fact.erase({dstPagNode,false});
            }
        }
    }
    //BinaryOp: get complete datafact for binaryOp
    else if (const BinaryOPSVFGNode *biOpNode = SVFUtil::dyn_cast<BinaryOPSVFGNode>(svfgNode)){

        const PAGNode *resBiOpNode = biOpNode->getRes();
        assert(biOpNode->getOpVerNum() == 2);
        const PAGNode *OpOne = biOpNode->getOpVer(0);
        const PAGNode *OpTwo = biOpNode->getOpVer(1);

        if(isUninitialized(OpOne, fact) || isUninitialized(OpTwo, fact)){
            fact = {};
            fact.insert({resBiOpNode,true});
            fact.erase({resBiOpNode,false});
        }
        else if (isInitialized(OpOne, fact) || isInitialized(OpTwo, fact)){
            fact = {};
            fact.insert({resBiOpNode,false});
            fact.erase({resBiOpNode,true});
        }
    }
    return fact;
}

// print ICFGNodes and theirs datafacts
void SIFDS::getIFDSStat() {
    icfg->getStat()->performStatforIFDS();
    Datafact fact = concernedDatafact();
    estimatedDatafacts = fact.size();
    cout << "Datafact(D)         " << estimatedDatafacts << endl;
    std::cout << "-------------------------------------------------------\n";
  cout << "\n";
}

SIFDS::Datafact SIFDS::concernedDatafact() {
    Datafact fact = {};
    for (PAG::const_iterator it = (icfg->getPAG())->begin(), eit = icfg->getPAG()->end(); it != eit; ++it) {
        PAGNode *node = it->second;
        if (node->hasIncomingEdge() || node->hasOutgoingEdge() && node->getFunction()) { // nodes has edges
            bool excluded = false;    // excluded == false means add into fact
            if (node->isConstantData())
                excluded = true;
            if (ObjPN *objNode = SVFUtil::dyn_cast<ObjPN>(node))
                if (objNode->getMemObj()->isFunction())
                    excluded = true;
            PAGEdge::PAGEdgeSetTy edges = node->getIncomingEdges(PAGEdge::Addr);
            for (PAGEdge::PAGEdgeSetTy::iterator it = edges.begin(), eit = edges.end(); it != eit; ++it) {
                PAGEdge *e = *it;
                if (ObjPN *objNode = SVFUtil::dyn_cast<ObjPN>(e->getSrcNode()))
                    if (objNode->getMemObj()->isFunction())
                        excluded = true;
            }
            if (!excluded) //add eligible PAGNode into fact
                fact.insert({node,true});
        }
    }
    return fact;
}
void SIFDS::printRes() {
    std::cout << "\n******* Possibly Uninitialized Variables Problem *******\n\n";
    cout << "Analysis Terminates! Possibly uninitialized variables are: {";
    printFacts(FinalFacts, true);
    cout << "}\n\n";

    for (SVFGNodeToDataFactsMap::iterator it = SVFGNodeToFacts.begin(), eit = SVFGNodeToFacts.end(); it != eit; ++it) {
        const SVFGNode *node = it->first;
        Facts facts = it->second;
        NodeID id = node->getId();
        std::cout << "SVFGNodeID:" << id << ": PAGNodeSet: {";
        printFacts(facts);
        cout << "}\n";
    }
    printPathEdgeList();
    printSummaryEdgeList();
    validateTests("checkInit");
    validateTests("checkUninit");
    std::cout << "-------------------------------------------------------" << std::endl;
}
void SIFDS::printFacts(Facts facts, bool ObjNodeOnly) {
    Datafact finalFact = {};
    for (Facts::iterator fit = facts.begin(), efit = facts.end(); fit != efit; ++fit) {
        Datafact fact = (*fit);
        for (Datafact::iterator dit = fact.begin(), edit = fact.end(); dit != edit; ++dit) {
            if ((*dit).second){
                if (ObjNodeOnly){
                    if (const ObjPN *objNode = SVFUtil::dyn_cast<ObjPN>((*dit).first))
                        finalFact.insert(*dit);
                }
                else
                    finalFact.insert(*dit);
            }
        }
    }
    if (finalFact.size() > 1){
        for (Datafact::iterator dit = finalFact.begin(), edit = --finalFact.end(); dit != edit; ++dit)
            std::cout << (*dit).first->getId() << " ";
        std::cout << (*finalFact.rbegin()).first->getId();   //print last element without " "
    }
    else if (finalFact.size() == 1)
        std::cout << (*finalFact.begin()).first->getId();
}

void SIFDS::printPathEdgeList() {
    std::cout << "\n*********** PathEdge **************\n";
    for (PathEdgeSet::const_iterator it = PathEdgeList.begin(), eit = PathEdgeList.end(); it != eit; ++it){
        NodeID srcID = (*it)->getSrcPathNode()->getSVFGNode()->getId();
        NodeID dstID = (*it)->getDstPathNode()->getSVFGNode()->getId();
        Datafact srcFact = (*it)->getSrcPathNode()->getDataFact();
        Datafact dstFact = (*it)->getDstPathNode()->getDataFact();

        cout << "[SVFGNodeID:" << srcID << ",(";
        for (Datafact::const_iterator it = srcFact.begin(), eit = srcFact.end(); it != eit; it++){
            std::cout << "<" << (*it).first->getId() << "," << (*it).second << "> ";

        }
        if (!srcFact.empty())
            cout << "\b";
        cout << ")] --> [SVFGNodeID:" << dstID << ",(";
        for (Datafact::const_iterator it = dstFact.begin(), eit = dstFact.end(); it != eit; it++){
            std::cout << "<" << (*it).first->getId() << "," << (*it).second << "> ";
        }
        if (!dstFact.empty())
            cout << "\b";
        cout << ")]\n";
    }
}
void SIFDS::printSummaryEdgeList() {
    std::cout << "\n*********** SummaryEdge **************\n";
    for (PathEdgeSet::const_iterator it = SummaryEdgeList.begin(), eit = SummaryEdgeList.end(); it != eit; ++it){
        NodeID srcID = (*it)->getSrcPathNode()->getSVFGNode()->getId();
        NodeID dstID = (*it)->getDstPathNode()->getSVFGNode()->getId();
        Datafact srcFact = (*it)->getSrcPathNode()->getDataFact();
        Datafact dstFact = (*it)->getDstPathNode()->getDataFact();

        cout << "[SVFGNodeID:" << srcID << ",(";
        for (Datafact::const_iterator it = srcFact.begin(), eit = srcFact.end(); it != eit; it++){
            std::cout << (*it).first->getId() << " ";
        }
        if (!srcFact.empty())
            cout << "\b";
        cout << ")] --> [SVFGNodeID:" << dstID << ",(";
        for (Datafact::const_iterator it = dstFact.begin(), eit = dstFact.end(); it != eit; it++){
            std::cout << (*it).first->getId() << " ";
        }
        if (!dstFact.empty())
            cout << "\b";
        cout << ")]\n";
    }
}
void SIFDS::validateTests(const char *fun) {
//    for (u32_t i = 0; i < icfg->getPAG()->getModule().getModuleNum(); ++i) {
//        Module *module = icfg->getPAG()->getModule().getModule(i);
//        if (Function *checkFun = module->getFunction(fun)) {
//            for (Value::user_iterator i = checkFun->user_begin(), e =
//                    checkFun->user_end(); i != e; ++i)
//                if (SVFUtil::isa<CallInst>(*i) || SVFUtil::isa<InvokeInst>(*i)) {
//                    CallSite cs(*i);
//                    assert(cs.getNumArgOperands() == 1 && "arguments should one pointer!!");
//                    Value *v1 = cs.getArgOperand(0);
//                    NodeID ptr = icfg->getPAG()->getValueNode(v1);
//                    PointsTo &pts = pta->getPts(ptr);
//                    for (PointsTo::iterator it = pts.begin(), eit = pts.end(); it != eit; ++it) {
//                        const PAGNode *objNode = icfg->getPAG()->getPAGNode(*it);
//                        NodeID objNodeId = objNode->getId();
//                        const CallBlockNode *callnode = icfg->getCallICFGNode(cs);
//                        const Facts &facts = SVFGNodeToFacts[callnode];
//
//                        bool initialize = true;
//                        for (Facts::const_iterator fit = facts.begin(), efit = facts.end(); fit != efit; ++fit) {
//                            const Datafact &fact = (*fit);
//                            if (fact.count(objNode))
//                                initialize = false;
//                        }
//                        if (strcmp(fun, "checkInit") == 0) {
//                            if (initialize)
//                                std::cout << sucMsg("SUCCESS: ") << fun << " check <CFGId:" << callnode->getId()
//                                          << ", objId:" << objNodeId << "> at ("
//                                          << getSourceLoc(*i) << ")\n";
//                            else
//                                std::cout << errMsg("FAIL: ") << fun << " check <CFGId:" << callnode->getId()
//                                          << ", objId:" << objNodeId << "> at ("
//                                          << getSourceLoc(*i) << ")\n";
//                        } else if (strcmp(fun, "checkUninit") == 0) {
//                            if (initialize)
//                                std::cout << errMsg("FAIL: ") << fun << " check <CFGId:" << callnode->getId()
//                                          << ", objId:" << objNodeId << "> at ("
//                                          << getSourceLoc(*i) << ")\n";
//                            else
//                                std::cout << sucMsg("SUCCESS: ") << fun << " check <CFGId:" << callnode->getId()
//                                          << ", objId:" << objNodeId << "> at ("
//                                          << getSourceLoc(*i) << ")\n";
//                        }
//                    }
//                }
//        }
//    }
}