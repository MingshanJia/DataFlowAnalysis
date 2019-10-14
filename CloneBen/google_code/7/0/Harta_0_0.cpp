#include <bits/stdc++.h>
using namespace std;

#define MAXS 1010
int t, S, arr[MAXS][MAXS], pos[MAXS * MAXS], dp[MAXS * MAXS];

int moveX[] = {-1, 1, 0, 0};
int moveY[] = { 0, 0,-1, 1};

int main() {
	scanf("%d", &t);
	int xx = 1;
	while (t--) {
		scanf("%d", &S);
		pair<int, int> pos[S * S + 1];
		for (int i = 1; i <= S; i++) {
			for (int j = 1; j <= S; j++) {
				scanf("%d", &arr[i][j]);
				pos[arr[i][j]] = {i, j};
			}
		}
		for (int i = S * S; i >= 1; i--) {
			dp[i] = 1;
		}
		int maxi = -1, ans = 1;
		for (int i = S * S; i >= 1; i--) {
			for (int k = 0; k < 4; k++) {
				int nextX = pos[i].first + moveX[k];
				int nextY = pos[i].second + moveY[k];
				if (nextX >= 1 && nextY >= 1 && nextX <= S && nextY <= S) {
					if (arr[nextX][nextY] == i + 1) {
						dp[i] = max(dp[i], dp[arr[nextX][nextY]] + 1);
					}
				}
			}
			if (dp[i] >= maxi) {
				maxi = dp[i];
				ans = i;
			}
		}
		printf("Case #%d: %d %d\n", xx++, ans, maxi);
	}
	return 0;
}
