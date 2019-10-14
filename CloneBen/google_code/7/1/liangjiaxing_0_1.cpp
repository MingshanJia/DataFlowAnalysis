#include <stdio.h>
#include <string.h>

const int MAXN = 1010;

int a[MAXN][MAXN];
int d[MAXN][MAXN];

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

int n, m, ans;

bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

int dfs(int x, int y) {
	if (d[x][y] > 0) return d[x][y];
	d[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int xx, yy;
		xx = x + dx[i];
		yy = y + dy[i];
		if (!valid(xx, yy)) continue;
		if (a[xx][yy] == a[x][y] + 1) {
			d[x][y] = dfs(xx, yy) + 1;
		}
	}
	if (d[x][y] > ans || (d[x][y] == ans && a[x][y] < m)) {
		ans = d[x][y];
		m = a[x][y];
	}
	return d[x][y];
}

int main() {
	int cas;
	scanf("%d" , &cas);
	for (int re = 1; re <= cas; re++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		memset(d, 0, sizeof(d));
		ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][j] == 0) dfs(i, j);
			}
		}
		printf("Case #%d: %d %d\n", re, m, ans);
	}
}