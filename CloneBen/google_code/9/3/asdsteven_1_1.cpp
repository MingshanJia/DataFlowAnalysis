#include <cstdio>

double cup[402][402][2];

double solve() {
	int B, L, N;
	scanf("%d%d%d", &B, &L, &N);
	for (int i = 1; i <= L; i++)
		for (int j = 1; j <= i; j++)
			cup[i][j][0] = cup[i][j][1] = 0;
	int f = 0;
	cup[1][1][f] = B * 750.0;
	for (int i = 1; i <= L; i++, f ^= 1) {
		for (int j = 1; j <= L; j++){
			for (int k = 1; k <= j; k++) {
				cup[j][k][!f] = 0;
			}
		}
		for (int j = 1; j <= i; j++)
			for (int k = 1; k <= j; k++)
				if (cup[j][k][f] > 250) {
					double d = (cup[j][k][f] - 250) / 3.0;
					cup[j][k][f] = 250;
					cup[j][k][!f] += d;
					cup[j + 1][k][!f] += d;
					cup[j + 1][k + 1][!f] += d;
				}
	}
	for (int i = 1, k = 1; i <= L; i++)
		for (int j = 1; j <= i; j++, k++)
		if (k == N) {
			return cup[i][j][!f];
		}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
		printf("Case #%d: %.7f\n", i, solve());
}