/*
 * C.cpp
 *
 *  Created on: Mar 22, 2010
 *      Author: Yasser
 */


#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<sstream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<complex>

using namespace std;

vector<int> v;

int main(){
	freopen("C.in","rt",stdin);
	freopen("C.txt","wt",stdout);

	int TC,n,c;
	cin>>TC;
	for(int tt=0;tt<TC;tt++){
		cin>>n >> c;
		v.clear();
		v.resize(n);
		for(int i=0;i<n;i++)
			cin>>v[i];

		int sol = 0;
		while(true){
			sort(v.begin(),v.end());
			if(v[n-c]>0){
				sol++;
				for(int i=0;i<c;i++){
					v[n-(1+i)]--;
				}
			}
			else
				break;
		}
		cout<<"Case #"<<tt+1<<": "<<sol<<endl;
	}

	return 0;
}
