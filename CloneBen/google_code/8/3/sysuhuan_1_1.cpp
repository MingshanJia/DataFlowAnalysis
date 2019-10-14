#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <cstdlib>
#include <queue>
#include <vector>

#define X first
#define Y second
#define mp make_pair
#define sqr(x) ((x) * (x))
#define Rep(i, n) for(int i = 0; i<(n); i++)
#define foreach(it, n) for(__typeof(n.begin()) it = n.begin(); it != n.end(); it++)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

#define esp 1e-8
#define N 1010

int ecnt; 
struct Edge {
	int to, val, inLine;
	Edge *next;
}*mat[N], edges[N*4];

void link(int x, int to, int val, int inLine) {
	edges[ecnt].to = to;
	edges[ecnt].val = val;
	edges[ecnt].inLine = inLine;
	edges[ecnt].next = mat[x];
	mat[x] = &edges[ecnt++];
}

int sn[N], n, w[N], metro[N];
int dis[2][N];
bool in_que[2][N];

bool check(int &x, int y) {
	if (y == -1) return false;
	if (x == -1 || x > y) {
		x = y;
		return true;
	}
	return false;
}
int solve(int m1, int s1, int m2, int s2) {
	memset(dis, -1, sizeof dis);
	memset(in_que, false, sizeof in_que);
	queue<pair<int,int> > que;
	dis[0][sn[m1]+s1] = 0;
	que.push(make_pair(0, sn[m1]+s1));
	while (!que.empty()) {
		int inLine = que.front().X;
		int id = que.front().Y;
		int m = metro[id];
		in_que[inLine][id] = false;
		que.pop();
		for (Edge *p = mat[id]; p; p = p->next) {
			int to = p->to;
			int val = dis[inLine][id] + p->val;
			if (p->inLine && !inLine) val += w[m];
			if (check(dis[p->inLine][to], val) && !in_que[p->inLine][to]) {
				in_que[p->inLine][to] = true;
				que.push(make_pair(p->inLine, to));
			}
		}

	}
	int ans = -1;
	check(ans, dis[0][sn[m2]+s2]);
	check(ans, dis[1][sn[m2]+s2]);
	return ans; 
}
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int cas, tt = 0;
	scanf("%d", &cas);
	while (cas--) {
		ecnt = 0;
		memset(sn, 0, sizeof sn);
		memset(mat, 0, sizeof mat);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &sn[i + 1], &w[i]);
			for (int j = 0; j < sn[i + 1]; j++) metro[sn[i]+j] = i;
			for (int j = 0; j < sn[i + 1] - 1; j++) {
				int val;
				scanf("%d", &val);
				link(sn[i] + j, sn[i] + j + 1, val, 1);
				link(sn[i] + j + 1, sn[i] + j, val, 1);
			}
			sn[i + 1] += sn[i];
		}
		int m, m1, m2, s1, s2, val;
		scanf("%d", &m);
		while (m--) {
			scanf("%d%d%d%d%d", &m1, &s1, &m2, &s2, &val);
			m1--, m2--, s1--, s2--;
			link(sn[m1] + s1, sn[m2] + s2, val, 0);
			link(sn[m2] + s2, sn[m1] + s1, val, 0);
		}
		scanf("%d", &m);
		printf("Case #%d:\n", ++tt);
		while (m--) {
			scanf("%d%d%d%d", &m1, &s1, &m2, &s2, &val);
			m1--, m2--, s1--, s2--;
			printf("%d\n", solve(m1, s1, m2, s2));
		}
	}
	return 0;
}
