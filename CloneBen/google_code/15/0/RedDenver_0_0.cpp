
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]){
	int tests,n;
	long double v;
	vector<long double> hedge;
	
	//setup the input file
	string dirName = "input/";
	stringstream ss;
	ss << dirName << "A-small-attempt0.in";
	puts(ss.str().c_str());
	ifstream inputFile;
	inputFile.open(ss.str().c_str());
	
	//setup the output file
	dirName = "results/";
	ss.str("");
	ss.clear();
	ss << dirName << "A-small-attempt0.out";
	puts(ss.str().c_str());
	ofstream outputFile;
	outputFile.open(ss.str().c_str());
	
	//read input file
	inputFile >> tests;
  cout << "Number of tests: " << tests << endl;
  for(int t = 0; t<tests; t++) {
		inputFile >> n;
		hedge.clear();
  	for(int i=0; i<n; i++){
  		inputFile >> v;
  		hedge.push_back(v);
  	}
  	for(int i=1; i<n-1; i++){
  		v = (hedge[i-1]+hedge[i+1])/2.0;
  		if(v < hedge[i])
  			hedge[i]=v;
  	}
  	
  	cout << "Case #" << t+1 << ": " << hedge[n-2] << endl;
  	outputFile << "Case #" << t+1 << ": " << hedge[n-2] << endl;
  }
	
	
	//close the files
	outputFile.close();
	inputFile.close();
	
	return 0;
}
