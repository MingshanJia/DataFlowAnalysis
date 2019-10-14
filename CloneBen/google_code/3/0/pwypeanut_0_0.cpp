#include <bits/stdc++.h>
using namespace std;

int T, dp[305];
string S;

bool same(int a, int b, int x, int y) {
	for (int i = 0; i < y - x; i++) if (S[a + i] != S[x + i]) return 0;
	return 1;
}

bool found(int a, int b, int x, int y) {
	for (int i = a; i < b; i++) {
		if (i + (y - x) <= b) {
			if (same(i, i + y - x, x, y)) return 1;
		} else break;
	}
	return 0;
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		cin >> S;
		memset(dp, 63, sizeof(dp));
		dp[0] = 0;
		for (int i = 1; i <= S.length(); i++) {
			dp[i] = min(dp[i], dp[i - 1] + 1);
			
			for (int j = 1; j < i; j++) {
				if (i-j <= 0) continue;
				int potate[i-j+1];
				memset(potate, -63, sizeof(potate));
				potate[0] = 1;
				//printf("j = %d\n", j);
				if (found(0, i-j, i-j, i)) dp[i] = min(dp[i], 2 + dp[i-j]);
				for (int k = 1; k <= i-j; k++) {
					potate[k] = potate[k-1];
					
					if (k-j >= 0 && same(i-j-k, i-k, i-j, i)) potate[k] = max(potate[k], 1 + potate[k-j]);
					if (potate[k] < -1000000000) continue;
					//printf("potate[%d] = %d %d\n", k, potate[k], same(i-j-k, i-k, i-j, i));
					if (found(0, i-j-k, i-j, i)) dp[i] = min(dp[i], dp[i-j-k] + 1 + potate[k] + (j + k - j * potate[k]));
					//else break;
				}
			}
		//printf("dp[%d] = %d\n", i, dp[i]);
		}
		printf("Case #%d: %d\n", tc, dp[S.length()]);
	}
}
