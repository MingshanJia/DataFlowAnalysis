#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int _,n,k,__;
double ret,dp[20][20],p[20];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&k);
		rep(i,0,n) scanf("%lf",p+i);
		ret=0;
		rep(S,0,(1<<n)) {
			if (__builtin_popcount(S)!=k) continue;
			dp[0][0]=1;
			int t=0;
			rep(i,0,n) if (S&(1<<i)) {
				rep(j,0,t+2) dp[t+1][j]=0;
				rep(j,0,t+1) dp[t+1][j+1]+=dp[t][j]*p[i],dp[t+1][j]+=dp[t][j]*(1-p[i]);
				t++;
			}
			ret=max(ret,dp[k][k/2]);
		}
		printf("Case #%d: %.10f\n",++__,ret);
	}
}
