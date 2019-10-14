#include <cstdio>
#include <vector>
#include <set>
#include <utility>
#include <memory.h>
#include <cstdlib>

using namespace std;

#define NN 8
#define INF 0x3FFFFFFFFFFFFFFFLL


long long cap[NN][NN], cost[NN][NN], flow[NN][NN];
struct vertex_s
{
	vector<int> adj;
	int parent;
	long long dist, pi;

	vertex_s() : pi(0) { }
	void init() {
		parent = -1; dist = INF;
	}
};
vector<vertex_s> vert;
inline long long potential(int st, int ed) {
	return vert[st].dist + vert[st].pi - vert[ed].pi;
}
int find_path(int st, int ed)
{
	set< pair<long long, long long> > que;
	int N = vert.size();
	for (int i = 0;i < N;i++) vert[i].init();
	vert[st].dist = 0;
	que.insert(make_pair(vert[st].dist, st));
	for (;!que.empty();)
	{
		pair<long long, long long> p = *que.begin();
		que.erase(que.begin());
		long long u = p.second;
		for (int i = 0;i < vert[u].adj.size();i++)
		{
			int v = vert[u].adj[i];
			long long pot = potential(u, v);
			long long &d = vert[v].dist;
			if (flow[v][u] && d > pot - cost[v][u])
			{
				que.erase(make_pair(d, v));
				d = pot - cost[v][u];
				vert[v].parent = u;
				que.insert(make_pair(d, v));
			}
			if (flow[u][v] < cap[u][v] && d > pot + cost[u][v])
			{
				que.erase(make_pair(d, v));
				d = pot + cost[u][v];
				vert[v].parent = u;
				que.insert(make_pair(d, v));
			}
		}
	}

	for (int i = 0;i < N;i++)
		if (vert[i].pi < INF)
			vert[i].pi += vert[i].dist;
	return vert[ed].parent != -1;
}
// pair<flow, cost>
pair<long long, long long> mcmf(int n, int st, int ed)
{
	long long total_flow = 0, total_cost = 0;
	vert = vector<vertex_s>(n);
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			if (cap[i][j] || cap[j][i])
				vert[i].adj.push_back(j);
	memset(flow, 0, sizeof(flow));

	for (;find_path(st, ed);) {
		long long bot = INF;
		for (int v = ed, u = vert[v].parent; v != st; u = vert[v = u].parent)
			bot = min(bot, flow[v][u] ? flow[v][u] : (cap[u][v] - flow[u][v]));

		for (int v = ed, u = vert[v].parent; v != st; u = vert[v = u].parent) 
		{
			if (flow[v][u]) {
				flow[v][u] -= bot;
				total_cost -= bot * cost[v][u];
			}
			else {
				flow[u][v] += bot;
				total_cost += bot * cost[u][v];
			}
		}
		total_flow += bot;
	}
	return make_pair(total_flow, total_cost);
}


int main()
{
	int tc;
	scanf("%d", &tc);
	for (int ti = 1;ti <= tc;ti++)
	{
		memset(flow, 0, sizeof(flow));
		memset(cap, 0, sizeof(cap));
		memset(cost, 0, sizeof(cost));

		long long n;
		scanf("%lld", &n);
		scanf("%lld %lld %lld %lld %lld %lld", &cap[0][1], &cap[0][2], &cap[0][3], &cap[4][7], &cap[5][7], &cap[6][7]);
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				long long v;
				scanf("%lld", &v);
				cost[i + 1][j + 4] = -v;
				cap[i + 1][j + 4] = n;
			}
		}

		pair<long long, long long> r = mcmf(8, 0, 7);
		if (r.first != n)
			exit(-1);
		printf("Case #%d: %lld\n", ti, -r.second);
		fprintf(stderr, "Case #%d: %lld\n", ti, -r.second);
	}
	return 0;
}
