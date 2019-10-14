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
LL x[400005], y[400005], z[400005];
LL l[400005], r[400005], k[400005];
map<int, int> dp;
map<int, int> dp2, dp3;
map<int, int>::iterator its;
void solve(int tt){
	cerr << tt << endl;
	dp.clear();
	dp2.clear();
	dp3.clear();
	LL a, b, c, m;
	int n, q;
	scanf("%d%d", &n, &q);
	scanf("%lld%lld%lld%lld%lld%lld", &x[1], &x[2], &a, &b, &c, &m);
	for(int i=3;i<=n;i++){
		x[i] = (a*x[i-1] + b*x[i-2] + c)%m;
	}
	scanf("%lld%lld%lld%lld%lld%lld", &y[1], &y[2], &a, &b, &c, &m);
	for(int i=3;i<=n;i++){
		y[i] = (a*y[i-1] + b*y[i-2] + c)%m;
	}
	scanf("%lld%lld%lld%lld%lld%lld", &z[1], &z[2], &a, &b, &c, &m);
	for(int i=3;i<=q;i++){
		z[i] = (a*z[i-1] + b*z[i-2] + c)%m;
	}
	for(int i=1;i<=q;i++){
		k[i] = z[i]+1;
	}


	for(int i=1;i<=n;i++){
		l[i] = min(x[i], y[i]) + 1;
		r[i] = max(x[i], y[i]) + 1;
	}

	// test
	// int n, q;
	// scanf("%d%d", &n, &q);
	// for(int i=1;i<=n;i++){
	// 	scanf("%lld %lld", &l[i], &r[i]);
	// }
	// for(int i=1;i<=q;i++){
	// 	scanf("%lld", &k[i]);
	// }

	dp[-2e9] = 0;
	dp[2e9] = 0;
	LL cnt = 0;	
	for(int i=1;i<=n;i++){
		cnt += r[i]-l[i]+1;
		dp[-l[i]+1] = 1;
		dp[-r[i]] = 1;

		dp2[-r[i]]++;
		dp2[-l[i]+1]--;
	}

	vector<pll> Q;
	for(int i=1;i<=q;i++){
		Q.push_back(pll(k[i], i));
	}
	sort(Q.begin(), Q.end());

	LL ans = 0;

	LL curk = 0, pvK;
	LL C = 0, V = 0;
	LL pvC = 0, pvV = 0;
	its = dp.begin();
	bool st = 0;
	for(int i=0;i<Q.size();i++){
		LL idx = Q[i].second;
		LL k = Q[i].first;
		if(k > cnt) continue;

		LL res = 0;
		while(curk < k && its != dp.end()){
			pvV = its->first;
			pvC = C;

			its++;

			V = its->first-1;
			C += dp2[its->first];
			pvK = curk;
			curk += (V-pvV+1)*pvC;
		}

		LL lo = pvV, hi = V;
		while(lo <= hi){
			LL mid = (lo+hi)/2;

			if((mid-pvV+1)*pvC + pvK >= k) res = mid, hi = mid-1;
			else lo = mid+1;
		}
		res = -res;
		ans += res*idx;
	}
	printf("Case #%d: %lld\n", tt, ans);
}
int main(){
	int t;
	scanf("%d", &t);	
	for(int tt=1;tt<=t;tt++) solve(tt);
}