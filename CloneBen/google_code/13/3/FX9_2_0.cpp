#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;


bool do_case(ifstream &fin,ofstream &fout,int casenum){
	int ans=0;
	string maxstr,temp;
	int k;
	fin>>k;
	getline(fin,maxstr);
	getline(fin,maxstr);
	cout<<maxstr<<endl;
	for(int i=1;i<k;i++){
		getline(fin,temp);
		//cout<<temp<<' '<<(maxstr<temp)<<endl;
		if(maxstr<temp){
			maxstr=temp;
		}
		else if(temp<maxstr){
			ans++;
		}
	}
	fout<<"Case #"<<casenum<<": "<<ans<<endl;
					return true;
}


int main(){
	ifstream fin("C-small-1-attempt0.in");
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
