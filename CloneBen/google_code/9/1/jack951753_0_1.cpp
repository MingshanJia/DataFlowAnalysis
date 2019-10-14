#include <cstdio>
#include <iostream>
const int MAXN = 110;
const int MOD  = 1000000007;
long long f[MAXN][MAXN];
using namespace std;

void doit()
{
	int m, n;
	long long p = 1;
	scanf("%d%d", &m, &n);
	for (int i = 2; i <= m; i++)
	{
		for (int j = i; j <= n; j++)
			f[i][j] = (f[i - 1][j - 1] + f[i][j - 1] * i) % MOD;
		p = (p * i) % MOD;
	}
	cout << (p * f[m][n]) % MOD << endl;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i < MAXN; i++)
		f[1][i] = 1;
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d: ", i + 1);
		doit();
	}
	return 0;
}