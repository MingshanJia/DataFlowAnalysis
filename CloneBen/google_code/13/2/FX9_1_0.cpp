#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;


bool do_case(ifstream &fin,ofstream &fout,int casenum){
	double V,D,pi=asin(1.0)*2;
	fin>>V>>D;
	fout.precision(10);
	fout<<"Case #"<<casenum<<": "<<asin(min(1.0,9.8*D/V/V))/2/2/pi*360<<endl;
					return true;
}


int main(){
	ifstream fin("B-small-attempt0.in");
	ofstream fout("output.txt");
	int n;
	fin>>n;
	for(int i=0;i<n;i++){
		do_case(fin,fout,i+1);
	}
	fin.close();
	fout.close();
	return 0;
}
