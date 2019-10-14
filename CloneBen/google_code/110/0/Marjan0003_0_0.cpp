#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>


using namespace std;
ifstream in("in");


char read_char(){
	char b;
	int c;
	int cnum=0;
	for(int i=0;i<8;i++){
		in>>b;
		if(b=='I')
			c=1;
		else
			c=0;
		cnum=cnum*2+c;
	}
	return (char)cnum;
}

int main(){
	
	int casenum=0;
	in>>casenum;
	int b;
	for (int c=0;c<casenum;c++){
		string s="";
		in>>b;
		for(int i=0;i<b;i++){
			char c=read_char();		
			s=s+c;
		}
		cout<<"Case #"<<c+1<<": "<<s<<endl;
			
	}
	
	return 0;
	
}
