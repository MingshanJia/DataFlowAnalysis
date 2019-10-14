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

const int N=10100,inf=0x20202020;
int _,__,n,e[N],t[N],l[N],vis[N],cnt[N];
int cost(int x,int y) {
	if (x==-1) return l[y]+t[y];
	int r=l[y];
	while (r<l[x]+t[x]) r+=24;
	return r+t[y]-(l[x]+t[x]);
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		rep(i,0,2*n) scanf("%d%d%d",e+i,l+i,t+i),--e[i];
		int ret=inf;
		rep(S,0,(1<<n)) {
			rep(i,0,2*n) vis[i]=0,cnt[i]=0;
			int p=0,pe=-1,mv=0;
//			puts("");
			rep(i,0,2*n) {
				if (pe!=-1&&vis[pe]) { mv=inf; break; }
				if (pe!=-1) vis[pe]=1;
				if (cnt[p]==0) {
//					printf("gg");
					mv+=cost(pe,p*2+((S>>p)&1));
					pe=p*2+((S>>p)&1);
					cnt[p]++;
					p=e[pe];
				} else {
//					printf("ff");
					mv+=cost(pe,p*2+(1^((S>>p)&1)));
					pe=p*2+(1^((S>>p)&1));
					cnt[p]++;
					p=e[pe];
				}
//				printf("%d ",pe);
			}
			ret=min(ret,mv);
		}
		printf("Case #%d: %d\n",++__,ret);
	}
}
