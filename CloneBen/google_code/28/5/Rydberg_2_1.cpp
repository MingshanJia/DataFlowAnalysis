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

int mod = 9901;
int S[400];
bool M[400];
int deg[400];
int main(){
	int T,n,k;
	scanf("%d",&T);
	FORE(tt,1,T){
		scanf("%d%d",&n,&k);
		FOR(i,0,k) scanf("%d%d",&F[i][0],&F[i][1]);
		int ret = 0;
		FOR(sub,0,(1<<k)){
		
			FORE(i,1,n){
				S[i]=i;
				M[i]=false;
				deg[i] = 0;
			}
			FOR(i,0,k) if((sub>>i)&1){
				deg[F[i][0]]++;
				deg[F[i][1]]++;
			}
			bool stop = false;
			int path = 0;
			FORE(i,1,n){
				if(deg[i]>2) stop = true;
				if(deg[i]==1) path++;
			}
			if(stop) continue;
			FOR(z,0,20){
				FOR(i,0,k) if((sub>>i)&1){
					S[F[i][0]]=min(S[F[i][0]],S[F[i][1]]);
					S[F[i][1]]=min(S[F[i][0]],S[F[i][1]]);
				}
			}
			int sp = 0, ex = 0;
			FORE(i,1,n){
				if(S[i]==i) sp++;
				else if(!M[S[i]]){
					M[S[i]]=true;
					ex++;
				}
			}
			if(sp>1 && path/2 != ex) continue;
			int a = 0;
			
			if(sp==1) a = 2;
			else if(sp==2){
				if(ex==1) a = 2;
				else a = 4;
			}
			else{
			 	a = 1;
				FORE(i,2,sp-1) a = (a*i)%(mod*2);
				FOR(i,0,ex) a = (a*2)%(mod*2);
			}
			int ile = 0;
			FOR(i,0,k) if((sub>>i)&1) ile++;
			if(ile%2==0) ret+=a;
			else ret-=a;
			while(ret<0) ret+=(mod*2);
			while(ret>=(mod*2)) ret-=(mod*2);
		}
		printf("Case #%d: %d\n",tt,ret/2);
	}
}
