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

ll comb(int n,int m){
	ll a=1,b=1;
	rep(i,m)a*=n-i,b*=i+1;
	return a/b;
}
int main()
{
	int TC;cin>>TC;
	FOR(T, 1, TC)
	{
		int n;cin>>n;
		ll A[7000];
		rep(i,n)cin>>A[i];
		sort(A,A+n);
		pair<ll,int> B[7000];
		int m=0;
		for(int i=0;i<n;){
			int j=i+1;
			while(j<n&&A[i]==A[j])++j;
			B[m++]={A[i],j-i};
			i=j;
		}
		ll ans=0,s=0;
		rep(i,m){
			s+=B[i].ss;
			if(B[i].ff<=1&&B[i].ss>=3){
				ans+=comb(B[i].ss,3);
			}
			if(B[i].ff==0){
				if(B[i].ss>=2)
					ans+=comb(B[i].ss,2)*(n-s);
			}else if(B[i].ff==1){
				REP(j,i+1,m){
					if(B[j].ss>=2)
						ans+=B[i].ss*comb(B[j].ss,2);
				}
			}else{
				if(B[i].ss>=2){
					auto b=make_pair(B[i].ff*B[i].ff,0);
					int k=lower_bound(B,B+m,b)-B;
					if(k>=0&&k<m&&B[k].ff==b.ff)
						ans+=comb(B[i].ss,2)*B[k].ss;
				}
				REP(j,i+1,m){
					auto b=make_pair(B[i].ff*B[j].ff,0);
					int k=lower_bound(B,B+m,b)-B;
					if(k>=0&&k<m&&B[k].ff==b.ff)
						ans+=B[i].ss*B[j].ss*B[k].ss;
				}
			}
		}
		printf("Case #%d: %lld\n", T, ans);
	}

	return 0;
}