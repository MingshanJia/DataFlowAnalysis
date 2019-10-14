// '
#include <bits/stdc++.h>
// #include <bits/extc++.h>
using namespace std;
// using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld TAU=2*acos(-1);
const ld eps=1e-8;
const int inf=1e9+99;
const ll linf=1e18+99;


int hd,ad,hk,ak,b,d;
map<tuple<int,int,int,int>,int> dp;
int f(int h,int hh,int ad,int ak) {
	// cerr<<"calling f on "<<h<<","<<hh<<","<<ad<<","<<ak<<endl;
	if(hh<=0) return 0;
	if(h<=0) return inf;
	tuple<int,int,int,int> idx={h,hh,ad,ak};
	if(dp.count(idx)) return dp[idx];
	int &ans=dp[idx];
	ans=inf;
	if(h<hd-ak) ans=min(ans,1+f(hd-ak,hh,ad,ak));
	if(b && ad<hh) ans=min(ans,1+f(h-ak,hh,ad+b,ak));
	if(d && ak) ans=min(ans,1+f(h-ak+d,hh,ad,max(ak-d,0)));
	ans=min(ans,1+f(h-ak,hh-ad,ad,ak));
	return ans;
}

int g() {
	if(ad>=hk) return 1;
	if(ak-d>=hd) return inf;
	dp.clear();
	return ak>=hd ? 1+f(hd-ak+d,hk,ad,ak-d) : f(hd,hk,ad,ak);
}

void go(int tn) {
	scanf("%d%d%d%d%d%d",&hd,&ad,&hk,&ak,&b,&d);
	int ans=g();
	if(ans<inf) printf("Case #%d: %d\n",tn,ans);
	else printf("Case #%d: IMPOSSIBLE\n",tn);
}




int32_t main() {
	int T; scanf("%d",&T); for(int i=1;i<=T;i++) {
		go(i);
	}
}
