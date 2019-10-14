/*
 * A.cpp
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

map<long long,int> m;
vector<long long> v;

int main(){

	freopen("A.in","rt",stdin);
	freopen("A.txt","wt",stdout);

	int TC,n;
	cin>>TC;
	for(int tt=0;tt<TC;tt++){
		cin>>n;
		m.clear();
		v.clear();
		v.resize(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
			m[v[i]] ++;
		}
		for(int i=0;i<n;i++){
			if(m[v[i]]%2){
				cout<<"Case #"<<tt+1<<": "<<v[i]<<endl;
				break;
			}
		}
	}

	return 0;
}
