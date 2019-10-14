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
#include <cstdlib>
#include <cmath>
#include <sstream>

int main(int argc, char * argv[])
{
    int T;
    vector<string> G;
    vector< pair<string, string> > H;
    vector< pair<int, int> > inchH;
    vector<string> O;
    vector<string>::iterator genderIter;
    int foot;
    int inch;
    int genderMod;
    long apost;
    stringstream ss;
    //vector< vector<double> >::iterator outIterA;
    //vector<double>::iterator outIterB;
    //vector<double>::iterator b;
    //double dTemp;
    
    
    getInput(argc, argv, T, G, H);
    
    for(vector<pair<string, string> >::iterator a = H.begin(); a != H.end(); a++)
    {
        pair<int, int> iiPair;
        apost = a->first.find_first_of("'");
        foot = atoi(a->first.substr(0,apost).c_str());
        inch = atoi(a->first.substr(apost+1,(a->first.size()-1)).c_str());
        iiPair.first = foot*12 + inch;
        apost = a->second.find_first_of("'");
        foot = atoi(a->second.substr(0,apost).c_str());
        inch = atoi(a->second.substr(apost+1,(a->first.size()-1)).c_str());
        iiPair.second = foot*12 + inch;
        //cout << iiPair.first << " " << iiPair.second << endl;
        inchH.push_back(iiPair);
    }
    
    genderIter = G.begin();
    for(vector<pair<int, int> >::iterator a = inchH.begin(); a != inchH.end(); a++)
    {
        string out;
        double calcHigh;
        double calcLow;
        double intpart;
        double footHigh;
        double footLow;
        double inchHigh;
        double inchLow;
        if (*genderIter == "G") genderMod = -5;
        else if (*genderIter == "B") genderMod = 5;
        else cout << "Error";
        genderIter++;
        calcHigh = (a->first + a->second + genderMod) / 2.0 + 4.0;
        if(modf(calcHigh, &intpart) != 0) calcHigh -= 0.5;
        calcLow = (a->first + a->second + genderMod) / 2.0 - 4.0;
        if(modf(calcLow, &intpart) != 0) calcLow += 0.5;
        
        inchHigh = modf((calcHigh / 12), &footHigh) * 12;
        inchLow = modf((calcLow / 12), &footLow) * 12;
        
        ss << footLow << "\'" << inchLow << "\" to " << footHigh << "\'" << inchHigh << "\"";
        out = ss.str();
        ss.str("");
        //cout << out << endl;
        O.push_back(out);
    }
    cout << endl << endl;
    /*
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
    */
    sendOutput(O);
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

