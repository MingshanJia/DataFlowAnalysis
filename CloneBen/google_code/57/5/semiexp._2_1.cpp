#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
typedef long long i64;

int W, H, B;
int X0[1010], Y0[1010], X1[1010], Y1[1010];

int dist[1010][1010];
int dij[1010];
bool vis[1010];

int rg(int a, int b, int c, int d)
{
	if(b < c) return c - b;
	if(d < a) return a - d;
	return 0;
}

int main()
{
	int T;
	scanf("%d", &T);

	for(int t = 0; t++ < T; ) {
		scanf("%d%d%d", &W, &H, &B);

		for(int i = 0; i < B; i++) {
			scanf("%d%d%d%d", X0+i, Y0+i, X1+i, Y1+i);

			++X1[i];
			++Y1[i];
		}

		for(int i = 0; i < B; i++) {
			for(int j = 0; j < B; j++) {
				if(i == j) dist[i][j] = 0;
				else {
					dist[i][j] = max(rg(X0[i], X1[i], X0[j], X1[j]), rg(Y0[i], Y1[i], Y0[j], Y1[j]));
				}
			}
		}

		for(int i = 0; i < B; i++) {
			dij[i] = X0[i];
			vis[i] = false;
		}

		for(int i = 0; i < B; i++) {
			int bp = -1;
			for(int j = 0; j < B; j++) {
				if(!vis[j] && (bp == -1 || dij[bp] > dij[j])) bp = j;
			}

			vis[bp] = true;
			for(int j = 0; j < B; j++) dij[j] = min(dij[j], dij[bp] + dist[bp][j]);
		}

		int ret = W;
		for(int i = 0; i < B; i++) ret = min(ret, dij[i] + (W - X1[i]));

		//printf("%d %d\n", s, d);
		printf("Case #%d: %d\n", t, ret);
		fprintf(stderr, "%d\n", t);
	}

	return 0;
}
