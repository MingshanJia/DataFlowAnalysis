//
//  output.cpp
//  CodeJamRotate
//
//  Created by Paul on 3/2/13.
//  Copyright (c) 2013 Paul. All rights reserved.
//

#include "output.h"

void sendOutput(vector< vector<double> >&O)
{
    vector< vector<double> >::iterator outIterA;
    vector<double>::iterator outIterB;
    int i = 1;
    for(outIterA = O.begin(); outIterA != O.end(); outIterA++)
    {
        outIterB = outIterA->end();
        cout << "Case #" << i << ": " << *(outIterB-1) << endl;
        i++;
    }
    
}