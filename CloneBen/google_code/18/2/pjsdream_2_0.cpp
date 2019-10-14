#include <memory.h>
#include <stdio.h>
#include <vector>
using namespace std;

int n, m, K;
char map[60][60][60];

int cnt;
int num[60][60][60];
bool check[60][60][60];

int kroom[60], kroom_sum[60];

inline bool range(int l, int r, int x) { return l<=x && x<r; }
void flood_fill(int i, int j, int k) {
	check[i][j][k] = true;
	num[i][j][k] = cnt;
	if (range(0, n, j-1) && !check[i][j-1][k] && map[i][j-1][k]=='.') flood_fill(i, j-1, k);
	if (range(0, n, j+1) && !check[i][j+1][k] && map[i][j+1][k]=='.') flood_fill(i, j+1, k);
	if (range(0, m, k-1) && !check[i][j][k-1] && map[i][j][k-1]=='.') flood_fill(i, j, k-1);
	if (range(0, m, k+1) && !check[i][j][k+1] && map[i][j][k+1]=='.') flood_fill(i, j, k+1);
}

vector<int> edge[10010];
inline void makeedge(int x, int y)
{
	edge[x].push_back(y);
}

int dynamic[60][1048576/8];
bool avail[20000];
int main()
{
	int i, j, k;
	int t, tt=0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &K);
		for (i=0; i<K; i++) for (j=0; j<n; j++) scanf("%s", map[i][j]);

		cnt = 0;
		memset(check, 0, sizeof(check));
		memset(kroom, 0, sizeof(kroom));
		for (i=0; i<K; i++) for (j=0; j<n; j++) for (k=0; k<m; k++) if (map[i][j][k] == '.' && !check[i][j][k]) {
			flood_fill(i, j, k);
			cnt++;
			kroom[i]++;
		}

		for (i=0; i<cnt; i++) edge[i].clear();
		for (k=0; k<K; k++) {
			for (i=0; i<n; i++) for (j=0; j<m; j++) if (map[k][i][j] == '.') {
				if (range(0, K, k+1) && map[k+1][i][j]=='.') makeedge(num[k][i][j], num[k+1][i][j]);
			}
		}

		for (k=1; k<K; k++) kroom_sum[k] = kroom_sum[k-1] + kroom[k-1];

		memset(dynamic, 0, sizeof(dynamic));
		for (k=0; k<K; k++) {
			for (i=0; i<(1<<kroom[k]); i++) {
				int ch = 0;
				int cnt = 0;
				for (j=0; j<kroom[k]; j++) if (i & (1<<j)) {
					cnt++;
					for (int a=0; a<edge[kroom_sum[k] + j].size(); a++)
						ch |= 1 << (edge[kroom_sum[k] + j][a] - kroom_sum[k] - kroom[k]);
				}

				for (j=0; j<(1<<kroom[k+1]); j++) {
					if ((ch & j) == 0)
						dynamic[k+1][j] = max(dynamic[k+1][j], dynamic[k][i] + cnt);
				}
			}
		}

		printf("Case #%d: %d\n", ++tt, dynamic[K][0]);
	}

	return 0;
}
