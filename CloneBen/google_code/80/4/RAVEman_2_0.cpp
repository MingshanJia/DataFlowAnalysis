#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

int n,m;
int u[2222];
int v[2222];

bool has(vi v,int x){
	REP(i,v.size()) if(v[i]==x) return 1;
	return 0;
}

vector<vi> vv;

void parse(int x,int y){
	vi v1,v2;
	vi v = vv.back();vv.pop_back();

	int i1 = -1,i2=-1;
	REP(i,v.size()){
		if(v[i] == x) i1 = i;
		if(v[i] == y) i2 = i;
	}
	if(i1>i2) swap(i1,i2);

	FOR(i,i1,i2+1) v1.pb(v[i]);
	for(int i=i2;;i++){
		if(i==v.size()) i=0;
	
		v2.pb(v[i]);

		if(i==i1) break;
	}

	vv.pb(v1);
	vv.pb(v2);
}

int r[2222];
int best =0;
int rb[2222];

void go(int pos,int mask){
	if(pos==n){
		int num = 0;
		REP(i,8)if(mask&(1<<i)) num++;
		if(num<=best) return;

		REP(i,vv.size()){
			int mm = 0;
			REP(j,vv[i].size()) mm |= 1<<r[vv[i][j]];

			if(mm!=mask) 
				return;
		}
		if(n==8)
			n=n;
		best = num;
		REP(i,n) rb[i] = r[i];
		return;
	}
	REP(i,8)if((mask&(1<<i)) || i==0 || i && (mask&(1<<(i-1)))){
		r[pos] = i;
		go(pos+1,mask|(1<<i));
	}
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n>>m;
		REP(i,m) scanf("%d",u+i),u[i]--;
		REP(i,m) scanf("%d",v+i),v[i]--;
		vi t;
		REP(i,n) t.pb(i);
		vv.clear();
		vv.pb(t);

		REP(i,m){
			int U = u[i];
			int V = v[i];
			REP(j,vv.size()) if(has(vv[j],U) && has(vv[j],V)){
				swap(vv[j],vv.back());
				parse(U,V);
				break;
			}
		}
		best=0;
		go(0,0);
		printf("Case #%d: %d\n",TC+1,best);
		REP(i,n){
			if(i)printf(" ");
			printf("%d",rb[i]+1);
		}
		puts("");
	}
	return 0;
}