//
// Created by mingshan on 5/03/19.
//

#ifndef INCLUDE_WPA_SIFDSANALYSIS_H
#define INCLUDE_WPA_SIFDSANALYSIS_H

#include "WPA/Andersen.h"

class SifdsAnalysis:  public Andersen {

public:
    /// Constructor
    SifdsAnalysis(PTATY type = SIFDS_WPA)
            :  Andersen(type){
    }

    /// Destructor
    virtual ~SifdsAnalysis() {
    }

    /// Type analysis
    void analyze(SVFModule svfModule);

    /// Initialize analysis
    void initialize(SVFModule svfModule);

    /// Finalize analysis
    virtual inline void finalize();

    /// Methods for support type inquiry through isa, cast, and dyn_cast:
    //@{
    static inline bool classof(const SifdsAnalysis *) {
        return true;
    }
    static inline bool classof(const PointerAnalysis *pta) {
        return (pta->getAnalysisTy() == SIFDS_WPA);
    }
    //@}

private:
    std::set<CallSite> virtualCallSites;
};
#endif //INCLUDE_WPA_SIFDSANALYSIS_H
