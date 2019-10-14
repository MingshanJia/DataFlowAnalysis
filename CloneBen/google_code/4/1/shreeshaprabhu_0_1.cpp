#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

double dp[2222][2222];

double solve(int n, int m, int N, int M)
{
	if (n == N)
		return 1.0;
	if (dp[n][m] > -0.5)
		return dp[n][m];

	dp[n][m] = 0.0;
	if (m < M)
	{
		if (m + 1 < n)
			dp[n][m] = (double(M - m) / double(N + M - n - m)) * solve(n, m + 1, N, M);
		dp[n][m] += (double(N - n) / double(N + M - n - m)) * solve(n + 1, m, N, M);
	}
	else
	{
		dp[n][m] = 1.0;
	}
	return dp[n][m];
}

int main()
{
	int T, N, M;

	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d%d", &N, &M);
		assert(N > M);
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= N; j++)
				dp[i][j] = -1.0;
		printf("Case #%d: ", t);
		printf("%lf\n", solve(0, 0, N, M));
	}

	return 0;
}