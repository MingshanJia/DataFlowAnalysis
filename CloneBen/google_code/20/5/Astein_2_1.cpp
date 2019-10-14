#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int start[105];
int speed[105];
vector<pair<int, int> > graph[10005];
long long mintime_table[105][10005];

int main() {
	int n, p, m;
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		scanf("%d%d%d", &n, &p, &m);
		memset(mintime_table, -1, sizeof(mintime_table));
		for (int i = 0; i < p; ++i) {
			scanf("%d%d", &start[i], &speed[i]);
			start[i]--;
		}
		for (int i = 0; i < n; ++i)
			graph[i].clear();
		for (int i = 0; i < m; ++i) {
			int dist, numcity;
			scanf("%d%d", &dist, &numcity);
			int last = -1, now;
			for (int j = 0; j < numcity; ++j) {
				scanf("%d", &now);
				now--;
				if (last != -1) {
					graph[last].push_back(make_pair(now, dist));
  				graph[now].push_back(make_pair(last, dist));
				}
				last = now;
			}
		}
		for (int i = 0; i < p; ++i) { 
			vector<int> check(n, 0);
			check[start[i]] = 1;
			mintime_table[i][start[i]] = 0;
			priority_queue<pair<int, int> > pq;
			for (int j = 0; j < graph[start[i]].size(); ++j) {
				pq.push(make_pair(-graph[start[i]][j].second, graph[start[i]][j].first));
			}
			while (!pq.empty()) {
				pair<int, int> top = pq.top(); pq.pop();
				int city = top.second;
				int d = -top.first;
				if (check[city] == 1) continue;
			  check[city] = 1;
			  mintime_table[i][city] = d;
			  for (int j = 0; j < graph[city].size(); ++j) {
			  	if (check[graph[city][j].first] == 0) {
			  		pq.push(make_pair(-(d + graph[city][j].second), graph[city][j].first));
			  	}
				}
			}
		}
		long long ret = 987987987987987987LL;
		for (int i = 0; i < n; ++i) {
			bool ispos = true;
			long long maxtime = -1;
			for (int j = 0; j < p; ++j) {
				if (mintime_table[j][i] == -1) ispos = false;
				if (maxtime < mintime_table[j][i] * speed[j]) maxtime = mintime_table[j][i] * speed[j];
			}
			if (ispos && ret > maxtime) ret = maxtime;
		}
		if (ret == 987987987987987987LL) ret = -1;
		cout << "Case #" << cn << ": " << ret << endl;
	}
}

