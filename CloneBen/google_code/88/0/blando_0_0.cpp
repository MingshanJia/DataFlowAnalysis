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

const int max_n = 64;

char a[max_n][max_n], b[max_n][max_n];
int n, k;
int T, I;

void input() {
	scanf("%d %d", &n, &k);
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			scanf(" %c ", &a[x][y]);
		}
	}
}

void rotate() {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			b[y][n - 1 - x] = a[x][y];
		}
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++)
			a[x][y] = b[x][y];
	}
}

void gravity() {
	for (int y = 0; y < n; y++) {
		int x1 = n - 1;
		for (int x = n - 1; x >= 0; x--) {
			if (x1 < 0) {
				a[x][y] = '.';
				continue;
			}
			while (x1 >= 0 && a[x1][y] == '.')
				x1--;
			if (x1 >= 0) {
				assert(x1 <= x);
				a[x][y] = a[x1][y];
				x1--;
			} else
				a[x][y] = '.';
		}
	}
}

void solve() {
	rotate();
	gravity();
}

bool test(int sx, int sy, int dx, int dy, char ch) {
	int ex = sx + dx * (k - 1), ey = sy + dy * (k - 1);
	if (ex < 0 || ex >= n || ey < 0 || ey >= n)
		return false;
	int x = sx, y = sy;
	for (int i = 0; i < k; i++) {
		if (a[x][y] != ch)
			return false;
		x += dx; y += dy;
	}
	return true;
}

bool join(char ch) {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (a[x][y] != ch)
				continue;
			if (test(x, y, 0, 1, ch) || test(x, y, 1, 0, ch) ||
					test(x, y, 1, 1, ch) || test(x, y, 1, -1, ch))
				return true;
		}
	}
	return false;
}

void output() {
	bool red = join('R'), blue = join('B');
	printf("Case #%d: ", I + 1);
	if (red) {
		if (blue)
			printf("Both\n");
		else
			printf("Red\n");
	} else {
		if (blue)
			printf("Blue\n");
		else
			printf("Neither\n");
	}
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

