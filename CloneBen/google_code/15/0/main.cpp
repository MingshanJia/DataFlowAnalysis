//
//  main.cpp
//  CodeJamRotate
//
//  Created by Paul on 3/2/13.
//  Copyright (c) 2013 Paul. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "input.h"
#include "output.h"

int main(int argc, char * argv[])
{
    int T;
    vector<int> N;
    vector< vector<double> > D;
    vector< vector<double> > O;
    vector< vector<double> >::iterator outIterA;
    vector<double>::iterator outIterB;
    vector<double>::iterator b;
    double dTemp;
    
    
    getInput(argc, argv, T, N, D);
    
    for (vector< vector<double> >::iterator a = D.begin(); a != D.end(); a++)
    {
        
        b = a->begin();
        vector<double> vec;
        for (vector<double>::iterator b = (a->begin()+1); b != (a->end()-1); b++)
        {
            dTemp = (*(b-1) + *(b+1))/2.00;
            
            if(*b >= dTemp) *b = dTemp;
            cout << *b << " ";
            vec.push_back(*b);
        }
        cout << endl;
        
        O.push_back(vec);
    }
    
    cout << endl;
    
    sendOutput(O);
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

