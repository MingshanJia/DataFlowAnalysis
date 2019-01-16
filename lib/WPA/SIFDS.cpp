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
SIFDS::SIFDS(ICFG *i) : icfg(i){
    pta = AndersenWaveDiff::createAndersenWaveDiff(getPAG()->getModule());
    icfg->updateCallgraph(pta);
    icfg->getVFG()->updateCallGraph(pta);
    getIFDSStat();
    initialize();
    forwardTabulate();
    printRes();
}

/*initialization
    PathEdgeList = {(<EntryMain, 0> --> <EntryMain,0>)}
    WorkList = {(<EntryMain, 0> --> <EntryMain,0>)}
    SummaryEdgeList = {}
 */
void SIFDS::initialize() {
    Datafact datafact = {};    // datafact = 0;
    assert(getProgEntryFunction(getPAG()->getModule())); // must have main function as program entry point
    mainEntryNode = icfg->getFunEntryICFGNode(getProgEntryFunction(getPAG()->getModule()));
    PathNode *mainEntryPN = new PathNode(mainEntryNode, datafact);
    PathEdge *startPE = new PathEdge(mainEntryPN, mainEntryPN);
    PathEdgeList.push_back(startPE);
    WorkList.push_back(startPE);
    SummaryEdgeList = {};
    ICFGDstNodeSet.insert(mainEntryNode);

    //initialize ICFGNodeToFacts
    for (ICFG::const_iterator it = icfg->begin(), eit = icfg->end(); it != eit; ++it) {
        const ICFGNode *node = it->second;
        ICFGNodeToFacts[node] = {};
        SummaryICFGNodeToFacts[node] = {};
    }

    MainExitFacts = {};    //facts at main exit node
}

void SIFDS::forwardTabulate() {
    while (!WorkList.empty()) {
        PathEdge *e = WorkList.front();
        WorkList.pop_front();
        PathNode *srcPN = e->getSrcPathNode();
        const ICFGNode *sp = srcPN->getICFGNode();
        Datafact& d1 = srcPN->getDataFact();
        PathNode *dstPN = e->getDstPathNode();
        const ICFGNode *n = e->getDstPathNode()->getICFGNode();
        Datafact& d2 = dstPN->getDataFact();

        if (isa<IntraBlockNode>(n) || isa<FunEntryBlockNode>(n)) {

            Datafact& d = transferFun(n, d2);     //caculate datafact after execution of n
            const ICFGEdge::ICFGEdgeSetTy &outEdges = n->getOutEdges();
            for (ICFGEdge::ICFGEdgeSetTy::iterator it = outEdges.begin(), eit =
                    outEdges.end(); it != eit; ++it) {
                ICFGNode *succ = (*it)->getDstNode();
                propagate(srcPN, succ, d);
            }
        } else if (SVFUtil::isa<FunExitBlockNode>(n)) {
            if(srcPN->getCaller()){

            }
            else if (sp == mainEntryNode)
                MainExitFacts.insert(d2);

        }
    }
}

//add new PathEdge into PathEdgeList and WorkList
void SIFDS::propagate(PathNode *srcPN, ICFGNode *succ, Datafact& d) {
    if (ICFGDstNodeSet.find(succ) == ICFGDstNodeSet.end()) {
        PEPropagate(srcPN, succ, d);
        ICFGDstNodeSet.insert(succ);
    } else {
        if (ICFGNodeToFacts[succ].find(d) == ICFGNodeToFacts[succ].end()) {
            PEPropagate(srcPN, succ, d);
        }
    }
}

void SIFDS:: PEPropagate(PathNode *srcPN, ICFGNode *succ, Datafact& d){
    PathNode *newDstPN = new PathNode(succ, d);
    PathEdge *e = new PathEdge(srcPN, newDstPN);
    WorkList.push_back(e);
    PathEdgeList.push_back(e);
    ICFGNodeToFacts[succ].insert(d);
}

bool SIFDS::isInitialized(const PAGNode *pagNode, Datafact& datafact) {
    Datafact::iterator it = datafact.find(pagNode);
    if (it == datafact.end())
        return true;
    else
        return false;
}

// StmtNode(excludes cmp and binaryOp)
// Addr: srcNode is uninitialized, dstNode is initialiazed
// copy: dstNode depends on srcNode
// Store: dstNode->obj depends on srcNode
// Load: dstNode depends on scrNode->obj
// Gep : same as Copy

// PHINode: resNode depends on operands -> getPAGNode
// Cmp & Binary

SIFDS::Datafact& SIFDS::transferFun(const ICFGNode *icfgNode, Datafact& fact) {
    if (const IntraBlockNode *node = SVFUtil::dyn_cast<IntraBlockNode>(icfgNode)) {
        for (IntraBlockNode::StmtOrPHIVFGNodeVec::const_iterator it = node->vNodeBegin(), eit = node->vNodeEnd();
             it != eit; ++it) {
            const VFGNode *node = *it;
            if (const StmtVFGNode *stmtNode = SVFUtil::dyn_cast<StmtVFGNode>(node)) {
                PAGNode *dstPagNode = stmtNode->getPAGDstNode();
                PAGNode *srcPagNode = stmtNode->getPAGSrcNode();
                // Addr: srcNode is uninitialized, dstNode is initialiazed
                if (const AddrVFGNode *addrNode = SVFUtil::dyn_cast<AddrVFGNode>(stmtNode)) {
                    fact.erase(dstPagNode);
                    if(dstPagNode->isConstantData())
                        fact.erase(srcPagNode);
                    else
                        fact.insert(srcPagNode);
                    if (ObjPN *objNode = SVFUtil::dyn_cast<ObjPN>(srcPagNode))
                        if (objNode->getMemObj()->isFunction())
                            fact.erase(srcPagNode);
                }
                    // Copy: dstNode depends on srcNode
                else if (const CopyVFGNode *copyNode = SVFUtil::dyn_cast<CopyVFGNode>(stmtNode)) {
                    if (isInitialized(srcPagNode, fact))
                        fact.erase(dstPagNode);
                    else
                        fact.insert(dstPagNode);
                }
                    // Gep: same as Copy
                else if (const GepVFGNode *copyNode = SVFUtil::dyn_cast<GepVFGNode>(stmtNode)) {
                    if (isInitialized(srcPagNode, fact))
                        fact.erase(dstPagNode);
                    else
                        fact.insert(dstPagNode);
                }
                    // Store：dstNode->obj depends on srcNode
                else if (const StoreVFGNode *storeNode = SVFUtil::dyn_cast<StoreVFGNode>(stmtNode)) {
                    PointsTo &PTset = SIFDS::getPts(dstPagNode->getId());
                    if (isInitialized(srcPagNode, fact)) {
                        for (PointsTo::iterator it = PTset.begin(), eit = PTset.end(); it != eit; ++it) {
                            PAGNode *node = getPAG()->getPAGNode(*it);
                            fact.erase(node);
                        }
                    } else {
                        for (PointsTo::iterator it = PTset.begin(), eit = PTset.end(); it != eit; ++it) {
                            PAGNode *node = getPAG()->getPAGNode(*it);
                            fact.insert(node);
                        }
                    }
                }
                    // Load：Load: dstNode depends on scrNode->obj
                    // if all obj are initialized, dstPagNode is initialized, otherwise dstPagNode is Unini
                else if (const LoadVFGNode *loadNode = SVFUtil::dyn_cast<LoadVFGNode>(stmtNode)) {
                    PointsTo PTset = SIFDS::getPts(srcPagNode->getId());
                    u32_t sum = 0;
                    for (PointsTo::iterator it = PTset.begin(), eit = PTset.end(); it != eit; ++it) {
                        PAGNode *node = getPAG()->getPAGNode(*it);
                        sum += isInitialized(node, fact);
                    }
                    if (sum == PTset.count())
                        fact.erase(dstPagNode);
                    else
                        fact.insert(dstPagNode);
                }
            }
                //Compare:
            else if (const CmpVFGNode *cmpNode = SVFUtil::dyn_cast<CmpVFGNode>(node)){
                const PAGNode *resCmpNode = cmpNode->getRes();
                u32_t sum = 0;
                for(CmpVFGNode::OPVers::const_iterator it = cmpNode->opVerBegin(), eit = cmpNode->opVerEnd(); it != eit; ++it){
                    const PAGNode *opNode = it->second;
                    sum += isInitialized(opNode, fact);
                }
                if (sum == cmpNode->getOpVerNum())
                    fact.erase(resCmpNode);
                else
                    fact.insert(resCmpNode);
            }
                //BinaryOp:
            else if (const BinaryOPVFGNode *biOpNode = SVFUtil::dyn_cast<BinaryOPVFGNode>(node)){
                const PAGNode *resBiOpNode = biOpNode->getRes();
                u32_t sum = 0;
                for(BinaryOPVFGNode::OPVers::const_iterator it = biOpNode->opVerBegin(), eit = biOpNode->opVerEnd(); it != eit; ++it){
                    const PAGNode *opNode = it->second;
                    sum += isInitialized(opNode, fact);
                }
                if (sum == biOpNode->getOpVerNum())
                    fact.erase(resBiOpNode);
                else
                    fact.insert(resBiOpNode);
            }
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
//    Facts facts = {};
//    facts.insert(fact);
//    cout << "PAGNode ID: {";
//    printFacts(facts);
//    cout << "}\n";
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
                fact.insert(node);
        }
    }
    return fact;
}
void SIFDS::printRes() {
    std::cout << "\n******* Possibly Uninitialized Variables Problem *******\n\n";
    cout << "Analysis Terminates! Possibly uninitialized variables are: {";
    printFacts(MainExitFacts, true);
    cout << "}\n\n";

    for (ICFGNodeToDataFactsMap::iterator it = ICFGNodeToFacts.begin(), eit = ICFGNodeToFacts.end(); it != eit; ++it) {
        const ICFGNode *node = it->first;
        Facts facts = it->second;
        NodeID id = node->getId();
        std::cout << "ICFGNodeID:" << id << ": PAGNodeSet: {";
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
            if (ObjNodeOnly){
                if (const ObjPN *objNode = SVFUtil::dyn_cast<ObjPN>(*dit))
                    finalFact.insert(*dit);
            }
            else
                finalFact.insert(*dit);
        }
    }
    if (finalFact.size() > 1){
        for (Datafact::iterator dit = finalFact.begin(), edit = --finalFact.end(); dit != edit; ++dit)
            std::cout << (*dit)->getId() << " ";
        std::cout << (*finalFact.rbegin())->getId();   //print last element without " "
    }
    else if (finalFact.size() == 1)
        std::cout << (*finalFact.begin())->getId();
}

void SIFDS::printPathEdgeList() {
    std::cout << "\n*********** PathEdge **************\n";
    for (PathEdgeSet::const_iterator it = PathEdgeList.begin(), eit = PathEdgeList.end(); it != eit; ++it){
        NodeID srcID = (*it)->getSrcPathNode()->getICFGNode()->getId();
        NodeID dstID = (*it)->getDstPathNode()->getICFGNode()->getId();
        Datafact srcFact = (*it)->getSrcPathNode()->getDataFact();
        Datafact dstFact = (*it)->getDstPathNode()->getDataFact();

        cout << "[ICFGNodeID:" << srcID << ",(";
        for (Datafact::const_iterator it = srcFact.begin(), eit = srcFact.end(); it != eit; it++){
            std::cout << (*it)->getId() << " ";
        }
        if (!srcFact.empty())
            cout << "\b";
        cout << ")] --> [ICFGNodeID:" << dstID << ",(";
        for (Datafact::const_iterator it = dstFact.begin(), eit = dstFact.end(); it != eit; it++){
            std::cout << (*it)->getId() << " ";
        }
        if (!dstFact.empty())
            cout << "\b";
        cout << ")]\n";
    }
}
void SIFDS::printSummaryEdgeList() {
    std::cout << "\n*********** SummaryEdge **************\n";
    for (PathEdgeSet::const_iterator it = SummaryEdgeList.begin(), eit = SummaryEdgeList.end(); it != eit; ++it){
        NodeID srcID = (*it)->getSrcPathNode()->getICFGNode()->getId();
        NodeID dstID = (*it)->getDstPathNode()->getICFGNode()->getId();
        Datafact srcFact = (*it)->getSrcPathNode()->getDataFact();
        Datafact dstFact = (*it)->getDstPathNode()->getDataFact();

        cout << "[ICFGNodeID:" << srcID << ",(";
        for (Datafact::const_iterator it = srcFact.begin(), eit = srcFact.end(); it != eit; it++){
            std::cout << (*it)->getId() << " ";
        }
        if (!srcFact.empty())
            cout << "\b";
        cout << ")] --> [ICFGNodeID:" << dstID << ",(";
        for (Datafact::const_iterator it = dstFact.begin(), eit = dstFact.end(); it != eit; it++){
            std::cout << (*it)->getId() << " ";
        }
        if (!dstFact.empty())
            cout << "\b";
        cout << ")]\n";
    }
}
void SIFDS::validateTests(const char *fun) {
    for (u32_t i = 0; i < icfg->getPAG()->getModule().getModuleNum(); ++i) {
        Module *module = icfg->getPAG()->getModule().getModule(i);
        if (Function *checkFun = module->getFunction(fun)) {
            for (Value::user_iterator i = checkFun->user_begin(), e =
                    checkFun->user_end(); i != e; ++i)
                if (SVFUtil::isa<CallInst>(*i) || SVFUtil::isa<InvokeInst>(*i)) {
                    CallSite cs(*i);
                    assert(cs.getNumArgOperands() == 1 && "arguments should one pointer!!");
                    Value *v1 = cs.getArgOperand(0);
                    NodeID ptr = icfg->getPAG()->getValueNode(v1);
                    PointsTo &pts = pta->getPts(ptr);
                    for (PointsTo::iterator it = pts.begin(), eit = pts.end(); it != eit; ++it) {
                        const PAGNode *objNode = icfg->getPAG()->getPAGNode(*it);
                        NodeID objNodeId = objNode->getId();
                        const CallBlockNode *callnode = icfg->getCallICFGNode(cs);
                        const Facts &facts = ICFGNodeToFacts[callnode];

                        bool initialize = true;
                        for (Facts::const_iterator fit = facts.begin(), efit = facts.end(); fit != efit; ++fit) {
                            const Datafact &fact = (*fit);
                            if (fact.count(objNode))
                                initialize = false;
                        }
                        if (strcmp(fun, "checkInit") == 0) {
                            if (initialize)
                                std::cout << sucMsg("SUCCESS: ") << fun << " check <CFGId:" << callnode->getId()
                                          << ", objId:" << objNodeId << "> at ("
                                          << getSourceLoc(*i) << ")\n";
                            else
                                std::cout << errMsg("FAIL: ") << fun << " check <CFGId:" << callnode->getId()
                                          << ", objId:" << objNodeId << "> at ("
                                          << getSourceLoc(*i) << ")\n";
                        } else if (strcmp(fun, "checkUninit") == 0) {
                            if (initialize)
                                std::cout << errMsg("FAIL: ") << fun << " check <CFGId:" << callnode->getId()
                                          << ", objId:" << objNodeId << "> at ("
                                          << getSourceLoc(*i) << ")\n";
                            else
                                std::cout << sucMsg("SUCCESS: ") << fun << " check <CFGId:" << callnode->getId()
                                          << ", objId:" << objNodeId << "> at ("
                                          << getSourceLoc(*i) << ")\n";
                        }
                    }
                }
        }
    }
}