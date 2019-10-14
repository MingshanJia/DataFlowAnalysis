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

const int N = (int) 105, mod = (int) 0;
int sz = 1, nxt[N * N][2], forbidden[N * N];
long long dp[N * N], odp[N * N];
string s[N];
int main() {
	int tc;
	cin >> tc;
	for (int tt = 1; tt <= tc; ++tt) {
		memset(dp, 0, sizeof dp);
		memset(nxt, 0, sizeof nxt);
		memset(forbidden, 0, sizeof forbidden);
		sz = 1;
		cout << "Case #" << tt << ": ";
		int n, m;
		cin >> n >> m;
		for (int j = 0; j < m; ++j) {
			cin >> s[j];
			int v = 0;
			for (auto c : s[j]) {
				int g = (c == 'B');
				if (!nxt[v][g]) {
					nxt[v][g] = sz++;
				}
				v = nxt[v][g];
			}
			forbidden[v] = 1;
		}
		for (int j = 0; j <= sz; ++j)
			for (int i = 0; i <= 1; ++i)
				if (nxt[j][i] == 0)
					nxt[j][i] = sz;
		dp[0] = 1;
		for (int j = 0; j < n; ++j) {
			memcpy(odp, dp, sizeof dp);
			memset(dp, 0, sizeof dp);
			for (int state = 0; state <= sz; ++state) {
				for (int i = 0; i <= 1; ++i) {
					if (!forbidden[nxt[state][i]]) dp[nxt[state][i]] += odp[state];	
				}
			}
		}
		long long res = 0;
		for (int j = 0; j <= sz; ++j)
			if (!forbidden[j])
				res += dp[j];
		cout << res << '\n';
	}
}

















