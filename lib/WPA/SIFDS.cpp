//
// Created by mingshan on 15/01/19.
//

/*
 * SIFDS.cpp
 *
 */

#include "WPA/SIFDS.h"
#include "Util/ICFGStat.h"
#include "Util/timequick.h"

using namespace std;
using namespace SVFUtil;

//constructor
SIFDS::SIFDS(SVFG *s) : svfg(s){
    pag = getPAG();
    pta = AndersenWaveDiff::createAndersenWaveDiff(pag->getModule());
    svfg->updateCallGraph(pta);

/*    initialize();
    getIFDSStat();
    // start timing
    tq_start(NULL);
    forwardTabulate();
    tq_stop("ForwardTabulate Time:");
    // end timing
    printRes();*/
}

/*initialization
    PathEdgeList = {<ds_1, 0> --> <ds_1,0>, <ds_2, 0> --> <ds_2,0>, ... <ds_n, 0> --> <ds_n,0>}
    WorkList = {<ds_1, 0> --> <ds_1,0>, <ds_2, 0> --> <ds_2,0>, ... <ds_n, 0> --> <ds_n,0>}
    SummaryEdgeList = {}
*/
void SIFDS::initialize() {

    //initialize SVFGNodeToFacts
    for(SVFG::const_iterator it = svfg->begin(), eit = svfg->end(); it != eit; ++it ){
        const SVFGNode *node = it->second;
        if(node->hasOutgoingEdge() || node->hasIncomingEdge()){
            SVFGNodeToFacts[node] = {};
            SummarySVFGNodeToFacts[node] = {};
        }
        //for validate test purpose
        const SVFGEdge::SVFGEdgeSetTy &outEdges = node->getOutEdges();
        for (SVFGEdge::SVFGEdgeSetTy::iterator it = outEdges.begin(), eit = outEdges.end(); it != eit; ++it) {
            if((*it)->isCallDirectVFGEdge()){
                SVFGCallEdges.insert(*it);
            }
            // for reuse optimization
            else if(const RetDirSVFGEdge *retdir = dyn_cast<RetDirSVFGEdge>(*it)){
                NodeIDWithCS key = {node->getId(), retdir->getCallSiteId()};
                putInMap(key, *it);
            }
            else if(const RetIndSVFGEdge *retind = dyn_cast<RetIndSVFGEdge>(*it)){
                NodeIDWithCS key = {node->getId(), retind->getCallSiteId()};
                putInMap(key, *it);
            }
        }
    }

    Datafact emptyfact = {};    // datafact = 0;
    for(SVFG::const_iterator it = svfg->begin(), eit = svfg->end(); it != eit; ++it ){   //iterate SVFGNodes
        const SVFGNode *node = it->second;
        if(const AddrSVFGNode* addrNode = SVFUtil::dyn_cast<AddrSVFGNode>(node)){    // assert(addrNode has no incoming edges)?
            if(addrNode->hasOutgoingEdge()) {

                Datafact datafact = transferFun(addrNode, emptyfact);
                StartPathNode *srcPN = new StartPathNode(addrNode, datafact);
                PathNode *dstPN = new PathNode(addrNode, datafact);
                PathEdge *startPE = new PathEdge(srcPN, dstPN);
                PathEdgeList.push_back(startPE);
                WorkList.push_back(startPE);
                SVFGDstNodeSet.insert(addrNode);

                DFwithCS dc = {datafact, 0};
                SVFGNodeToFacts[addrNode].insert(dc);
            }
        }
    }

    totalVar = PathEdgeList.size();
    SummaryEdgeList = {};

     //creat CSID2SVFGEdgesMap
    for (SVFGEdge::SVFGEdgeSetTy::iterator it = SVFGCallEdges.begin(), eit = SVFGCallEdges.end(); it != eit; ++it) {
        const CallDirSVFGEdge *calldir = dyn_cast<CallDirSVFGEdge>(*it);
        CallSiteID cs = calldir->getCallSiteId();
        SVFGEdge::SVFGEdgeSetTy edgeList;
        if (CSID2SVFGEdgesMap.find(cs) == CSID2SVFGEdgesMap.end()){
            edgeList.insert(*it);
            CSID2SVFGEdgesMap[cs] = edgeList;
        }else{
            edgeList = CSID2SVFGEdgesMap[cs];
            edgeList.insert(*it);
            CSID2SVFGEdgesMap[cs] = edgeList;
        }
    }

    printPTset(9);
    printPTset(11);
}

void SIFDS::putInMap(NodeIDWithCS key, SVFGEdge *e){
    SVFGEdge::SVFGEdgeSetTy edgeList;
    if (SVFGNodeWithCS2SVFGRetEdgesMap.find(key) == SVFGNodeWithCS2SVFGRetEdgesMap.end()){
        edgeList.insert(e);
        SVFGNodeWithCS2SVFGRetEdgesMap[key] = edgeList;
    }else{
        edgeList = SVFGNodeWithCS2SVFGRetEdgesMap[key];
        edgeList.insert(e);
        SVFGNodeWithCS2SVFGRetEdgesMap[key] = edgeList;
    }
}

void SIFDS::forwardTabulate() {
    while (!WorkList.empty()) {
        PathEdge *e = WorkList.back();
        WorkList.pop_back();
        StartPathNode *srcPN = e->getSrcPathNode();
        //const SVFGNode *sa = srcPN->getSVFGNode();
        //Datafact& d1 = srcPN->getDataFact();
        PathNode *dstPN = e->getDstPathNode();
        const SVFGNode *n = e->getDstPathNode()->getSVFGNode();
        Datafact& d2 = dstPN->getDataFact();

        if(!d2.empty()){      // empty means unknown
            if (n->hasOutgoingEdge()){
                const SVFGEdge::SVFGEdgeSetTy &outEdges = n->getOutEdges();
                for (SVFGEdge::SVFGEdgeSetTy::iterator it = outEdges.begin(), eit =
                        outEdges.end(); it != eit; ++it) {

                    const SVFGNode *succ = (*it)->getDstNode();

                    // direct edges
                    if(const DirectSVFGEdge *dirEdge = dyn_cast<DirectSVFGEdge>(*it)){
                        Datafact d = transferFun(succ, d2);

                        if(const CallDirSVFGEdge *calldir = dyn_cast<CallDirSVFGEdge>(*it)){
                            CallSiteID cs = calldir->getCallSiteId();
                            StartPathNode *newSrcPN = new StartPathNode(succ, d, cs, srcPN);

                            SubSummaryEdgeList = isInSummaryEdgeListForDir(succ, d);
                            checkAndUseSummaryEdge(cs, newSrcPN, succ, d);   //think carefully...
                        }
                        else if (const RetDirSVFGEdge *retdir = dyn_cast<RetDirSVFGEdge>(*it)){
                            if(retdir->getCallSiteId() == srcPN->getCallSiteID()){
                                SEPropagate(e);
                                PEPropagate(srcPN->getUpperLvlStartPN(), succ, d);
                            }
                        }else
                            propagate(srcPN, succ, d);
                    }

                    // indirect edges
                    else if (const IndirectSVFGEdge *indEdge = dyn_cast<IndirectSVFGEdge>(*it)){
                        const PointsTo PTset = indEdge->getPointsTo();
                        Datafact d_filter = FilterDatafact(d2, PTset);
                        Datafact d_after = transferFun(succ, d_filter);

                        if (const CallIndSVFGEdge *callInd = dyn_cast<CallIndSVFGEdge>(*it)){
                            CallSiteID cs = callInd->getCallSiteId();
                            StartPathNode *newSrcPN = new StartPathNode(succ, d_after, cs, srcPN);

                            SubSummaryEdgeList = isInSummaryEdgeListForIndir(succ, d_after);
                            checkAndUseSummaryEdge(cs, newSrcPN, succ, d_after);
                        }
                        else if(const RetIndSVFGEdge *retind = dyn_cast<RetIndSVFGEdge>(*it)){
                            if(retind->getCallSiteId() == srcPN->getCallSiteID()){
                                SEPropagate(e);
                                PEPropagate(srcPN->getUpperLvlStartPN(), succ, d_after);     //caculate d_after in if?
                            }
                        }
                        else  // other indirect edges
                            propagate(srcPN, succ, d_after);
                    }
                }
            }
        }
    }
}

//add new PathEdge into PathEdgeList and WorkList
void SIFDS::propagate(StartPathNode *srcPN, const SVFGNode *succ, Datafact& d) {
    if (SVFGDstNodeSet.find(succ) == SVFGDstNodeSet.end()) {
        PEPropagate(srcPN, succ, d);
    }
    else {
        DFwithCS dc = {d, srcPN->getCallSiteID()};
        if (SVFGNodeToFacts[succ].find(dc) == SVFGNodeToFacts[succ].end()) {
            PEPropagate(srcPN, succ, d);
        }
    }
}

void SIFDS:: PEPropagate(StartPathNode *srcPN, const SVFGNode *succ, Datafact& d){
    PathNode *newDstPN = new PathNode(succ, d);
    PathEdge *e = new PathEdge(srcPN, newDstPN);
    WorkList.push_back(e);
    PathEdgeList.push_back(e);
    SVFGDstNodeSet.insert(succ);
    DFwithCS dc = {d, srcPN->getCallSiteID()};
    SVFGNodeToFacts[succ].insert(dc);
}

void SIFDS::SEPropagate(PathEdge *e){
    if(std::find(SummaryEdgeList.begin(), SummaryEdgeList.end(), e) == SummaryEdgeList.end())
        SummaryEdgeList.push_back(e);
}

SIFDS::PathEdgeSet SIFDS::isInSummaryEdgeListForDir(const SVFGNode *node, Datafact& d){
    PathEdgeSet SEset = {};
    for (PathEdgeSet::const_iterator it = SummaryEdgeList.begin(), eit = SummaryEdgeList.end(); it != eit; ++it){
        const SVFGNode *srcNode = (*it)->getSrcPathNode()->getSVFGNode();
        Datafact srcFact = (*it)->getSrcPathNode()->getDataFact();
        if(node->getId() == srcNode->getId() && d == srcFact)
            SEset.push_back(*it);
    }
    return SEset;   // Summary edges in the set should have same csId
}

SIFDS::PathEdgeSet SIFDS::isInSummaryEdgeListForIndir(const SVFGNode *node, Datafact& d){   //FIXME:see example: easyptr3 callInd
    PathEdgeSet SEset = {};
    for (PathEdgeSet::const_iterator it = SummaryEdgeList.begin(), eit = SummaryEdgeList.end(); it != eit; ++it){
        const SVFGNode *srcNode = (*it)->getSrcPathNode()->getSVFGNode();
        Datafact srcFact = (*it)->getSrcPathNode()->getDataFact();
        /*handle call of indirEdge   ???*/
        u32_t d_sum = 0;
        u32_t srcFact_sum = 0;
        for (Datafact::iterator it = d.begin(), eit = d.end(); it != eit; ++it)
            d_sum += it->second;
        for (Datafact::iterator it = srcFact.begin(), eit = srcFact.end(); it != eit; ++it)
            srcFact_sum += it->second;
        /*handle call of indirEdge*/
        if(node->getId() == srcNode->getId() && d_sum == srcFact_sum)
            SEset.push_back(*it) ;
    }
    return SEset;   // Summary edges in the set should have same csId
}

// use summaryEdge to speed up
void SIFDS::checkAndUseSummaryEdge(CallSiteID cs, StartPathNode *srcPN, const SVFGNode* succ, Datafact &d){
    //test info: summary edge reuse info
    //std::cout << "SVFGNode:"<<succ->getId()<< "|" << srcPN->getUpperLvlStartPN()->getSVFGNode()->getId() <<", CallSite: " << cs << ", Use SummaryEdge? " << !SubSummaryEdgeList.empty() << endl;
    if(!SubSummaryEdgeList.empty()){
        for (PathEdgeSet::const_iterator it = SubSummaryEdgeList.begin(), eit = SubSummaryEdgeList.end(); it != eit; ++it){
            const SVFGNode *SEdstNode = (*it)->getDstPathNode()->getSVFGNode();
            Datafact d = (*it)->getDstPathNode()->getDataFact();

            goViaSummaryEdge(SEdstNode, d, srcPN, cs);
        }
    } else
        propagate(srcPN, succ, d);  //subEdgeBegining
}

void SIFDS::goViaSummaryEdge(const SVFGNode *SEdstNode, Datafact& d, StartPathNode* srcPN, CallSiteID cs){
    //const SVFGEdge::SVFGEdgeSetTy &outEdges = SEdstNode->getOutEdges();
    NodeIDWithCS key = {SEdstNode->getId(), cs};
    const SVFGEdge::SVFGEdgeSetTy &outEdges = SVFGNodeWithCS2SVFGRetEdgesMap[key];
    for (SVFGEdge::SVFGEdgeSetTy::iterator it = outEdges.begin(), eit = outEdges.end(); it != eit; ++it){
        const SVFGNode *succ = (*it)->getDstNode();

        if (const RetDirSVFGEdge *retdir = dyn_cast<RetDirSVFGEdge>(*it)) {
            Datafact d_after = transferFun(succ, d);
            propagate(srcPN->getUpperLvlStartPN(), succ, d_after);
        }
        else if(const RetIndSVFGEdge *retind = dyn_cast<RetIndSVFGEdge>(*it)) {
            const PointsTo PTset = retind->getPointsTo();
            Datafact d_filter = FilterDatafact(d, PTset);
            Datafact d_after = transferFun(succ, d_filter);
            propagate(srcPN->getUpperLvlStartPN(), succ, d_after);
        }
    }
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

        if (SVFUtil::isa<AddrSVFGNode>(stmtNode)){
            fact.insert({dstPagNode, false});
        }
        // DummyStore: dstNode's points-to set is uninitialized, dstNode is initialiazed
        else if (SVFUtil::isa<DummyStoreSVFGNode>(stmtNode)) {
            fact = {};
            PointsTo &PTset = SIFDS::getPts(dstPagNode->getId());
            for (PointsTo::iterator it = PTset.begin(), eit = PTset.end(); it != eit; ++it) {
                PAGNode *node = pag->getPAGNode(*it);
                fact.insert({node,true});
            }
        }
        // Copy/Gep: dstNode depends on srcNode
        else if (SVFUtil::isa<CopySVFGNode>(stmtNode) || SVFUtil::isa<GepSVFGNode>(stmtNode)) {
            if (isInitialized(srcPagNode, fact)){
                fact = {};
                fact.insert({dstPagNode,false});
            }
            else if (isUninitialized(srcPagNode, fact)){
                fact = {};
                fact.insert({dstPagNode,true});
            }
            else if (isUnknown(srcPagNode, fact))
                fact = {};
        }
        // Store：dstNode->obj depends on srcNode
        else if (SVFUtil::isa<StoreSVFGNode>(stmtNode)) {
            PointsTo &PTset = SIFDS::getPts(dstPagNode->getId());
            if (isInitialized(srcPagNode, fact)) {
                fact = {};
                for (PointsTo::iterator it = PTset.begin(), eit = PTset.end(); it != eit; ++it) {
                    PAGNode *node = pag->getPAGNode(*it);
                    fact.insert({node,false});
                }
            } else if (isUninitialized(srcPagNode, fact)) {
                fact = {};
                for (PointsTo::iterator it = PTset.begin(), eit = PTset.end(); it != eit; ++it) {
                    PAGNode *node = pag->getPAGNode(*it);
                    fact.insert({node,true});
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
                PAGNode *node = pag->getPAGNode(*it);
                sum_ini += isInitialized(node, fact);
                sum_unknown += isUnknown(node, fact);
                sum_unini += isUninitialized(node, fact);
            }
            if(sum_unknown == PTset.count())
                fact = {};
            else if (sum_ini + sum_unknown == PTset.count()){
                fact = {};
                fact.insert({dstPagNode,false});
            }
            else{
                fact = {};
                fact.insert({dstPagNode,true});
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
        }
        else if (isInitialized(OpOne, fact) || isInitialized(OpTwo, fact)){
            fact = {};
            fact.insert({resBiOpNode,false});
        }
    }
    else if (const InterPHISVFGNode *interPhi = SVFUtil::dyn_cast<InterPHISVFGNode>(svfgNode)) {
        const PAGNode *dstPagNode = interPhi->getRes();
        u32_t sum_ini = 0;
        u32_t sum_unini = 0;
        for(PHISVFGNode::OPVers::const_iterator it = interPhi->opVerBegin(), eit = interPhi->opVerEnd(); it != eit; ++it){
            sum_ini += isInitialized(it->second, fact);
            sum_unini += isUninitialized(it->second, fact);
        }
        if(sum_unini == 1){    // need to check uninit first(because constantData will be init without execution)
            fact = {};
            fact.insert({dstPagNode,true});
        }
        else if (sum_ini >= 1){   //take consideration of constantData
            fact = {};
            fact.insert({dstPagNode,false});
        }
    }
    return fact;
}

SIFDS::Datafact SIFDS::FilterDatafact(Datafact& d, const PointsTo &PTset){
    Datafact d_filter = d;
    // cannot process in original data structure
    set<int> pts = {};
    for (PointsTo::iterator it = PTset.begin(), eit = PTset.end(); it != eit; ++it) {
        pts.insert(*it);
    }

    for(Datafact::iterator it = d_filter.begin(), eit = d_filter.end(); it != eit; ){
        if(pts.find(it->first->getId()) == pts.end()){
            it = d_filter.erase(it);
        }else
            it++;
    }
    return d_filter;
}

// print ICFGNodes and theirs datafacts
void SIFDS::getIFDSStat() {
    cout << "#######################################################\n\n";
    cout << "Total Variables     " << totalVar << endl;
    std::cout << "-------------------------------------------------------\n";
  cout << "\n";
}

void SIFDS::printRes() {
    std::cout << "\n******* Possibly Uninitialized Variables Problem *******\n\n";
    cout << "Analysis Terminates! Possibly uninitialized variables are: {";
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
        Datafact fact = (*fit).first;
        for (Datafact::iterator dit = fact.begin(), edit = fact.end(); dit != edit; ++dit) {
            if (ObjNodeOnly){
                if (const ObjPN *objNode = SVFUtil::dyn_cast<ObjPN>((*dit).first))
                    finalFact.insert(*dit);
            }
            else
                finalFact.insert(*dit);
        }
    }
    if (finalFact.size() > 1){
        for (Datafact::iterator dit = finalFact.begin(), edit = --finalFact.end(); dit != edit; ++dit)
            std::cout << "<" << (*dit).first->getId() << "," << (*dit).second << "> ";
        //print last element without " "
        std::cout << "<" << (*finalFact.rbegin()).first->getId() << "," << (*finalFact.rbegin()).second << ">";
    }
    else if (finalFact.size() == 1)
        std::cout << "<" << (*finalFact.begin()).first->getId() << "," << (*finalFact.begin()).second << ">";
}

void SIFDS::printPathEdgeList() {
    std::cout << "\n*********** PathEdge **************\n";
    for (PathEdgeSet::const_iterator it = PathEdgeList.begin(), eit = PathEdgeList.end(); it != eit; ++it){
        NodeID srcID = (*it)->getSrcPathNode()->getSVFGNode()->getId();
        NodeID upperlvlSrcID = 0;
        if ((*it)->getSrcPathNode()->getUpperLvlStartPN())
            upperlvlSrcID = (*it)->getSrcPathNode()->getUpperLvlStartPN()->getSVFGNode()->getId();

        NodeID dstID = (*it)->getDstPathNode()->getSVFGNode()->getId();
        Datafact srcFact = (*it)->getSrcPathNode()->getDataFact();
        Datafact dstFact = (*it)->getDstPathNode()->getDataFact();

        cout << "[SVFGNodeID:" << srcID << "|" << upperlvlSrcID << ",(";
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
        NodeID upperlvlSrcID = 0;
        if ((*it)->getSrcPathNode()->getUpperLvlStartPN())
            upperlvlSrcID = (*it)->getSrcPathNode()->getUpperLvlStartPN()->getSVFGNode()->getId();
        NodeID dstID = (*it)->getDstPathNode()->getSVFGNode()->getId();
        Datafact srcFact = (*it)->getSrcPathNode()->getDataFact();
        Datafact dstFact = (*it)->getDstPathNode()->getDataFact();
        int cs = (*it)->getSrcPathNode()->getCallSiteID();

        cout << "[SVFGNodeID:" << srcID << "|" << upperlvlSrcID << "@" << cs << ",(";
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
void SIFDS::validateTests(const char *fun) {

    for (u32_t i = 0; i < pag->getModule().getModuleNum(); ++i) {
        Module *module = pag->getModule().getModule(i);
        PTACallGraph cg = PTACallGraph(module); // get call graph
        if (Function *checkFun = module->getFunction(fun)) {
            for (Value::user_iterator i = checkFun->user_begin(), e =
                    checkFun->user_end(); i != e; ++i)
                if (SVFUtil::isa<CallInst>(*i) || SVFUtil::isa<InvokeInst>(*i)) {
                    CallSite cs(*i);
                    assert(cs.getNumArgOperands() == 1 && "arguments should one pointer!!");
                    Value *v1 = cs.getArgOperand(0);

                    CallSiteID csId = cg.getCallSiteID(cs, checkFun); // get call site id for check fun
                    assert(CSID2SVFGEdgesMap[csId].size() == 1);

                    SVFGNode *targetNode = (*(CSID2SVFGEdgesMap[csId].begin()))->getSrcNode();
                    const Facts &facts = SVFGNodeToFacts[targetNode];

                    Datafact finalFact = {};
                    for (Facts::iterator fit = facts.begin(), efit = facts.end(); fit != efit; ++fit) {
                        Datafact fact = (*fit).first;
                        for (Datafact::iterator dit = fact.begin(), edit = fact.end(); dit != edit; ++dit) {
                            finalFact.insert(*dit);
                        }
                    }

                    PAGNode *node;
                    if (const StmtSVFGNode *stmtNode = SVFUtil::dyn_cast<StmtSVFGNode>(targetNode)) {
                        PAGNode *srcPagNode = stmtNode->getPAGSrcNode();
                        PointsTo &PTset = SIFDS::getPts(srcPagNode->getId());
                        node = pag->getPAGNode(*PTset.begin());  //PTset.size() == 1
                    }

                    if (finalFact.size()){
                        bool initialize = true;
                        int sum_fact = 0;
                        for (Datafact::iterator dit = finalFact.begin(), edit = finalFact.end(); dit != edit; ++dit)
                            sum_fact += (*dit).second;
                        if(sum_fact)  // {ex: <35, 0>, <35, 1> means unini}
                            initialize = false;

                        if (strcmp(fun, "checkInit") == 0) {
                            if (initialize)
                                std::cout << sucMsg("SUCCESS: ") << fun << " check [SVFGId:" << targetNode->getId() << "]  for variable:" << node->getValueName()
                                          << " at ("<< getSourceLoc(*i) << ")\n";
                            else
                                std::cout << errMsg("FAIL: ") << fun << " check [SVFGId:" << targetNode->getId() << "]  for variable:" << node->getValueName()
                                          << " at ("<< getSourceLoc(*i) << ")\n";

                        } else if (strcmp(fun, "checkUninit") == 0) {
                            if (initialize)
                                std::cout << errMsg("FAIL: ") << fun << " check [SVFGId:" << targetNode->getId() << "]  for variable:" << node->getValueName()
                                          << " at ("<< getSourceLoc(*i) << ")\n";
                            else
                                std::cout << sucMsg("SUCCESS: ") << fun << " check [SVFGId:" << targetNode->getId() << "]  for variable:" << node->getValueName()
                                          << " at ("<< getSourceLoc(*i) << ")\n";
                        }
                    }
                    else
                        std::cout << errMsg("Unknown: ") << " check [SVFGId:" << targetNode->getId() << "]  for variable:" << node->getValueName()
                                  << " at ("<< getSourceLoc(*i) << ")\n";
                }
        }
    }
}

void SIFDS::printPTset(u32_t id){
    PointsTo &PTset = SIFDS::getPts(id);
    std::cout << "Pts of " << id << ": ";
    for (PointsTo::iterator it = PTset.begin(), eit = PTset.end(); it != eit; ++it) {
        PAGNode *node = pag->getPAGNode(*it);
        std::cout <<node->getId() << ", ";
    }
    std::cout << endl;
}