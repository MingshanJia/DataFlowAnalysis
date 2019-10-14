#include <bits/stdc++.h>
using namespace std;

int n, m, e, sr, sc, tr, tc;
int arr[105][105];
vector<pair<int,int>> traps;
int par[10005];
int sum[10005];
int mr[] = {0, 1, 0, -1}, mc[] = {1, 0, -1, 0};
int q[(1 << 15) + 5];
bool vis[(1 << 15) + 5];
int trapid[105][105];

int parOf(int x) {
	return par[x] == x ? x : par[x] = parOf(par[x]);
}

int get(int r, int c) {
	return r * m + c;
}

void merge(int a, int b, int c, int d) {
	int u = get(a, b);
	int v = get(c, d);
	u = parOf(u);
	v = parOf(v);
	if (u==v) return;
	sum[u] += sum[v];
	par[v] = u;
}

int main() {
	int t, no = 0; scanf("%d", &t);
	while (t--) {
		memset(trapid, -1, sizeof(trapid));
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < 10005; ++i) par[i] = i;
		memset(sum, 0, sizeof(sum));
		traps.clear();
		scanf("%d%d%d%d%d%d%d", &n, &m, &e, &sr, &sc, &tr, &tc); --sr, --sc, --tr, --tc;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &arr[i][j]);
				if (arr[i][j] > 0) {
					sum[get(i, j)] = arr[i][j];
				}
				if (arr[i][j] < 0 && arr[i][j] != -100000) {
					trapid[i][j] = traps.size();
					traps.emplace_back(i, j);
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (arr[i][j] < 0) continue;
				if (i && arr[i - 1][j] >= 0) {
					merge(i, j, i - 1, j);
				}
				if (j && arr[i][j - 1] >= 0) {
					merge(i, j, i, j - 1);
				}
			}
		}

		// for (int i = 0; i < n; ++i) {
		// 	for (int j = 0; j < m; ++j) {
		// 		printf("%d ", sum[parOf(get(i, j))]);
		// 	}
		// 	printf("\n");
		// }

		int ans = -1;

		q[0] = 0;
		vis[0] = true;

		for (int qh = 0, qt = 1; qh < qt; ++qh) {
			int bm = q[qh];


			int cur = e;
			unordered_set<int> s;
			s.insert(parOf(get(sr, sc)));
			for (int i = 0; i < traps.size(); ++i) {
				int cr = traps[i].first, cc = traps[i].second;
				if (bm & (1 << i)) {
					cur += arr[cr][cc];
					for (int j = 0; j < 4; ++j) {
						int nr = cr + mr[j], nc = cc + mc[j];
						if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
						if (arr[nr][nc] >= 0) s.insert(parOf(get(nr, nc)));
					}
				}
			}
			for (const int &x : s) {
				cur += sum[x];
				// printf("ada %d\n", x);
			}

			// printf("now %d %d\n", bm, cur);

			if (s.count(parOf(get(tr, tc)))) ans = max(ans, cur);

			for (int i = 0; i < traps.size(); ++i) {
				if (bm & (1 << i)) continue;
				if (vis[bm | (1 << i)]) continue;
				int cr = traps[i].first, cc = traps[i].second;
				if (cur < -arr[cr][cc]) continue;
				bool valid = false;
				// printf("cek %d (%d %d)\n", i, cr, cc);
				for (int j = 0; j < 4; ++j) {
					int nr = cr + mr[j], nc = cc + mc[j];
					if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
					if (arr[nr][nc] >= 0) {
						if (s.count(parOf(get(nr, nc)))) {
							valid = true;
							break;
						}
					} else if (trapid[nr][nc] != -1) {
						if (bm & (1 << trapid[nr][nc])) {
							valid = true;
							break;
						}
					}
				}
				if (!valid) continue;
				q[qt++] = (bm | (1 << i));
				vis[bm | (1 << i)] = true;
			}
		}

		printf("Case #%d: %d\n", ++no, ans);

	}
	return 0;
}