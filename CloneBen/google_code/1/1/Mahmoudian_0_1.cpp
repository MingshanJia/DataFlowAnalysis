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
const int N = (int) 7005, M = 2e5 + 5, mod = (int) 0;
int a[N], c[M];
void fadd(int x) {
	if (x < M)
		c[x]++;
}
int fcnt(int x) {
	if (x < M)
		return c[x];
	return 0;
}
int32_t main() {
	int tc;
	cin >> tc;
	for (int tt = 1; tt <= tc; ++tt) {
		memset(c, 0, sizeof c);
		cout << "Case #" << tt << ": ";
		int n, res = 0;
		cin >> n;
		for (int j = 0; j < n; ++j)
			cin >> a[j];
		map<int, int> cnt;
		for (int m = n - 1; m >= 0; --m) {
			for (int l = 0; l < m; ++l) {
				if (a[l] == 0) continue;
				if (a[m] == 0) continue;
				if (a[l] == 1 && a[m] == 1) {
					res += fcnt(1);	
				} else if (a[l] == 1 || a[m] == 1) {
					res += fcnt(a[l] * a[m]);	
				} else {
					res += fcnt(a[l] * a[m]);
					if (a[l] != a[m]) {
						if (a[l] % a[m] == 0)
							res += fcnt(a[l] / a[m]);
					}
					if (a[m] % a[l] == 0)
						res += fcnt(a[m] / a[l]);
				}
			}
			fadd(a[m]);
		}
		res += c[0] * (c[0] - 1) * (c[0] - 2) / 6 + c[0] * (c[0] - 1) / 2 * (n - c[0]);
		cout << res << endl;	
	}
}

















