#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define FILE_IN  "C-large.in"
#define FILE_OUT "C-large.out"

#define MAXN 100
#define MAXNODE (2*MAXN+2)
#define LEFT(x) (x)
#define RIGHT(x) ((x)+MAXN)
#define SOURCE (2*MAXN)
#define SINK (SOURCE+1)

typedef pair<int, int> pii;

int adj[MAXNODE][MAXNODE];
int f[MAXNODE][MAXNODE];
int price[MAXN][MAXN];

bool isPath(int s, int t) {
	int from[MAXNODE];
	fill(from, from + MAXNODE, -1);
	queue<int> q;
	q.push(s);
	from[s] = s;
	while (!q.empty() && from[t] < 0) {
		int x = q.front(); q.pop();
		for (int i = 0; i < MAXNODE; ++i)
			if ((adj[x][i]-f[x][i]) > 0 && from[i] < 0) {
				from[i] = x;
				q.push(i);
			}
	}
	if (from[t] < 0)
		return false;
	for (int w = t; w != from[w]; w = from[w]) {
		f[from[w]][w] = 1;
		f[w][from[w]] = -1;
	}
	return true;
}

int maxflow(int s, int t) {
	fill(f[0], f[MAXNODE], 0);
	int c = 0;
	while (isPath(s, t))
		++c;
	return c;
}

void solve() {
	fill(adj[0], adj[MAXNODE], 0);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		adj[SOURCE][LEFT(i)] = 1;
		adj[RIGHT(i)][SINK] = 1;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < k; ++j)
			scanf("%d", &price[i][j]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			bool less = true;
			for (int q = 0; q < k && less; ++q)
				if (price[i][q] >= price[j][q])
					less = false;
			if (less)
				adj[LEFT(i)][RIGHT(j)] = 1;
		}
	int f = maxflow(SOURCE, SINK);
	printf("%d\n", n - f);
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
