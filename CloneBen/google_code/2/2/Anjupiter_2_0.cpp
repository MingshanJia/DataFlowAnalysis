//TAG : 
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)	for(int (i)=0;(i)<(n);(i)++)
#define repd(i,n)	for(int (i)=(n)-1;(i)>=0;(i)--)
#define REP(i,j,n)  for(int (i)=(j),_n=(n);(i)<_n;(i)++)
#define FOR(i,a,b)  for(int (i)=(a),_b=(b);(i)<=_b;(i)++)
#define FORD(i,a,b) for(int (i)=(a),_b=(b);(i)>=_b;(i)--)
#define ALL(c) (c).begin(),(c).end()
#define SORT(c) sort(ALL(c))
#define CLEAR(x) memset((x),0,sizeof(x))
#define ff first
#define ss second
#define MP make_pair
typedef pair<int, int>	pii;
typedef vector<pii>	vii;
typedef vector<int>	vi;
typedef long long		ll;
template<typename T> void cmax(T& a, T b) { if (a < b) a = b; }
template<typename T> void cmin(T& a, T b) { if (a > b) a = b; }
#ifdef _MSC_VER
#include "builtin_gcc_msvc.h"
#define gets	gets_s
#else
#define popcnt(x)	__builtin_popcount(x)
#define ctz(x)		__builtin_ctz(x)
#define clz(x)		__builtin_clz(x)
#define popcntll(x)	__builtin_popcountll(x)
#define ctzll(x)	__builtin_ctzll(x)
#define clzll(x)	__builtin_clzll(x)
#endif

int main()
{
	const int MX=100,INF = 1e9;
	int D[MX][MX];
	double F[201][MX];
	int TC;cin>>TC;
	FOR(T, 1, TC)
	{
		int n,m,p;cin>>n>>m>>p;
		rep(i,n)rep(j,n)D[i][j]=INF;
		while(m--){
			int u,v,d;cin>>u>>v>>d;
			--u,--v;
			cmin(D[u][v],d);
			cmin(D[v][u],d);
		}
		rep(k,n)rep(i,n)rep(j,n)
			cmin(D[i][j],D[i][k]+D[k][j]);
		rep(i,n){
			int sum=0;
			rep(j,n)if(i!=j)sum+=D[i][j];
			F[1][i]=(double)sum/(n-1);
		}
		FOR(pi,2,p){
			rep(i,n){
				double sum=0;
				rep(j,n)if(i!=j)sum+=D[i][j]+F[pi-1][j];
				F[pi][i]=sum/(n-1);
			}
		}
		printf("Case #%d: %.6lf\n", T, F[p][0]);
	}

	return 0;
}