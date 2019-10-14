#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 1010;
int dp[MAX_N][MAX_N];
int a[MAX_N][MAX_N], n;
int fx[4][2] = {
	{1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

pair<int, int> ans;

int ok(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

int gao(int x, int y) {
	if (dp[x][y]) {
		return dp[x][y];
	}
	for (int i = 0; i < 4; i++) {
		int tx = fx[i][0] + x;
		int ty = fx[i][1] + y;
		if (ok(tx, ty) && a[tx][ty] == a[x][y] + 1) {
			return dp[x][y] = gao(tx, ty) + 1;
		}
	}
	return dp[x][y] = 1;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
				dp[i][j] = 0;
			}
		}
		ans = make_pair(1, 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans = min(ans, make_pair(-gao(i, j), a[i][j]));
			}
		}
		printf("Case #%d: %d %d\n", ca, ans.second, -ans.first);
	}
	return 0;
}
