
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
//#include <vector>
//#include <algorithm>

using namespace std;

int main(int argc, char *argv[]){
	char gender,marker;
	int tests,f_ft,f_in,m_ft,m_in,h,h_offset,h_min_ft,h_min_in,h_max_ft,h_max_in;
	
	//setup the input file
	string dirName = "input/";
	stringstream ss;
	ss << dirName << "B-small-attempt2.in";
	puts(ss.str().c_str());
	ifstream inputFile;
	inputFile.open(ss.str().c_str());
	
	//setup the output file
	dirName = "results/";
	ss.str("");
	ss.clear();
	ss << dirName << "B-small-attempt2.out";
	puts(ss.str().c_str());
	ofstream outputFile;
	outputFile.open(ss.str().c_str());
	
	//read input file
	inputFile >> tests;
  cout << "Number of tests: " << tests << endl;
  for(int t = 0; t<tests; t++) {
		inputFile >> gender;
		
		inputFile >> m_ft;
		inputFile >> marker;
		inputFile >> m_in;
		inputFile >> marker;
		m_in += m_ft*12;
		
		inputFile >> f_ft;
		inputFile >> marker;
		inputFile >> f_in;
		inputFile >> marker;
		f_in += f_ft*12;
		
		//add parents' heights
		h = m_in + f_in;
		if(gender =='B')
			h += 5;
		else
			h -= 5;
		h_offset = h%2;
		h = h/2;
		h_min_ft = (h-4 + h_offset)/12;
		h_min_in = (h-4 + h_offset)%12;
		h_max_ft = (h+4)/12;
		h_max_in = (h+4)%12;
  	cout << "Case #" << t+1 << ": " << h_min_ft << "\'" << h_min_in << "\" to " << h_max_ft << "\'" << h_max_in << "\"" << endl;
  	outputFile << "Case #" << t+1 << ": " << h_min_ft << "\'" << h_min_in << "\" to " << h_max_ft << "\'" << h_max_in << "\"" << endl;
  }
	
	
	//close the files
	outputFile.close();
	inputFile.close();
	
	return 0;
}
