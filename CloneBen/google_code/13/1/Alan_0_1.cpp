#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define MAXN 128
using namespace std;
int getId(map<string, int>& s2i, string &name) {
	if(s2i.find(name) == s2i.end()) {
		int id = s2i.size();
		s2i[name] = id;
	}
	return s2i[name];
}
bool canPartite(vector<int> g[], int n, int color[], int u) {
	for(int i = 0; i < g[u].size(); ++i) {
		if(color[g[u][i]] == -1) {
			color[g[u][i]] = !color[u];
			if(!canPartite(g, n, color, g[u][i])) {
				return false;
			}
		} else {
			if(color[g[u][i]] == color[u]) 
				return false;
		}
	}
	return true;
}
int main() {
	int t;
	cin >> t;
	int cs = 1;
	while(t--) {
		int m;
		map<string, int> s2i;
		vector<int> g[MAXN];
		int color[MAXN];
		cin >> m;
		for(int i = 0; i < m; ++i) {
			string name1, name2;
			cin >> name1 >> name2;
			int id1 = getId(s2i, name1);
			int id2 = getId(s2i, name2);
			g[id1].push_back(id2);
			g[id2].push_back(id1);
		}
		int n = s2i.size();
		fill(color, color + n, -1);
		cout << "Case #" << cs << ": ";
		color[0] = 0;
		if(canPartite(g, n, color, 0)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
		++cs;
	}
	return 0;
}
