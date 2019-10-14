//
//  output.cpp
//  CodeJamRotate
//
//  Created by Paul on 3/2/13.
//  Copyright (c) 2013 Paul. All rights reserved.
//

#include "output.h"

void sendOutput(vector<string>&O)
{
    int i = 1;
    for(vector<string>::iterator a = O.begin(); a != O.end(); a++)
    {
        cout << "Case #" << i << ": " << *a << endl;
        i++;
    }
    
}