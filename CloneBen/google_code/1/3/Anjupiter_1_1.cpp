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

struct Item{
	ll x,c,cnt;
};
const int MX=4e5;
ll X[MX],Y[MX],Z[(int)1e5];
pair<ll,int> A[MX*2];
Item B[MX*2];
int main()
{
	int TC;cin>>TC;
	FOR(T, 1, TC)
	{
		int n,q;cin>>n>>q;
		rep(k,3){
			ll*A=(k==0?X:(k==1?Y:Z));
			ll a,b,c,m;
			cin>>A[0]>>A[1]>>a>>b>>c>>m;
			REP(i,2,(k<2?n:q)){
				A[i]=(a*A[i-1]+b*A[i-2]+c)%m;
			}
		}
		ll sum=0;
		rep(i,n){
			if(X[i]>Y[i])swap(X[i],Y[i]);
			++X[i],++Y[i];
			sum+=Y[i]-X[i]+1;
			A[i*2]={X[i],-1};
			A[i*2+1]={Y[i]+1,1};
		}
		sort(A,A+n*2);
		int m=0,c=0;
		for(int i=0;i<n*2;){
			c-=A[i].ss;
			int j=i+1;
			while(j<n*2&&A[i].ff==A[j].ff)
				c-=A[j++].ss;
			B[m++]={A[i].ff,c,0};
			i=j;
		}
		ll cnt=0;
		REP(i,1,m){
			cnt+=(B[i].x-B[i-1].x)*B[i-1].c;
			B[i].cnt=cnt;
		}
		assert(sum==cnt);
		ll ans=0;
		rep(i,q){
			ll f=sum-(Z[i]+1);
			if(f<0)continue;
			int l=0,r=m-1,aha=-1;
			while(l<=r){
				int mid=(l+r)>>1;
				if(f>=B[mid].cnt)
					aha=mid,l=mid+1;
				else r=mid-1;
			}
			ans+=(i+1)*(B[aha].x+(f-B[aha].cnt)/B[aha].c);
		}
		printf("Case #%d: %lld\n", T,ans);
	}

	return 0;
}