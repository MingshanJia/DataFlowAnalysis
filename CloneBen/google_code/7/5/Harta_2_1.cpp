#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int t, n, cnt, start[20010];
string a, b;

int main() {
	scanf("%d", &t);
	int xx = 1;
	while (t--) {
		scanf("%d", &n);
		cnt = 1;
		map<string, int> mp;
		map<int, string> mpinv;
		vector<int> g[20010];
		memset(start, 0, sizeof(start));
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			if (mp.find(a) == mp.end()) {
				mp[a] = cnt;
				mpinv[cnt] = a;
				cnt++;
			}
			if (mp.find(b) == mp.end()) {
				mp[b] = cnt;
				mpinv[cnt] = b;
				cnt++;
			}
			g[mp[a]].pb(mp[b]);
			start[mp[b]] = 1;
		}
		queue<int> q;
		for (int i = 1; i < cnt; i++) {
			if (!start[i]) {
				q.push(i);
			}
		}
		printf("Case #%d:", xx++);
		while (!q.empty()) {
			int front = q.front();
			q.pop();
			if (g[front].size() == 0) break;
			int to = g[front][0];
			q.push(to);
			printf(" %s-%s", mpinv[front].c_str(), mpinv[to].c_str());
		}
		printf("\n");
	}
	return 0;
}
