#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include <queue>

using namespace std;
using namespace stdext;

bool openFileHandles(ifstream& readFile, const string& inFile, ofstream& writeFile, const string& outFile);

int main()
{
	// files
	ifstream readFile;
	ofstream writeFile;
	
	//string fileIn("practice");
	//string fileIn("small");
	string fileIn("large");

	if (!openFileHandles(readFile, fileIn + ".txt", writeFile, fileIn + "_out.txt"))
		return -1;

	// read # of lines
	int numCases;
	readFile >> numCases;
	readFile.get();  // get rid of the newline

	// for each test case, ...
	for (int i = 0; i < numCases; ++i)
	{
		// read N
		int N;
		readFile >> N;
		readFile.get();  // get rid of the newline

		vector<float> arr(N);
		for (int n = 0; n < N; ++n)
			readFile >> arr[n];
		readFile.get();  // get rid of the newline
		
		// now look through all the hedges
		for (int n = 1; n < N - 1; ++n)
		{
			const float avg = (arr[n-1] + arr[n+1])/2.0;
			if (arr[n] > avg)
				arr[n] = avg;
		}

		//  "Case #x: y" -- x is case #, y is the height of bush number N - 1 
		cout << "Case #" << i+1 << ": " << arr[N-2] << endl;
		writeFile << "Case #" << i+1 << ": " << arr[N-2] << endl;
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
