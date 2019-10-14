#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define UNDEF 0x7FFFFFFFFFFFFFFFLL

const int nn = 3;
const int n = 8;
long long m;
long long c1[10], c2[10];
long long cost[10][10];

struct _edge {
	int x;
	long long u, c;
	bool reversed;
	_edge *rev;

	long long original_u, original_c;

	_edge() {}
	_edge(int x, long long u, long long c, bool reversed) : x(x), u(u), c(c), original_c(c), original_u(u), reversed(reversed), rev(NULL) {}
};

vector<_edge*> edge[10];
inline void makeedge(int x, int y, long long u, long long c)
{
	_edge *p = new _edge(y, u, c, false), *q = new _edge(x, 0, 0, true);
	p->rev = q, q->rev = p;
	edge[x].push_back(p), edge[y].push_back(q);
}


long long potential[10];

void reduce_cost()
{
	int i, j;

	for (i=0; i<n; i++) for (j=0; j<edge[i].size(); j++) {
		_edge *e = edge[i][j];
		int x = i, y = e->x;
		if (e->u > 0) e->c += potential[x] - potential[y];
		else e->c = 0;
	}
}

void bellman_ford()
{
	int i, j, k;

	fill(potential, potential+n, UNDEF);
	potential[0] = 0;

	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) for (k=0; k<edge[j].size(); k++) {
			_edge *e = edge[j][k];
			int x = j, y = e->x;
			if (e->u > 0 && potential[x] != UNDEF && (potential[y] == UNDEF || potential[y] > potential[x] + e->c))
				potential[y] = potential[x] + e->c;
		}
	}
}

int back[10];
_edge *backedge[10];
bool check[10];
void dijkstra()
{
	memset(check, 0, sizeof(check));
	fill(potential, potential+n, UNDEF);
	potential[0] = 0;

	int i;
	while (true) {
		long long mindist = UNDEF, x;
		for (i=0; i<n; i++) if (!check[i] && potential[i] != UNDEF && (mindist == UNDEF || mindist > potential[i]))
			mindist = potential[i], x = i;

		if (mindist == UNDEF) break;
		check[x] = true;

		for (i=0; i<edge[x].size(); i++) {
			_edge *e = edge[x][i];
			int y = e->x;

			if (e->u &&	!check[y] && (potential[y] == UNDEF || potential[y] > potential[x] + e->c))
				potential[y] = potential[x] + e->c, back[y] = x, backedge[y] = e;
		}
	}
}

void flow()
{
	int x, y;
	_edge *e;
	long long f = UNDEF;

	x = n-1;
	while (x) {
		y = back[x], e = backedge[x];

		if (f==UNDEF || f > e->u)
			f = e->u;

		x = y;
	}

	x = n-1;
	while (x) {
		y = back[x], e = backedge[x];

		e->u -= f;
		if (!e->rev->u) e->rev->c = 0;
		e->rev->u += f;

		x = y;
	}
}

long long mincost_maxflow()
{
	bellman_ford();
	reduce_cost();

	while (true) {
		dijkstra();
		if (potential[n-1] == UNDEF) break;

		reduce_cost();
		flow();
	}

	int i, j;
	long long c = 0;
	for (i=0; i<n; i++) for (j=0; j<edge[i].size(); j++) {
		_edge *e = edge[i][j];
		if (!e->reversed)
			c += (edge[i][j]->original_u - edge[i][j]->u) * edge[i][j]->original_c;
	}

	return c;
}

int main()
{
	int i, j;

	int t, tt=0;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &m);
		for (i=0; i<nn; i++) scanf("%lld", &c1[i]);
		for (i=0; i<nn; i++) scanf("%lld", &c2[i]);
		for (i=0; i<nn; i++) for (j=0; j<nn; j++) scanf("%lld", &cost[i][j]);

		for (i=0; i<n; i++) edge[i].clear();

		for (i=0; i<nn; i++) makeedge(0, i+1, c1[i], 0);
		for (i=0; i<nn; i++) for (j=0; j<nn; j++) makeedge(i+1, nn+j+1, max(c1[i], c2[j]), -cost[i][j]);
		for (i=0; i<nn; i++) makeedge(nn+i+1, nn+nn+1, c2[i], 0);

		printf("Case #%d: %lld\n", ++tt, -mincost_maxflow());
	}

	return 0;
}
