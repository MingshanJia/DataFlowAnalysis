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

const int N = (int) 5e6 + 6, mod = (int) 0;
int sum[N];
int main() {
	int tc;
	cin >> tc;
	for (int tt = 1; tt <= tc; ++tt) {
		cout << "Case #" << tt << ": ";
		int n;
		cin >> n;
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j)
			sum[j + 1] = sum[j] + s[j] - '0';
		int res = 0;
		for (int pos = 0; pos < n; ++pos) {
			int cur = sum[pos + 1] - sum[pos];
			int pick_all = (n / 2 + n % 2) - 1;
			int rg = n - pos - 1;
			int lf = pos;
			cur += sum[pos + rg / 2 + 1] - sum[pos + 1];	
			cur += sum[pos] - sum[pos - lf / 2];
			if (lf % 2 == 1 && rg % 2 == 1) {
				cur += min(s[pos + rg / 2 + 1] - '0', s[pos - lf / 2 - 1] - '0'); 
			}
			res = max(res, cur);
		}
		cout << res << '\n';
	}
}

















