#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tp;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
typedef pair<LL, LL> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;
typedef pair<LL, pii> plpii;
typedef pair<LD, LD> pdd;
typedef pair<LD, int> pdi;
typedef pair<LD, LL> pdl;
typedef pair<int, LD> pid;
typedef pair<LL, LD> pld;
const int mod = 1e9 + 7;
const int hf = 999983;
const int N = 1e6;
int a[N];
map<LL, LL> dp;
void solve(int tt){
	dp.clear();
	int n;
	scanf("%d", &n);
	LL z = 0;
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
		if(a[i] == 0) z++;
	}
	sort(a+1, a+1+n);
	LL ans = z*(z-1)*(z-2)/6;
	ans += z*(z-1)/2*(n-z);
	for(int i=1;i<=n;i++){
		if(a[i] == 0) continue;
		ans += dp[a[i]];
		for(int j=i-1;j>=1;j--){
			if(a[j] == 0) continue;
			dp[(LL)a[i]*a[j]]++;
		}
	}
	printf("Case #%d: %lld\n", tt, ans);
}
int main(){
	int t;
	scanf("%d", &t);	
	for(int tt=1;tt<=t;tt++) solve(tt);
}