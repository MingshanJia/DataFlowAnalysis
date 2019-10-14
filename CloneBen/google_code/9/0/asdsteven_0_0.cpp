#include <cstdio>

long long MOD = 1000000007;
long long dp[101][101];
long long fac[101], caf[101];

long long inv(long long x) {
	int y = MOD - 2;
	int i = 1;
	while (i + i <= y)
		i += i;
	long long ans = 1;
	while (i) {
		ans = ans * ans % MOD;
		if (y & i)
			ans = ans * x % MOD;
		i >>= 1;
	}
	return ans;
}

int solve() {
	int M, N;
	scanf("%d%d", &M, &N);
	return dp[M][N] * fac[N] % MOD;
}

int main() {
	fac[0] = 1;
	for (int i = 1; i <= 100; i++) {
		fac[i] = i * fac[i - 1] % MOD;
		caf[i] = inv(fac[i]);
	}
	for (int i = 1; i <= 100; i++)
		dp[1][i] = caf[i];
	for (int j = 1; j <= 100; j++)
	for (int i = 2; i <= j; i++)
	for (int k = 1; k <= j - i + 1; k++)
		dp[i][j] = (dp[i][j] + dp[i - 1][j - k] * caf[k]) % MOD;
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
		printf("Case #%d: %d\n", i, solve());
}