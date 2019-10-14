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
	double F[1001][MX];
	double G[1001][MX];
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
		double ans=p==1?F[p][0]:0.0;
		FOR(pi,2,p){
			rep(i,n){
				double sum=0;
				rep(j,n)if(i!=j)sum+=D[i][j]+F[pi-1][j];
				F[pi][i]=sum/(n-1);
			}
			rep(i,n){
				G[pi][i]=F[pi][i]-F[pi-1][i];
			}
			double lo = *min_element(G[pi], G[pi] + n);
			double hi = *max_element(G[pi], G[pi] + n);
			double g = hi - lo;
			if(pi==1000){
				assert(g<1e-9);
				ans=F[pi][0]+lo*(p-pi);
				break;
			}
			if(pi==p)ans=F[p][0];
		}
		printf("Case #%d: %.6lf\n", T, ans);
	}

	return 0;
}