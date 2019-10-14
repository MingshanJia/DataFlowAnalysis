#include <cstdio>

int T;

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	scanf("%d", &T);
	for (int Cas = 1; Cas <= T; ++Cas) {
		int minX = 1000, maxX = -1000;
		for (int i = 0; i < 3; ++i) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			if (x < minX) minX = x;
			if (x > maxX) maxX = x;
		}
		printf("Case #%d: %.10lf\n", Cas, (maxX - minX) / 6.);
	}
	return 0;
}
