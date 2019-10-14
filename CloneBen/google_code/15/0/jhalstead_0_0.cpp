#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream infile("A-small-attempt1.in");
    ofstream outfile("A-small-attempt1.out");
    double * hedges = NULL;
    int SIZE = 0, numCases = 0;
    string line = "";

    // Grab number of test cases
    getline(infile, line);
    stringstream temp(line);
    temp >> numCases;

    // Process all test cases
    for(int i = 0; getline( infile, line ); i++)
    {
        stringstream ss(line);

        if (i % 2 == 0)
        {
            ss >> SIZE;
            hedges = new double[SIZE];
        }
        else
        {
            double hedgeHeight;
            for(int j = 0; ss >> hedgeHeight; j++)
                hedges[j] = hedgeHeight;

            for (int j = 1; j < SIZE-1; j++)
            {
                if (hedges[j] > (hedges[j-1] + hedges[j+1]) / 2.0)
                    hedges[j] = (hedges[j-1] + hedges[j+1]) / 2.0;
            }

            stringstream outstr;
            outstr << "Case #" << (i/2)+1 << ": " << fixed << setprecision (6) << hedges[SIZE - 2] << endl;
            outfile << outstr.str();

            delete [] hedges;
            hedges = NULL;
        }
    }

    if (hedges != NULL)
        delete [] hedges;

    infile.close();
    outfile.close();
    return 0;
}

