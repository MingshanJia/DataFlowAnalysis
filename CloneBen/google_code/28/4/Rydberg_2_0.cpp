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

int F[20][2];
bool forb[20][20];
int mod = 9901;
int S[400];
bool M[400];
int deg[400];
int tab[20];

int main(){
	int T,n,k;
	scanf("%d",&T);
	FORE(tt,1,T){
		scanf("%d%d",&n,&k);
		FORE(i,1,n) FORE(j,1,n) forb[i][j] = false;
		FOR(i,0,k){
			scanf("%d%d",&F[i][0],&F[i][1]);
			forb[F[i][0]][F[i][1]] = true;
			forb[F[i][1]][F[i][0]] = true;
		}
		FORE(i,1,n) tab[i-1]=i;
		int ret = 0;
		do{
			if(tab[0]!=1) continue;
			bool ok = true;
			FOR(i,0,n){
				if(forb[tab[i]][tab[(i+1)%n]]) ok =false;
			}
			if(ok) ret++;
		}while(next_permutation(tab,tab+n));
		
		ret/=2;
		printf("Case #%d: %d\n",tt,ret%mod);
	}
}
