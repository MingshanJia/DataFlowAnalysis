#include <cstdio>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct peep_s
{
	int pos;
	int weight;
};

struct vert_s
{
	vert_s() : max_cost(0LL) { }
	vector<pair<int, int> > adj;
	long long max_cost;
};

int N, peepN;
vector<vert_s> verts;
vector<peep_s> peeps;

void go(int pos, int weight)
{
	vector<bool> did(N);
	vector<long long> cost(N, 0x7FFFFFFFFFFFFFFFLL);
	cost[pos] = 0;

	priority_queue< pair<long long, int>, vector< pair<long long, int> >, greater< pair<long long, int> > > pque;

	pque.push(make_pair(0, pos));

	for (;!pque.empty();)
	{
		pair<long long, int> ci = pque.top(); pque.pop();
		int pos = ci.second;
		if (did[pos])
			continue;
		did[pos] = true;

		vector< pair<int, int> > &adj = verts[pos].adj;
		for (int i = 0;i < adj.size();i++)
		{
			if (cost[adj[i].first] > ci.first + adj[i].second)
			{
				cost[adj[i].first] = ci.first + adj[i].second;
				pque.push(make_pair(cost[adj[i].first], adj[i].first));
			}
		}
	}

	for (int i = 0;i < N;i++)
	{
		long long eff;
		if (cost[i] >= (0x80000000LL + weight - 1) / weight)
			eff = 0x80000000LL;
		else
			eff = cost[i] * weight;
		verts[i].max_cost = max(verts[i].max_cost, eff);
	}
}

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int ti = 1;ti <= tc;ti++)
	{
		int roadN;
		scanf("%d %d %d", &N, &peepN, &roadN);

		peeps = vector<peep_s>(peepN);
		verts = vector<vert_s>(N);

		for (int i = 0;i < peepN;i++)
		{
			scanf("%d %d", &peeps[i].pos, &peeps[i].weight);
			peeps[i].pos--;
		}

		for (int i = 0;i < roadN;i++)
		{
			int weight;
			int ptN;
			int prev, cur;
			scanf("%d %d", &weight, &ptN);
			for (int i = 0;i < ptN;i++)
			{
				scanf("%d", &cur);
				cur--;
				if (i)
				{
					verts[prev].adj.push_back(make_pair(cur, weight));
					verts[cur].adj.push_back(make_pair(prev, weight));
				}
				prev = cur;
			}
		}

		for (int i = 0;i < peepN;i++)
			go(peeps[i].pos, peeps[i].weight);

		long long ans = 0x80000000LL;
		for (int i = 0;i < N;i++)
			if (ans > verts[i].max_cost)
				ans = verts[i].max_cost;

		if (ans == 0x80000000LL)
			ans = -1;
		printf("Case #%d: %lld\n", ti, ans);
	}
	return 0;
}
