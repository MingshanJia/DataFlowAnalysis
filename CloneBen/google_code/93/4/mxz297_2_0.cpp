#include<cstdio>
#include<cstring>
#define INF 0x7fffffff
int f[200][200];
int n, total;
int l[200];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w" , stdout);
	int cases;
	scanf("%d" , &cases);
	for (int ca = 1; ca <= cases; ++ca)
	{
		scanf("%d%d", &total , &n);
		for (int i = 1; i <= n; ++i) scanf("%d" , l + i);
		l[0] = 0;
		l[n + 1] = total + 1;
		memset( f, 0 , sizeof(f));
		for (int len = 2; len <= n + 1; ++len)
			for (int i = 0; i + len <= n + 1; ++i)
			{
				int j = i + len;
				f[i][j] = INF;
				for (int k = i + 1; k < j; ++k)
					if (f[i][k] + f[k][j] + l[j] - l[i] - 2 < f[i][j])
						f[i][j] = f[i][k] + f[k][j] + l[j] - l[i] - 2;
			}
		printf("Case #%d: %d\n", ca , f[0][n + 1]);
	}
}
