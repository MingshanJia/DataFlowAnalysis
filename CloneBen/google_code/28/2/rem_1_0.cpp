#define _CRT_SECURE_NO_WARNINGS
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;

template<typename T> inline T sqr(T a) { return a*a; }
template<typename T> inline int Size(const T& c) { return (int)c.size(); }

#define For(i, a, b) for (int i = int(a), _b = int(b); i <= _b; ++i)
#define Ford(i, a, b) for (int i = int(a), _b = int(b); i >= _b; --i)
#define Rep(i, n) for (int i = 0, _n = int(n); i < _n; ++i)
#define Repd(i, n) for (int i = int(n)-1; i >= 0; --i)
#define Fill(a, c) memset(&a, c, sizeof(a))
#define MP(x, y) make_pair(x, y)
#define All(v) (v).begin(), (v).end()

int n, k;
int x[15], y[15];
int dp[1<<15];

int solve(int len) {
	dp[0] = 0;
	For(mask, 1, (1<<n)-1) {
		dp[mask] = n;
		Rep(i1, n) if (mask&(1<<i1)) {
			Rep(i2, n) if (mask&(1<<i2)) {
				Rep(z1, 2) {
					int sx = z1 ? x[i1] : x[i1]-len;
					Rep(z2, 2) {
						int sy = z2 ? y[i2] : y[i2]-len;
						int newMask = mask;
						Rep(i, n) if (mask&(1<<i))
							if (x[i] >= sx && x[i] <= sx+len && y[i] >= sy && y[i] <= sy+len)
								newMask ^= 1<<i;
						if (newMask != mask)
							dp[mask] = min(dp[mask], 1+dp[newMask]);
					}
				}
			}
		}
	}
	return dp[(1<<n)-1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int t;
	scanf("%d", &t);
	For(test, 1, t) {
		scanf("%d%d", &n, &k);
		Rep(i, n)
			scanf("%d%d", &x[i], &y[i]);
		int l = 0, r = 1;
		while (solve(r) > k) {
			l = r;
			r *= 2;
		}
		while (r-l > 1) {
			int m = (l+r)/2;
			if (solve(m) > k)
				l = m;
			else
				r = m;
		}
		printf("Case #%d: %d\n", test, r);
	}

	exit(0);
}
