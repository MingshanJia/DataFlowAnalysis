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


int main(){
	int T;
	scanf("%d",&T);
	FORE(tt,1,T){
		int w,b;
		scanf("%d%d",&w,&b);
		if(b%2==0) printf("Case #%d: WHITE\n",tt);
		else printf("Case #%d: BLACK\n",tt);
	}
}
