#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <queue>
using namespace std;
typedef long long LL;
#define INF 1000000000
#define SZ(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);i++) 

bool ok[1<<15];
int mem[1<<15];
int p[15][2];
int n,k,best;

int count(int sub){
	if(mem[sub]!=-1) return mem[sub];
	if(sub==0){
		mem[sub]=0;
		return 0;
	}
	if(ok[sub]){
		mem[sub]=1;
		return 1;
	}
	mem[sub] = 100;
	FOR(i,1,sub){
		if((sub&i)==i) mem[sub] = min(mem[sub],count(i)+count(sub-i));
	}
	return mem[sub];

}

void go(int left,int right){
	if(left>right) return;
	int mid = (left+right)/2;
	FOR(i,0,(1<<n)){
		int xmin = 64000, ymin = 64000, xmax=0,ymax=0;
		mem[i] = -1;
		FOR(j,0,n) if((i>>j)&1){
			xmin = min(xmin,p[j][0]);
			ymin = min(ymin,p[j][1]);
			xmax = max(xmax,p[j][0]);
			ymax = max(ymax,p[j][1]);
		}
		if(max(xmax-xmin,ymax-ymin)<=mid) ok[i]=true;
		else ok[i]=false;
	}
	int a = count((1<<n)-1);
	if(a<=k){
		if(mid<best) best = mid;
		go(left,mid-1);
	}
	else go(mid+1,right);
}

int main(){
	int T;
	scanf("%d",&T);
	FORE(tt,1,T){
		scanf("%d%d",&n,&k);
		FOR(i,0,n) scanf("%d%d",&p[i][0],&p[i][1]);
		best = 64000;
		go(1,64000);
		printf("Case #%d: %d\n",tt,best);
	}
}
