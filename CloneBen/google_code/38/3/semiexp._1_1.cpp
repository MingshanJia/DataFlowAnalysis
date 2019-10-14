#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int T;
int A[2020], B[2020], V, E;

int vis[2020];
vector<pair<int, int> > graph[2020]; int ign;
void visit(int p, int gid)
{
	if (vis[p] != -1) return;
	vis[p] = gid;
	for (auto e : graph[p]) if (e.second != ign) {
		visit(e.first, gid);
	}
}
int count_cons(int ig = -1)
{
	ign = ig;
	for (int i = 0; i < V; ++i) vis[i] = -1;
	
	int ret = 0;
	for (int i = 0; i < V; ++i) if (vis[i] == -1) {
		visit(i, i);
		++ret;
	}
	return ret;
}
bool has_bridge()
{
	int tot = count_cons();
	for (int i = 0; i < E; ++i) {
		if (count_cons(i) != tot) return true;
	}
	return false;
}

bool edge_used[2020];
vector<pair<int, int> > digraph[2020];
int edge_usage[2020];

bool vis2[2020];
int find_good_point(int p, int cond)
{
	if (vis2[p]) return -1;
	vis2[p] = true;

	if (p == cond) return p;
	else if (cond == -1) {
		for (auto e : graph[p]) {
			if (!edge_used[e.second]) {
				return p;
			}
		}
	}

	for (auto e : digraph[p]) {
		++edge_usage[e.second];
		int tmp = find_good_point(e.first, cond);
		if (tmp != -1) return tmp;
		--edge_usage[e.second];
	}
	return -1;
}

void solve()
{
	count_cons();
	for (int i = 0; i < E; ++i) edge_used[i] = false;

	for (int i = 0; i < V; ++i) if (vis[i] == i) {
		int nedge = 0;
		for (int j = 0; j < V; ++j) if (vis[j] == i) {
			nedge += graph[j].size();
		}
		nedge /= 2;

		int p = i;
		for (;;) {
			bool trans = false;
			for (auto e : graph[p]) {
				if (!edge_used[e.second]) {
					edge_used[e.second] = true;
					++edge_usage[e.second];
					digraph[p].push_back(e);
					p = e.first;
					trans = true;
					--nedge;
					break;
				}
			}
			if (!trans) {
				for (int j = 0; j < V; ++j) vis2[j] = false;
				p = find_good_point(p, (nedge == 0 ? i : -1));
				if (nedge == 0) break;
			}
		}
	}
	for (int i = 0; i < V; ++i) {
		for (auto e : digraph[i]) {
			if (A[e.second] != i) edge_usage[e.second] *= -1;
		}
	}
}

int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;){
		scanf("%d%d", &V, &E);
		for (int i = 0; i < V; ++i) {
			graph[i].clear();
			digraph[i].clear();
		}
		for (int i = 0; i < E; ++i) {
			scanf("%d%d", A + i, B + i);
			--A[i]; --B[i];
			graph[A[i]].push_back({ B[i], i });
			graph[B[i]].push_back({ A[i], i });
			edge_usage[i] = 0;
		}
		if (has_bridge()) {
			printf("Case #%d: IMPOSSIBLE\n", t);
			continue;
		}
		solve();
		printf("Case #%d:", t);
		for (int i = 0; i < E; ++i) printf(" %d", edge_usage[i]);
		puts("");
	}

	return 0;
}
