#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>
#include<math.h>

using namespace std;
ifstream in("in");


double calc(int k){
	double r=0;
	int n=9000;
	while(n>0){
		r=r+log10(n);
		n=n-k;
	}
	return r;
}
string write(int i){
	string s="IT'S OVER 9000";
	while(i>0){
			s=s+"!";
			i--;
	}
	return s;
}
int main(){
	
	int casenum=0;
	in>>casenum;
	for (int c=0;c<casenum;c++){
		int d;
		in>>d;
		bool golabi=false;
		for(int i=1;i<9000;i++){
			double result=calc(i);
			if(ceil(result)<d){
				golabi=1;
				cout<<"Case #"<<c+1<<": "<<write(i)<<endl;
				break;
			}
		}
		if(!golabi)
			cout<<"Case #"<<c+1<<": "<<"..."<<endl;
				
			
	}
	
	return 0;
	
}
