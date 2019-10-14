// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define int long long
#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;
const int N = (int) 8e5 + 6, mod = (int) 0;
int sum[N], ax[N], ay[N], az[N], xa[3], xb[3], xc[3], xm[3], xl[N], xr[N], qk[N];
int rate[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	for (int tt = 1; tt <= tc; ++tt) {
		cerr << tt << endl;
		cout << "Case #" << tt << ": ";
		int n, q;
		cin >> n >> q;
		cin >> ax[0] >> ax[1];
		cin >> xa[0] >> xb[0] >> xc[0] >> xm[0];	
		for (int j = 2; j < n; ++j) ax[j] = (xa[0] * ax[j - 1] + xb[0] * ax[j - 2] + xc[0]) % xm[0];
		cin >> ay[0] >> ay[1];
		cin >> xa[1] >> xb[1] >> xc[1] >> xm[1];	
		for (int j = 2; j < n; ++j) ay[j] = (xa[1] * ay[j - 1] + xb[1] * ay[j - 2] + xc[1]) % xm[1];
		cin >> az[0] >> az[1];
		cin >> xa[2] >> xb[2] >> xc[2] >> xm[2];	
		for (int j = 2; j < q; ++j) az[j] = (xa[2] * az[j - 1] + xb[2] * az[j - 2] + xc[2]) % xm[2];
		for (int j = 0; j < n; ++j) xl[j] = min(ax[j], ay[j]) + 1, xr[j] = max(ax[j], ay[j]) + 1, ++xr[j];
		for (int j = 0; j < q; ++j) qk[j] = 1 + az[j];
		vector<int> p;
		for (int j = 0; j < n; ++j) {
			xr[j] = 1e9 - xr[j] + 1;
			xl[j] = 1e9 - xl[j] + 1;
			swap(xl[j], xr[j]);
			p.pb(xl[j]);
			p.pb(xr[j]);
		}
		sort(ALL(p));
		p.resize(unique(ALL(p)) - p.begin());
		int m = (int) p.size();
		memset(sum, 0, sizeof sum);
		memset(rate, 0, sizeof rate);
		for (int j = 0; j < n; ++j) {
			rate[lower_bound(ALL(p), xl[j]) - p.begin()]++;
			rate[lower_bound(ALL(p), xr[j]) - p.begin()]--;
		}
		for (int j = 1; j <= m; ++j) rate[j] += rate[j - 1];
		for (int j = 0; j < m - 1; ++j) {
			sum[j + 1] = sum[j] + rate[j] * (p[j + 1] - p[j]);	
		}
		int res = 0;
		for (int j = 0; j < q; ++j) {
			if (qk[j] > sum[m - 1]) continue;
			int pos = lower_bound(sum, sum + m, qk[j]) - sum - 1;
			int cur = p[pos];
			assert(rate[pos] != 0);
			int cur_res = (qk[j] - sum[pos] - 1) / rate[pos] + cur;
			cur_res = 1e9  - cur_res;
			res += cur_res * (j + 1);
			
		}
		cout << res << endl;
	}
}

















