#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>
#include<math.h>
#include<set>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <algorithm>
#include <vector>


using namespace std;
int rows[200];
set<string> all;

int main(){
	int T,F,S,x,y;
	cin>>T;
	for (int tnum=0;tnum<T;tnum++){
		cin>>F>>S;
		for(int i=0;i<200;i++)
			rows[i]=0;
		all.clear();
		for(int i=0;i<F;i++){
			cin>>x>>y;
			stringstream temp("");
			temp<<x<<"___"<<y<<endl;
			string r=temp.str();
			if(all.find(r)==all.end()){
				if(x!=y){
					rows[x]++;
					rows[y]++;
				}
				else
					rows[x]++;
				all.insert(r);
			}
		}
		int max=0;
		for(int i=0;i<200;i++){
			if(rows[i]>max)
				max=rows[i];
		}
		cout<<"Case #"<<(tnum+1)<<": "<<max<<endl;
	}


	return 0;
}