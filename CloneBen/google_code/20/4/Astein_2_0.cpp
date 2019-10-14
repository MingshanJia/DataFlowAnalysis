#include <cstdio>
#include <cstring>

using namespace std;

int a[105][105];
int start[105];
int speed[105];

int main() {
	int n, p, m;
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		scanf("%d%d%d", &n, &p, &m);
		memset(a, -1, sizeof(a));
		for (int i = 0; i < p; ++i) {
			scanf("%d%d", &start[i], &speed[i]);
			start[i]--;
		}
		for (int i = 0; i < m; ++i) {
			int dist, numcity;
			scanf("%d%d", &dist, &numcity);
			int last = -1, now;
			for (int j = 0; j < numcity; ++j) {
				scanf("%d", &now);
				now--;
				if (last != -1) {
					if (a[last][now] == -1 || a[last][now] > dist) a[last][now] = dist;
					if (a[now][last] == -1 || a[now][last] > dist) a[now][last] = dist;
				}
				last = now;
			}
		}
		for (int i = 0; i < n; ++i) a[i][i] = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					if (a[j][i] != -1 && a[i][k] != -1) {
						if (a[j][i] + a[i][k] < a[j][k] || a[j][k] == -1) {
							a[j][k] = a[j][i] + a[i][k];
						}
					}
				}
			}
		}
		int ret = 987987987;
		for (int i = 0; i < n; ++i) {
			bool ispos = true;
			int maxtime = -1;
			for (int j = 0; j < p; ++j) {
				if (a[start[j]][i] == -1) ispos = false;
				if (maxtime < a[start[j]][i] * speed[j]) maxtime = a[start[j]][i] * speed[j];
			}
			if (ispos && ret > maxtime) ret = maxtime;
		}
		if (ret == 987987987) ret = -1;
		printf("Case #%d: %d\n", cn, ret);
	}
}

