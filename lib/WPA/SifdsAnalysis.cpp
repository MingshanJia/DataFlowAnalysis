//
// Created by mingshan on 4/03/19.
//

#include "WPA/SifdsAnalysis.h"
#include "MemoryModel/CHA.h"
#include "Util/CPPUtil.h"
#include "Util/PTAStat.h"
#include "Util/ICFGStat.h"
#include "Util/VFG.h"
#include "WPA/SIFDS.h"


using namespace SVFUtil;
using namespace cppUtil;
using namespace std;

/// Initialize analysis
void SifdsAnalysis::initialize(SVFModule svfModule) {
    Andersen::initialize(svfModule);
    icfg = new ICFG(ptaCallGraph);
    SIFDS* sifds = new SIFDS(icfg->getSVFG());
    icfg->dump("icfg_initial");
    icfg->getVFG()->dump("vfg_initial");
    icfg->getSVFG()->dump("svfg_initial");
}


void SifdsAnalysis::analyze(SVFModule svfModule){
    initialize(svfModule);
}


