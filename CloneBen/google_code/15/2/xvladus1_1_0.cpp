#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <math.h>

#include <queue>

using namespace std;
using namespace stdext;
 
const int INCHES = 12;

bool openFileHandles(ifstream& readFile, const string& inFile, ofstream& writeFile, const string& outFile);

int main()
{
	// files
	ifstream readFile;
	ofstream writeFile;
	
	//string fileIn("practice");
	string fileIn("small");
	//string fileIn("large");

	if (!openFileHandles(readFile, fileIn + ".txt", writeFile, fileIn + "_out.txt"))
		return -1;

	// read # of lines
	int numCases;
	readFile >> numCases;
	readFile.get();  // get rid of the newline

	// for each test case, ...
	for (int i = 0; i < numCases; ++i)
	{
		char c;
		int momFt, momIn;
		int dadFt, dadIn;

		char dummy;
		readFile >> c >> momFt >> dummy >> momIn >> dummy >> dadFt >> dummy >> dadIn >> dummy;
		readFile.get();

		int parentsHeight = INCHES*(momFt + dadFt) + (momIn + dadIn);  // in inches

		float childHeight = (c == 'B') ? parentsHeight + 5
			: parentsHeight - 5;
		childHeight /= 2;

		float delta = (childHeight - (int)childHeight);
		
		// min height
		float min = childHeight - 4;
		if (delta > 0)
			min += delta;			

		int minFt = min/INCHES;
		float minIn = min - INCHES*minFt;

		// max height
		float max = childHeight + 4;
		if (delta > 0)
			max -= delta;

		int maxFt = max/INCHES;
		float maxIn = max - INCHES*maxFt;

		//  "Case #x: y" -- x is case #, y is the height of bush number N - 1 
		//cout << "Case #" << i+1 << ": " << minFt << "'" << minIn << "\" to " << maxFt << "'" << maxIn << "\"" << endl;
		writeFile << "Case #" << i+1 << ": " << minFt << "'" << minIn << "\" to " << maxFt << "'" << maxIn << "\"" << endl;
	}  // for (n)

	// close file handles
	readFile.close();
	writeFile.close();

	// no error
	return 0;
}

bool openFileHandles(ifstream& readFile, const string& inFile, ofstream& writeFile, const string& outFile)
{
	// input file
	readFile.open(inFile.c_str());
	if (!readFile)
	{
		cout << "Could not find '" << inFile << "'\n\n";
		return false;
	}

	// output file
	writeFile.open(outFile.c_str());
	if (!writeFile)
	{
		cout << "Could not find '" << outFile << "'\n\n";
		return false;
	}

	return true;
}
