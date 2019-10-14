#include <bits/stdc++.h>
using namespace std;

const int N = 233;
unordered_map<string, int> um;

struct Edge {
	int u, v, next;
	Edge() {}
	Edge(int u, int v, int next) : u(u), v(v), next(next) {}
} e[N];

int tot, eh[N];

void add(int u, int v) {
	e[tot] = Edge(u, v, eh[u]);
	eh[u] = tot++;
}

void addedge(int u, int v) {
	add(u, v);
	add(v, u);
}

int color[N];

void init() {
	tot = 0;
	memset(eh, -1, sizeof eh);
	memset(color, 0, sizeof color);
	um.clear();
}

bool dfs(int u, int cur) {
	if (color[u]) return color[u] == cur;
	else color[u] = cur;
	for (int i = eh[u]; ~i; i = e[i].next) {
		int v = e[i].v;
		if (!dfs(v, 3 - cur)) return 0;
	}
	return 1;
}

int main() {
#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out_small.txt", "w", stdout);
#endif // LOCAL
	int t, m, cot = 0, cas = 0;
	string s1, s2;
	scanf("%d", &t);
	while (t-- && scanf("%d", &m)) {
		init();
		cot = 0;
		for (int i = 0; i < m; ++i) {
			cin >> s1 >> s2;
			if (um.find(s1) == um.end()) {
				um.insert(make_pair(s1, um.size() + 1));
				++cot;
			}
			if (um.find(s2) == um.end()) {
				um.insert(make_pair(s2, um.size() + 1));
				++cot;
			}
			addedge(um[s1], um[s2]);
		}
		bool yes = 1;
		for (int i = 1; i <= cot; ++i) {
			if (!color[i] && !dfs(i, 1)) {
				yes = 0;
				break;
			}
		}
		printf("Case #%d: %s\n", ++cas, yes ? "Yes" : "No");
	}
	return 0;
}
