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
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 1e9 + 7;
int f[N], inv[N];
int pw(int a, int b) { return b == 0 ? 1 : (LL) pw((LL) a * a % mod, b >> 1) * (b & 1 ? a : 1) % mod; }
int comb(int n, int r) {
	if (n == r) return 1;
	if (n < 0 || r < 0 || n - r < 0) return 0;
	return f[n] * (LL) inv[r] % mod * inv[n - r] % mod;
}
int32_t main() {
	f[0] = inv[0] = 1;
	for (int j = 1; j < N; ++j)
		f[j] = (f[j - 1] * (LL) j) % mod, inv[j] = pw(f[j], mod - 2);
	int tc;
	cin >> tc;
	for (int tt = 1; tt <= tc; ++tt) {
		cout << "Case #" << tt << ": ";
		int n, m;
		cin >> n >> m;
		int res = 0;
		for (int merged = 0; merged <= m; ++merged) {
			int ways = comb(m, merged);
			ways = (LL) ways * pw(2, merged) % mod;
			ways = (LL) ways * f[2 * n - merged] % mod;
			if (merged & 1) {
				res = (res - ways + mod) % mod;	
			} else {
				res = (res + ways) % mod;
			}
		}
		cout << res << '\n';
	}

}

















