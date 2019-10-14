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

const int max_n = 1024 * 1024;

long long ans;
int A1, A2, B1, B2;
int T, I;
int c[max_n];

void input() {
	scanf("%d %d %d %d", &A1, &A2, &B1, &B2);
}

int my_floor(Real a) {
	if (abs(a - (int)(a + 0.5)) <= o)
		return (int)(a + 0.5);
	return (int)(floor(a) + 0.5);
}

void init() {
	for (int i = 1; i < max_n; i++) {
		c[i] = my_floor((sqrt((Real)5.0) - 1) * i / 2);
	}
}

void solve() {
	ans = (long long)(A2 - A1 + 1) * (B2 - B1 + 1);
	for (int A = A1; A <= A2; A++) {
		int low = c[A] + 1;
		int high = (lower_bound(c, c + max_n, A) - c) - 1;
		low = max(low, B1);
		high = min(high, B2);
		// fprintf(stderr, "%d (%d %d)\n", A, low, high);
		if (low <= high)
			ans -= (high - low + 1);
	}
}

void output() {
	printf("Case #%d: %lld\n", I + 1, ans);
	fprintf(stderr, "Case #%d: %lld\n", I + 1, ans);
}

int main() {
	init();
	scanf("%d", &T);
	for (I = 0; I < T; ++I) {
		input();
		solve();
		output();
	}
	return 0;
}

