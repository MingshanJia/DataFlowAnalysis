#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int ADD = 1200000;

const int MX = 2500000;

typedef long long LL;

int n;

int t[MX + 5];

int s[MX + 5], ss;

int curHole;

LL sum(int n) {
	return (LL(n) * (n + 1)) / 2;
}

LL countMoves(int dist, int cMoves) {
	return sum(dist) - sum(dist - cMoves);
}


void alg() {
	memset(t, 0, sizeof(t));
	LL res = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x, c;
		scanf("%d %d", &x, &c);
		t[x + ADD] += c;
	}
	for (int x = 1; x <= MX; ++x) {
		while (t[x] > 1) {
			t[x] -= 2;
			++res;
			++t[x - 1];
			++t[x + 1];
			if (t[x - 1] > 1) {
				x -= 2;
				continue;
			}
		}
	}
	for (int i = 1; i <= MX; ++i)
		if (t[i] > 1)
			printf("AAAA\n");
	printf("%lld\n", res);
}

int main() {
	int d;
	scanf("%d", &d);
	for (int caseNo = 1; caseNo <= d; ++caseNo) {
		printf("Case #%d: ", caseNo);
		alg();
	}
}
