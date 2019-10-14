#include <bits/stdc++.h>
using namespace std;

const int maxn = 505;

map <string, int> M;
int color[maxn];
vector <int> E[maxn];

bool dfs(int x, int fa, int z) {
	color[x] = z;
	for(int i : E[x]) {
		if(!color[i]) {
			if(dfs(i, x, 3 - z) == false) return false; 
		} else {
			if(color[i] == color[x]) return false;
		}
	}
	return true;
}
int main() {
#ifdef youmu
	freopen("A-small-2-attempt0.in", "r", stdin);
	freopen("A-small-2-attempt0.ou", "w", stdout);
#endif
	int T, m, cases = 0;
	cin >> T;
	while(T--) {
		cin >> m;
		string x, y;
		int idx = 0;
		M.clear();
		memset(color, 0, sizeof(color));
		for(int i = 0; i < maxn; i++) E[i].clear();
		while(m--) {
			cin >> x >> y;
			if(!M.count(x)) M[x] = ++idx;
			if(!M.count(y)) M[y] = ++idx;
			int u = M[x];
			int v = M[y];
			E[u].push_back(v);
			E[v].push_back(u);
		}
		bool flag = 1;
		for(int i = 1; i <= idx; i++) {
			if(!color[i]) flag &= dfs(i, 0, 1);
		}
		printf("Case #%d: %s\n", ++cases, flag ? "Yes" : "No");
	}
	return 0;
}
