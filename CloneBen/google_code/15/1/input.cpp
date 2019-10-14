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

void getInput(int argc, char **argv, int &T, vector<int> &N, vector< vector<double> > &D)
{
    ifstream inFile;
    ofstream outFile;
    string line;
    stringstream ss;
    int temp;
    double dtemp;
    
    cout << argv[1] << endl;
    inFile.open(argv[1]);
    if(!inFile.is_open())
    {
        printf("Input file is invalid\n");
        exit(1);
    }
    
    
    //getline gets the whole line from the file
    // ss >> T takes the first element from that line
    getline(inFile, line);
    cout << line << endl;
    ss << line;
    ss >> T;
    ss.clear();
    
    while (getline (inFile, line))
    {
        cout << line << endl;
        ss << line;
        ss >> temp;
        ss.clear();
        N.push_back(temp);
        cout << temp << endl;
        vector<double> vec;
        getline(inFile, line);
        cout << line << endl;
        ss << line;
        for (int i = 0; i < N.back() ; i++)
        {
            ss >> dtemp;
            
            vec.push_back(dtemp);
            cout << dtemp;
        }
        cout << endl;
        ss.clear();
        D.push_back(vec);
        
    }
    
    
    
    inFile.close();
    cout << endl << endl << endl;
    /*
    cout << "Cases" << endl;
    cout << T << endl;
    for (vector<int>::iterator a = N.begin(); a != N.end(); a++)
    {
        cout << "Set" << endl;
        cout << *a << endl;
        
        for (vector< vector<double> >::iterator b = D.begin(); b != D.end(); b++)
        {
            for (vector<double>::iterator c = b->begin(); c != b->end(); c++)
            {
                cout << *c;
            }
            cout << endl;
        }
        cout << endl;
    }
    */
    
}