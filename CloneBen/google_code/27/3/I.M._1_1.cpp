/*
 * B.cpp
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

map<int,vector<int> > ma;
vector<int> vv;
bool sol(int n,int tar){

	for(int i=1;i<=n;i++){
		if(i == tar)continue;
		if(ma[i].size() == 0)continue;
		vector<int> v = ma[i];
		sort(v.begin(),v.end());
		int j = 0,ii;
		for(ii=v.size() -1;ii>=0;ii--){
			if(ii < j)
				break;
			if(!v[ii])return false;
			j += (v[ii]-1);
		}
		vv[i-1] = (v.size() - 1)-ii;
	}
	return true;

}

int main(){

	freopen("B.in","rt",stdin);
	freopen("B.txt","wt",stdout);

	int TC,n,m,tar,x,y;
	cin>>TC;
	for(int tt=0;tt<TC;tt++){

		ma.clear();
		cin>>n >> tar;
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>x>>y;
			ma[x].push_back(y);
		}
		vv.clear();
		vv.resize(n,0);
		cout<<"Case #"<<tt+1<<":";
		if(sol(n,tar))
			for(int i=0;i<n;i++)
				cout<<" "<<vv[i];
		else
			cout<<" IMPOSSIBLE";
		cout<<endl;

	}

	return 0;
}
