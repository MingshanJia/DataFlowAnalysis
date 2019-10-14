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
typedef long long	ll;
typedef vector<ll> vl;
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
	int TC;cin>>TC;
	FOR(T, 1, TC)
	{
		pii S,E;
		int n,m,e;cin>>n>>m>>e>>S.ff>>S.ss>>E.ff>>E.ss;
		--S.ff,--S.ss,--E.ff,--E.ss;
		int A[100][100];
		rep(i, n)rep(j, m) {
			cin >> A[i][j];
			if (A[i][j] > 0) {
				A[i][j] = 0;
			}
		}
		int D[100][100];
		fill(D[0],D[0]+(int)1e4,e+1);
		const int CANT=-100000;
		D[S.ff][S.ss]=0;
		priority_queue<tuple<ll,int,int>> Q;
		Q.emplace(0,S.ff,S.ss);
		ll ans=-1;
#define PUSH(xx,yy)	if(A[xx][yy]!=CANT&&d-A[xx][yy]<D[xx][yy])D[xx][yy]=d-A[xx][yy],Q.emplace(-D[xx][yy],xx,yy);
		while(!Q.empty()){
			ll d;int x,y;
			tie(d,x,y)=Q.top();Q.pop();
			d=-d;
			if(x==E.ff&&y==E.ss){
				ans=e-d;break;
			}
			if(d>D[x][y])continue;
			if(x)PUSH(x-1,y);
			if(x+1<n)PUSH(x+1,y);
			if(y)PUSH(x,y-1);
			if(y+1<m)PUSH(x,y+1);
		}
		printf("Case #%d: %lld\n", T, ans);
	}

	return 0;
}