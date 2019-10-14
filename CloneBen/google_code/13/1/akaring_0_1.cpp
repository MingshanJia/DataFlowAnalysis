//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <map>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define REP(i,n) for (int i=0,n_=int(n); i<n_; ++i)
#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(),(c).end()
using namespace std; typedef long long lint;
template<typename T> inline void checkMin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (a < b) a = b; }

const int MAXN = 205;

map<string, int> mp;
vector<int> edge[MAXN];

int col[MAXN];

bool dfs(int u, int c) {
	if (col[u] != -1) {
		return col[u] == c;
	}
	col[u] = c;
	for (int v: edge[u]) {
		if (!dfs(v, !c)) {
			return false;
		}
	}
	return true;
}

bool gao() {
	int m, cnt = 0;
	cin >> m;
	fill(edge, edge + MAXN, vector<int>());
	REP (i, m) {
		string s1, s2;
		cin >> s1 >> s2;
		int a = mp.count(s1) ? mp[s1] : (mp[s1] = ++cnt);
		int b = mp.count(s2) ? mp[s2] : (mp[s2] = ++cnt);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	fill(col, col + MAXN, -1);
	REP (i, cnt) {
		if (col[i + 1] == -1 && !dfs(i + 1, 0)) {
			return false;
		}
	}
	return true;
}

int main() {
	int n_case;
	cin >> n_case;
	for (int index = 1; index <= n_case; ++index) {
		mp.clear();
		printf("Case #%d: %s\n", index, gao() ? "Yes" : "No");
	}
	return 0;
}
