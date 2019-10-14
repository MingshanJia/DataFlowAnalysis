#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif
#define int 		long long
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
int test=1;
void solve(){
	cout<<"Case #"<<test++<<": ";
	int L;
	cin>>L;
	string a,b,c;
	cin>>a>>b>>c;
	set<string>goods;
	vector<string>p={a,b,c};
	sort(all(p));
	do{
		set<pair<char,char>>smaller;
		bool good=1;
		{
			int m=0,n=1;
			int i=0;
			while(i<sz(p[m]) and i<sz(p[n]) and p[m][i]==p[n][i])i++;
			if(i==sz(p[m])){}
			else if(i==sz(p[n]))good=0;
			else{
				smaller.insert(mp(p[m][i],p[n][i]));
			}
		}
		{
			int m=0,n=2;
			int i=0;
			while(i<sz(p[m]) and i<sz(p[n]) and p[m][i]==p[n][i])i++;
			if(i==sz(p[m])){}
			else if(i==sz(p[n]))good=0;
			else{
				smaller.insert(mp(p[m][i],p[n][i]));
			}
		}
		{
			int m=1,n=2;
			int i=0;
			while(i<sz(p[m]) and i<sz(p[n]) and p[m][i]==p[n][i])i++;
			if(i==sz(p[m])){}
			else if(i==sz(p[n]))good=0;
			else{
				smaller.insert(mp(p[m][i],p[n][i]));
			}
		}
		if(!good)continue;
		vector<pii>temp(all(smaller));
		if(sz(temp)>=2 and temp[0].F==temp[1].S and temp[1].F==temp[0].S){
			good=0;
		}
		if(sz(temp)>2 and temp[2].F==temp[1].S and temp[1].F==temp[2].S){
			good=0;
		}
		if(sz(temp)>2 and temp[0].F==temp[2].S and temp[2].F==temp[0].S){
			good=0;
		}
		
		if(sz(temp)==3 and (temp[0].F==temp[1].S and temp[1].F==temp[2].S and temp[2].F==temp[0].S)){
			good=0;
		}
		if(sz(temp)==3 and (temp[0].F==temp[2].S and temp[2].F==temp[1].S and temp[1].F==temp[0].S)){
			good=0;
		}
		if(!good)continue;
		goods.insert(p[1]);
	}while(next_permutation(all(p)));
	if(goods.count(a))cout<<"YES ";
	else cout<<"NO ";
	if(goods.count(b))cout<<"YES ";
	else cout<<"NO ";
	if(goods.count(c))cout<<"YES ";
	else cout<<"NO ";
	cout<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}