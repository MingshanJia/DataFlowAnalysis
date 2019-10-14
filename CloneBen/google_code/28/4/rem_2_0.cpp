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

const int mod = 9901;
const int rev2 = 4951;

int n, k;
bool can[10][10];
int memo[1<<10][10];

int solve(int mask, int last) {
	int& res = memo[mask][last];
	if (res == -1) {
		mask ^= 1<<last;
		if (mask == 0) {
			res = int(last == 0);
		} else {
			res = 0;
			Rep(i, n) if (mask&(1<<i)) {
				if (can[i][last])
					res = (res+solve(mask, i))%mod;
			}
		}
	}
	return res;
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
		Rep(i, n) Rep(j, n)
			can[i][j] = i != j;
		Rep(i, k) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			can[x][y] = can[y][x] = false;
		}
		Fill(memo, -1);
		int res = 0;
		Rep(i, n) 
			if (can[i][0])
				res = (res+solve((1<<n)-1, i))%mod;
		res = res*rev2%mod;
		printf("Case #%d: %d\n", test, (res+mod)%mod);
	}

	exit(0);
}
