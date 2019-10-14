#include <cstdio>
#include <iostream>

using namespace std;
const int MAXN = 110;
const long long upper = 1000000000000000000LL;
long long f[MAXN][MAXN];

void dp()
{
	int n = 101;
	f[1][0] = f[1][1]= 1;
	for (int i = 2; i <= n; i++)
	{
		f[i][0] = 1;
		for (int j = 1; j < n; j++)
		{
			f[i][j] = f[i][j - 1] + f[i - 1][j];
			if(f[i][j] > upper)
				f[i][j] = upper + 1;	
		}
		f[i][i] = f[i][i - 1];
	}
}

void doit()
{
	int n;
	long long k;
	cin >> n >> k;
	if(f[n][n] < k)
	{
		printf("Doesn't Exist!\n");
		return;
	}

	for (int i = n, j = n; i > 0 || j > 0;)
	{
		if (i == j)
		{
			printf("(");
			j--;
			continue;
		}
		if (j == 0)
		{
			printf(")");
			i--;
			continue;
		}
		// printf("%d\n", k);
		if (f[i][j - 1] >= k)
		{
			printf("(");
			j--;
		}
		else
		{
			printf(")");
			k -= f[i][j - 1];
			i--;
		}
	}
	printf("\n");
}

int main()
{
	int T;
	dp();
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		printf("Case #%d: ", i);
		doit();
	}
	return 0;
}