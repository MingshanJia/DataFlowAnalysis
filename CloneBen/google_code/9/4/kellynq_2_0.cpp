#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF  = 100000;
const int MAXN = 110;

int f[MAXN], g[MAXN][MAXN];
int a[MAXN];
int T, N, K;

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &N, &K);
		for (int i = 1; i <= N; i++)
			scanf("%d", a + i);
		for (int i = 0; i < MAXN; i++)
			for (int j = 0; j < MAXN; j++)
				g[i][j] = -INF;
		for (int i = 1; i < MAXN; i++)
			g[i][i - 1] = 0;
		for (int i = N; i >= 1; i--)
			for (int j = i + 2; j <= N; j++) {
				for (int k = i + 1; k <= j; k++)
					g[i][j] = max(g[i][j], g[i][k - 1] + g[k][j]);
				if (a[j] - a[i] == K + K)
					for (int k = i + 1; k < j; k++)
						if (a[k] - a[i] == K)
							g[i][j] = max(g[i][j], g[i + 1][k - 1] + g[k + 1][j - 1] + 3);
			}
		f[0] = 0;
		for (int i = 1; i <= N; i++) {
			f[i] = f[i - 1];
			for (int j = 0; j < i; j++)
				f[i] = max(f[i], f[j] + g[j + 1][i]);
		}
		printf("Case #%d: %d\n", t, N - f[N]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
