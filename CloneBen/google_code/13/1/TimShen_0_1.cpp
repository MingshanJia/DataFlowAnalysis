#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<string, int> mp;
int top;
vector<int> g[1000];

int getid(const string & s) {
	if (mp.count(s)) {
		return mp[s];
	} else {
		return mp[s] = top++;
	}
}

void addEdge(int a, int b) {
	g[a].push_back(b);
	g[b].push_back(a);
}

bool ans;
vector<int> vis;

void dfs(int s, int color) {
	if (vis[s] == 0) {
		vis[s] = color;
		for (int i = 0; i < (int)g[s].size(); i++) {
			int j = g[s][i];
			dfs(j, 3-color);
			if (!ans) {
				return;
			}
		}
	} else if (vis[s] != color) {
		ans = false;
	}
}

int main() {
	int T;
	cin >> T;
	for (int ca = 1; ca <= T; ca++) {
		int n;
		cin >> n;
		mp.clear();
		top = 0;
		for (int i = 0; i < 1000; i++) {
			g[i].clear();
		}
		string s, t;
		for (int i = 0; i < n; i++) {
			cin >> s >> t;
			addEdge(getid(s), getid(t));
		}
		ans = true;
		vis.clear();
		vis.resize(top);
		for (int i = 0; i < top; i++) {
			if (vis[i] == 0) {
				dfs(i, 1);
			}
		}
		if (ans) {
			cout << "Case #"<< ca << ": Yes\n";
		} else {
			cout << "Case #"<< ca << ": No\n";
		}
	}
	return 0;
}
