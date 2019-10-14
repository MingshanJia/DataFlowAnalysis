#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
#include <cassert>
#include <queue>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

const int MAXN = -1;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const char dc[4]= {'v', '^', '>', '<'};

typedef long long ll;

struct Graph {
private:
    struct Edge {
        int from, to, cap, flow, cost;
        
        Edge() {}
        Edge(int from, int to, int cap, int cost) : from(from), to(to), cap(cap), flow(0), cost(cost) {}
    };

    int n;
    int S, T;
    vector<vector<int> > e;
    vector<Edge> edges;
    vector<int> d, c;
    
    bool bfs() {
        d.assign(n, 1e9);
        c.assign(n, 0);
        queue<int> q;
        q.push(S);
        d[S] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < e[v].size(); i++) {
                Edge cur = edges[e[v][i]];
                if (d[cur.to] > d[v] + 1 && -cur.flow + cur.cap > 0) {
                    d[cur.to] = d[v] + 1;
                    q.push(cur.to);
                }
            }
        }
        return d[T] < 1e9;
    }

    int dfs(int v, int flow) {
        if (flow == 0) return 0;
        if (v == T) return flow;
        for (int &i = c[v]; i < e[v].size(); i++) {
            Edge cur = edges[e[v][i]];
            if (d[cur.to] != d[v] + 1) continue;
            int pushed = dfs(cur.to, min(flow, cur.cap - cur.flow));
            if (pushed) {
                edges[e[v][i]].flow += pushed;
                edges[e[v][i] ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
    vector<int> p, pr, fl;

    int dijkstra() {
        d.assign(n, 1e9);
        pr.assign(n, -1);
        fl.assign(n, 0);
        set<pair<int, int> > st;
        d[0] = 0;
        fl[0] = 1e9;
        for (int i = 0; i < n; i++) st.insert(make_pair(d[i], i));

        while (!st.empty()) {
            int v = st.begin()->second;
            st.erase(st.begin());

            for (int i = 0; i < e[v].size(); i++) {
                Edge cur = edges[e[v][i]];
                if (d[cur.to] > d[v] + cur.cost + p[v] - p[cur.to] && cur.flow < cur.cap) {
                    st.erase(make_pair(d[cur.to], cur.to));
                    d[cur.to] = d[v] + cur.cost + p[v] - p[cur.to];
                    st.insert(make_pair(d[cur.to], cur.to));
                    fl[cur.to] = min(fl[v], cur.cap - cur.flow);
                    pr[cur.to] = e[v][i];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            p[i] += d[i]; 
            if (p[i] > 1e9) p[i] = 1e9;
        }
        return fl[n - 1];
    }

public:
    Graph() {}
    Graph(int N) {
        n = N;
        e.resize(n);
    }

    void addEdge(int from, int to, int cap, int cost = 0) {
        e[from].push_back(edges.size());
        edges.push_back(Edge(from, to, cap, cost));
        e[to].push_back(edges.size());
        edges.push_back(Edge(to, from, 0, -cost));
    }

    ll getFlow(int s, int t) {
        for (int i = 0; i < edges.size(); i++) edges[i].flow = 0;
        S = s, T = t;
        ll ans = 0;
        while (bfs()) {
            while (int pushed = dfs(S, 1e9)) {
                ans += pushed;
            }
        }
        return ans;
    }

    pair<int, int> minCost() {
        p.assign(n, 0);
        pair<int, int> res;

        while (1) {
            int fl = dijkstra();
            res.first += fl;
            if (!fl) break;
            int v = n - 1;
            while (v != 0) {
                int o = pr[v];
                edges[o].flow += fl;
                res.second += edges[o].cost * fl;
                edges[o ^ 1].flow -= fl;
                v = edges[o].from;
            }
        }
        return res;
    }
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";
		cerr << "Case #" << test << ": ";

		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		bool ok = 1;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) if (a[i][j] != '.') {
				int k = -1;
				for (int kk = 0; kk < 4; kk++) if (dc[kk] == a[i][j]) k = kk;

				int x = i, y = j;
				x += dx[k];
				y += dy[k];
				bool cok = 0;
				while (x >= 0 && y >= 0 && x < n && y < m) {
					if (a[x][y] != '.') {
						cok = 1;
						break;
					}
					x += dx[k];
					y += dy[k];
				}
				if (cok) continue;

				for (int k = 0; k < 4; k++) {
					int x = i, y = j;
					x += dx[k];
					y += dy[k];
					while (x >= 0 && y >= 0 && x < n && y < m) {
						if (a[x][y] != '.') {
							cok = 1;
							break;
						}
						x += dx[k];
						y += dy[k];
					}
				}
				if (cok) ans++;
				else ok = 0;
			}
		}
		if (ok) {
			cout << ans;
			cerr << ans;
		} else {
			cout << "IMPOSSIBLE";
			cerr << "IMPOSSIBLE";
		}

		cout << endl;
		cerr << endl;
	}

    return 0;
}