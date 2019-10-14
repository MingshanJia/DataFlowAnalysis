#include <cstdio>
#include <cstring>

const int MAXN = 405;
double f[MAXN][MAXN][MAXN];
void doit()
{
	int b, l, n;
	scanf("%d%d%d", &b, &l, &n);
	// memset(f, 0, sizeof(f));
	for(int i = 1; i <= l; i++)
		for(int j = 1; j <= i; j++)
			for(int k = 1; k <= j; k++)
				f[i][j][k] = 0;
	f[1][1][1] = b * 3;
	for(int i = 1; i <= l; i++)
		for(int j = 1; j <= i; j++)
			for(int k = 1; k <= j; k++)
				if(f[i][j][k] > 1)
				{
					double t = f[i][j][k] - 1;
					f[i][j][k] = 1;
					f[i + 1][j][k] += t / 3;
					f[i + 1][j + 1][k] += t / 3;
					f[i + 1][j + 1][k + 1] = t / 3;
				}
	int k = 0;
	for (int i = 1; i <= l; i++)
		for (int j = 1; j <= i; j++)
		{
			k++;
			if (k == n)
			{
				printf("%.7lf\n", 250 * f[l][i][j]);
				return;
			}
		}
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		printf("Case #%d: ", i);
		doit();
	}
	return 0;
}