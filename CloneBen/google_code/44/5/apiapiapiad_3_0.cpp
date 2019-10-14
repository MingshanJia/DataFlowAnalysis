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

VI e[60];
int g[40][40],vis[60],T,c0,c1,n,_,__;
char a[60];
void dfs(int u) {
	vis[u]=T;
	if (u<n) c0++; else c1++;
	for (auto v:e[u]) if (vis[v]==-1) dfs(v);
}
bool check1(int S) {
	rep(i,0,2*n) e[i].clear();
	rep(i,0,n) rep(j,0,n) if ((S>>(i*n+j))&1) {
		e[i].pb(j+n); e[j+n].pb(i);
		g[i][j]=1;
	} else g[i][j]=0;
	rep(i,0,2*n) vis[i]=-1;
	T=0;
	rep(i,0,2*n) if (vis[i]==-1) {
		c0=0,c1=0;
		dfs(i);
		T++;
		if (c0!=c1) return 0;
	}
	rep(i,0,n) rep(j,0,n) if ((vis[i]==vis[j+n])!=g[i][j]) return 0;
/*	printf("%d\n",S);
	rep(i,0,n) {
		rep(j,0,n) printf("%d",g[i][j]); puts("");
	}*/
	return 1;
}
int lf[40],rf[40];
bool Dfs(int d) {
	if (d==n) return 1;
	rep(i,0,n) if (!lf[i]) {
		lf[i]=1;
		bool val=0;
		rep(j,0,n) if (g[i][j]&&!rf[j]) {
			val=1; rf[j]=1;
//			printf("%d %d\n",i,j);
			if (Dfs(d+1)==0) return 0;
			rf[j]=0;
		}
//		printf("F %d %d %d\n",d,i,val);
		if (val==0) return 0;
		lf[i]=0;
	}
	return 1;
}
bool check2(int S) {
	rep(i,0,n) rep(j,0,n) if ((S>>(i*n+j))&1) g[i][j]=1;
	else g[i][j]=0;
	rep(i,0,n) lf[i]=rf[i]=0;
	return Dfs(0);
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		int S=0;
		rep(i,0,n) {
			scanf("%s",a);
			rep(j,0,n) if (a[j]=='1') S|=(1<<(i*n+j));
		}
		int ret=n*n+1;
		rep(pS,0,(1<<(n*n))) if ((S&pS)==S) {
			if (check1(pS)) {
				assert(check2(pS));
				ret=min(ret,__builtin_popcount(S^pS));
			}
		}
		printf("Case #%d: %d\n",++__,ret);
/*
		rep(pS,0,(1<<(n*n))) {
			int w1=check1(pS),w2=check2(pS);
			if (w1!=w2) {
				printf("%d %d %d\n",pS,w1,w2);
				assert(0);
			}
			assert(check1(pS)==check2(pS));
		}*/
	}
}
