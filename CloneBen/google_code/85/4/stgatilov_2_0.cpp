#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

const int SIZE = 256;
int matr[SIZE][SIZE];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		int r;
		scanf("%d", &r);
		memset(matr, 0, sizeof(matr));
		for (int i = 0; i<r; i++) {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			for (int u = x1; u<=x2; u++)
				for (int v = y1; v<=y2; v++)
					matr[u][v] = 1;
		}

		int cnt;
		for (cnt = 0; ; cnt++) {
			int alive = 0;
			for (int u = 1; u<SIZE; u++)
				for (int v = 1; v<SIZE; v++) {
					alive += (matr[u][v] == 1);
					if (matr[u][v]==1 && matr[u][v-1]<=0 && matr[u-1][v]<=0)
						matr[u][v] = 2;
					if (matr[u][v]==0 && matr[u][v-1]>0 && matr[u-1][v]>0)
						matr[u][v] = -1;
				}
			for (int u = 1; u<SIZE; u++)
				for (int v = 1; v<SIZE; v++) {
					if (matr[u][v] == 2) matr[u][v] = 0;
					if (matr[u][v] == -1) matr[u][v] = 1;
				}
			if (!alive) break;
//			fprintf(stderr, "%d\n", alive);
		}

		printf("Case #%d: %d\n", tt, cnt);
	}
	return 0;
}
