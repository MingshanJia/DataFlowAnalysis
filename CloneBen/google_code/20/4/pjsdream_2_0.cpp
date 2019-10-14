#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>
#include <memory.h>
using namespace std;

struct _heap {
	int x;
	long long d;
	_heap() {}
	_heap(int x, long long d) : x(x), d(d) {}

	inline bool operator < (const _heap &rhs) const { return d > rhs.d; }
};

int n, p, m;
int x[10010];
long long v[10010];
vector<pair<int, long long> > edge[10010];

long long dist[100][100010];

inline void make_edge(int x, int y, long long d) { edge[x].push_back(make_pair(y, d)); edge[y].push_back(make_pair(x, d)); }

bool check[10010];
priority_queue<_heap> heap;

inline void heap_push(int i, int x, long long d) { heap.push (_heap(x, d)) ; dist[i][x] = d;}

void dijkstra(int i)
{
	memset(check, 0, sizeof(check));
	memset(dist[i], -1, sizeof(dist[i]));
	while (!heap.empty()) heap.pop();

	heap_push(i, x[i], 0);

	int x;
	long long d;
	while (!heap.empty()) {
		x = heap.top().x;
		d = heap.top().d;
		heap.pop();

		if (check[x]) continue;
		check[x] = true;

		for (int j=0; j<edge[x].size(); j++) {
			int y = edge[x][j].first;
			if (!check[y] && (dist[i][y]==-1 || dist[i][y] > d + edge[x][j].second))
				heap_push(i, y, d + edge[x][j].second);
		}
	}
}

int main()
{
	int i, j;

	int t, tt=0;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d %d", &n, &p, &m);
		for (i=0; i<n; i++) edge[i].clear();

		for (i=0; i<p; i++) {
			scanf("%d %lld", &x[i], &v[i]); x[i]--;
		}

		for (i=0; i<m; i++) {
			long long d;
			int l;
			scanf("%lld %d", &d, &l);

			int x, y;
			for (j=0; j<l; j++) {
				scanf("%d", &x); x--;
				if (j) make_edge(x, y, d);
				y = x;
			}
		}


		for (i=0; i<p; i++) {
			dijkstra(i);
		}

		long long answer = -1;
		for (i=0; i<n; i++) {
			long long sum = 0;
			for (j=0; j<p; j++) {
				if (dist[j][i] == -1) break;
				if (sum < v[j] * dist[j][i])
					sum = v[j] * dist[j][i];
			}
			if (j<p) continue;

			if (answer==-1 || answer > sum)
				answer = sum;
		}

		printf("Case #%d: %lld\n", ++tt, answer);
	}

	return 0;
}
