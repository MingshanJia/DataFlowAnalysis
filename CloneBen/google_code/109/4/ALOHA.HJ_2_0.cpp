#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#define mod 1000000007
using namespace std;
long long t, c,v,l, dp[2][600];
int main()
{
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("cs.out", "w", stdout);
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		printf("Case #%d: ", tt);
		scanf("%lld%lld%lld", &c, &v, &l);
		dp[0][1] = c;
		dp[1][1] = v;
		for (int i = 2; i <= l; i++)
		{
			dp[0][i] = (dp[1][i - 1] * c) % mod;
			dp[1][i] = ((dp[0][i-1]+dp[1][i - 1]) * v) % mod;
		}
		printf("%lld\n", dp[1][l]);
	}
return 0;
}