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

long long ans;
int A1, A2, B1, B2;
int T, I;

void input() {
	scanf("%d %d %d %d", &A1, &A2, &B1, &B2);
}

bool win(int x, int y) {
	if (x == y)
		return false;
	if (x > y)
		swap(x, y);
	if (y - x - x >= 0)
		return true;
	return !win(x, y - x);
}

void solve() {
	ans = 0;
	for (int A = A1; A <= A2; A++) {
		for (int B = B1; B <= B2; B++) {
			if (win(A, B))
				ans++;
#if 0
			else
				fprintf(stderr, "%d %d\n", A, B);
#endif
		}
	}
}

void output() {
	printf("Case #%d: %lld\n", I + 1, ans);
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

