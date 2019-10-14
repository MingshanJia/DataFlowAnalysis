#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cassert>
#include <queue>
#include <cctype>
using namespace std;

typedef long double Real;

const Real o = 1e-8;
const Real pi = acos(-1.0);

const int max_p = 256;
const int max_n = 128;
const int oo = 0x7fffffff;

int del, ins, M, n;
int a[max_n];
bool s[max_p];
int c[max_n][max_p];
int T, I;

void input() {
	scanf("%d %d %d %d", &del, &ins, &M, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
}

void solve() {
	for (int v = 0; v < max_p; v++)
		c[0][v] = 0;
	for (int i = 1; i <= n; i++) {
		for (int v = 0; v < max_p; v++) {
			c[i][v] = c[i - 1][v] + del;
			for (int v1 = max(v - M, 0); v1 <= min(v + M, max_p - 1); v1++) {
				int tmp = c[i - 1][v1] + abs(v - a[i]);
				assert(tmp >= 0);
				c[i][v] = min(c[i][v], tmp);
			}
		}
		memset(s, 0, sizeof s);
		while (true) {
			int min_c = oo, mv = -1;
			for (int v = 0; v < max_p; v++) {
				if (!s[v] && c[i][v] < min_c) {
					min_c = c[i][v];
					mv = v;
				}
			}
			if (mv == -1)
				break;
			s[mv] = true;
			for (int v1 = max(mv - M, 0); v1 <= min(mv + M, max_p - 1); v1++) {
				c[i][v1] = min(c[i][v1], min_c + ins);
			}
		}
	}
}

void output() {
	int ans = oo;
	for (int v = 0; v < max_p; v++) {
		if (c[n][v] < ans)
			ans = c[n][v];
	}
	printf("Case #%d: %d\n", I + 1, ans);
	fprintf(stderr, "Case #%d: %d\n", I + 1, ans);
}

int main() {
	scanf("%d", &T);
	for (I = 0; I < T; ++I) {
		input();
		solve();
		output();
	}
	return 0;
}

