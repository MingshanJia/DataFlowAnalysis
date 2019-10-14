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

int a[2001][2001];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	/*a[1][0] = 1;
	a[0][1] = 2;
	For(sum, 2, 2000) For(i, 0, sum) {
		int j = sum-i;
		a[i][j] = 0;
		if (i >= 2)
			a[i][j] |= a[i-1][j];
		if (j >= 2)
			a[i][j] |= a[i+1][j-2];
		if (i >= 1 && j >= 1)
			a[i][j] |= a[i-1][j];
	}
	For(i, 0, 100) {
		For(j, 0, 100)
			printf(a[i][j] == 1 ? "W" : a[i][j] == 2 ? "B" : a[i][j] == 3 ? "U" : " ");
		printf("\n");
	}*/

	int t;
	scanf("%d", &t);
	For(test, 1, t) {
		int w, b;
		scanf("%d%d", &w, &b);
		printf("Case #%d: %s\n", test, b%2 == 0 ? "WHITE" : "BLACK");
	}

	exit(0);
}
