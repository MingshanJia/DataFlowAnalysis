#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int dp[10005];

void precmp()
{
	for (int i = 1;i < 10005;i++) dp[i] = 1000000;
	for (int i = 0;i < 10005;i++) for (int j = 1;i+j*j < 10005;j++)
		dp[i+j*j] = min(dp[i+j*j], dp[i]+1);
}

int solve()
{
	int n; scanf("%d", &n); return dp[n];
}

int main()
{
	precmp();
	int t; scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		fprintf(stderr, "\tCase #% 3d...", _); fflush(stdout);
		milliseconds start_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

		printf("Case #%d: %d\n", _, solve());

		milliseconds end_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		long long time_used = end_ti.count() - start_ti.count();
		fprintf(stderr, " done\t% 6lldms\n", time_used); fflush(stdout);
	}
	fprintf(stderr, "\n\n\n");
	return 0;
}
