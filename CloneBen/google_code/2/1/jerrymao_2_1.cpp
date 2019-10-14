#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

double prob[35][105][105];
double dp[35][105][105];
double dst[105][105];
double fin[105][105];
int n, m, p;

void mrg(int targ, int l1, int l2)
{
	double rdp[105][105], rprob[105][105];
	for (int i = 0;i < n;i++) for (int j = 0;j < n;j++) rdp[i][j] = rprob[i][j] = 0;
	for (int i = 0;i < n;i++) for (int j = 0;j < n;j++) for (int k = 0;k < n;k++)
	{
		rdp[i][j] += (dp[l1][i][k]+dp[l2][k][j])*prob[l1][i][k]*prob[l2][k][j];
		rprob[i][j] += prob[l1][i][k]*prob[l2][k][j];
	}
	for (int i = 0;i < n;i++) for (int j = 0;j < n;j++) if (rprob[i][j] > 1e-15)
		rdp[i][j] /= rprob[i][j];
	for (int i = 0;i < n;i++) for (int j = 0;j < n;j++)
		dp[targ][i][j] = rdp[i][j], prob[targ][i][j] = rprob[i][j];
}

double solve()
{
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0;i < n;i++) for (int j = 0;j < n;j++) dst[i][j] = 10000000;
	for (int i = 0;i < n;i++) dst[i][i] = 0;
	while (m--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a, --b;
		dst[a][b] = min(dst[a][b], (double)c);
		dst[b][a] = min(dst[b][a], (double)c);
	}
	for (int k = 0;k < n;k++) for (int i = 0;i < n;i++) for (int j = 0;j < n;j++)
		dst[i][j] = min(dst[i][j], dst[i][k]+dst[k][j]);

	for (int i = 0;i < n;i++) for (int j = 0;j < n;j++) dp[0][i][j] = dst[i][j]/(prob[0][i][j] = 1./(n-1))/(n-1);
	for (int i = 0;i < n;i++) prob[0][i][i] = 0;
	for (int l = 1;l < 34;l++)
		mrg(l, l-1, l-1);
	for (int i = 0;i < n;i++) for (int j = 0;j < n;j++)
	{
		dp[34][i][j] = dp[__builtin_ctz(p)][i][j];
		prob[34][i][j] = prob[__builtin_ctz(p)][i][j];
	}
	while (p ^= (p&-p)) mrg(34, 34, __builtin_ctz(p));
	double ans = 0;
	for (int i = 0;i < n;i++)
		ans += dp[34][0][i]*prob[34][0][i];
	return ans;
}

int main()
{
	int t; scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		fprintf(stderr, "\tCase #% 3d...", _); fflush(stdout);
		milliseconds start_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

		printf("Case #%d: %.8lf\n", _, solve());

		milliseconds end_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		long long time_used = end_ti.count() - start_ti.count();
		fprintf(stderr, " done\t% 6lldms\n", time_used); fflush(stdout);
	}
	fprintf(stderr, "\n\n\n");
	return 0;
}
