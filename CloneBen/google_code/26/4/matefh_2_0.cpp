#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define FOR(i,n) for(int i = 0 ; i < n ; i++)
#define FORL(i,i0,n) for(int i = i0 ; i < n ; i++)
#define FORIT(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define ALL(x) x.begin(), x.end()
#define SZ(x) int(x.size())
#define LEN(x) int(x.length())
#define PB push_back
#define MP make_pair
#define FST(x) (x).first
#define SEC(x) (x).second
#define LL long long
#define mem(x, n) memset(x, n, sizeof(x))
#define ni() ({int t;scanf("%d",&t);t;})
#define SRAND() srand(time(NULL))
#define RAND(mod, offset) ((rand() % (mod)) + (offset))
#if 1
#define DBG(z) cerr << #z << ": " << (z) << endl
#else
#define DBG(z)
#endif
using namespace std;

char g[100][100];
int sum[100][100];

int obstacle(int i, int j) {
	return g[i][j] == 'T' || g[i][j] == 'W' || g[i][j] == 'R';
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int t = ni();
	int kase = 1;
	while (t--) {
		int C = ni();
		int R = ni();

		FOR(i, R)
			scanf("%s", g[i]);
		mem(sum, 0);
		FOR(i, R) {
			FOR(j, C) {
				sum[i][j] = obstacle(i, j);
				if (i > 0)
					sum[i][j] += sum[i - 1][j];
				if (j > 0)
					sum[i][j] += sum[i][j - 1];
				if (i > 0 && j > 0)
					sum[i][j] -= sum[i - 1][j - 1];
			}
		}
		int ans = 0;
		FOR(i, R) {
			FOR(j, C) {
				FORL(x, i, R) {
					FORL(y, j, C) {
						int z = sum[x][y];
						if (i > 0)
							z -= sum[i - 1][y];
						if (j > 0)
							z -= sum[x][j - 1];
						if (i > 0 && j > 0)
							z += sum[i - 1][j - 1];

						if (z == 0)
							ans = max(ans, (x - i + 1) * (y - j + 1));
					}
				}
			}
		}

		printf("Case #%d: %d\n", kase++, ans);
	}
}

