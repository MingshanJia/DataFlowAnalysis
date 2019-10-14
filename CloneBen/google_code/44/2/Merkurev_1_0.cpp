#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = 205;
double p[N];
double a[N];
double dp[N][N];

double test(int n, int l, int r)
{
	int sz = 0;
	for (int i = 0; i < l; i++)
		a[sz++] = p[i];
	for (int i = n - r; i < n; i++)
		a[sz++] = p[i];
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for (int i = 0; i < sz; i++)
		for (int j = 0; j <= i; j++)
		{
			dp[i + 1][j] += dp[i][j] * a[i];
			dp[i + 1][j + 1] += dp[i][j] * (1. - a[i] );
		}
	return dp[sz][sz / 2];
}

void solve()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%lf", &p[i] );
	sort(p, p + n);
	double ans = 0;
	for (int l = 0; l <= k; l++)
	{
		int r = k - l;
		ans = max(ans, test(n, l, r) );
	}
	printf("%.10lf\n", ans);
}

void multitest()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("Case #%d: ", i);
		eprintf("Case #%d .. %d\n", i, n);
		solve();
	}


}

int main(int argc, char **)
{
	if (argc == 1)
		multitest();
	else
		solve();

	return 0;
}


