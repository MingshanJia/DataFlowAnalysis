//
//  input.cpp
//  CodeJamRotate
//
//  Created by Paul on 3/2/13.
//  Copyright (c) 2013 Paul. All rights reserved.
//

#include "input.h"
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

void getInput(int argc, char **argv, int &T, vector<string> &G, vector< pair<string, string> > &H)
{
    ifstream inFile;
    ofstream outFile;
    string line;
    stringstream ss;
    int itemp;
    double dtemp;
    string stemp;
    
    //cout << argv[1] << endl;
    inFile.open(argv[1]);
    if(!inFile.is_open())
    {
        printf("Input file is invalid\n");
        exit(1);
    }
    
    
    //getline gets the whole line from the file
    // ss >> T takes the first element from that line
    getline(inFile, line);
    //cout << line << endl;
    ss << line;
    ss >> T;
    ss.clear();
    
    while (getline (inFile, line))
    {
        //cout << line << endl;
        ss << line;
        ss >> stemp;
        G.push_back(stemp);
        //cout << stemp << " ";
        pair<string, string> p;
        ss >> p.first;
        ss >> p.second;
        //cout << p.first << " "  << p.second << endl;
        ss.clear();
        H.push_back(p);
        
    }
    
    //cout << endl << endl << endl;
    
    inFile.close();
    
}