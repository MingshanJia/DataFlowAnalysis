//Franciszek Budrowski

#include<bits/stdc++.h>
#define FOR(i,s,e) for(int i=(s);i<=(e);i++)
#define FORD(i,s,e) for(int i=(s);i>=(e);i--)
#define ALL(k) (k).begin(),(k).end()
#define e1 first
#define e2 second
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;

const bool print=false;
const int MAXN=55;
const LD EPS=1e-11;
LD dp[MAXN];



main(){
	int test;scanf("%d",&test);
	FOR(casenr,1,test){
		int n,k;scanf("%d%d",&n,&k);
		LD u;scanf("%Lf",&u);
		FOR(i,1,n){
			scanf("%Lf",&dp[i]);
		}
		LD dol=0.0000,gora=1.0000;
		LD bestmoglichkeit=0.0;
		while((gora-dol)>EPS){
			LD sr=(gora+dol)/2;
			LD suma=0.;
			LD jetzt=1.;
			FOR(i,1,n){
				if(dp[i]>sr) {jetzt*=dp[i];continue;}
				else suma+=sr-dp[i],jetzt*=sr;
			}
			if(suma<u+EPS) bestmoglichkeit=max(bestmoglichkeit,jetzt),dol=sr;
			else gora=sr;
		}
		printf("Case #%d: %.9Lf\n",casenr,bestmoglichkeit);
	}
}
		
