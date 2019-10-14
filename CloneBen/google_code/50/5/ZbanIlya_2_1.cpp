#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
#include <cassert>
#include <queue>
#include <sstream>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long ll;

const int MAXN = -1;

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

		int n;
		cin >> n;
		vector<vector<string> > _a(n);
		string oo;
		getline(cin, oo);
		vector<string> vct;
		for (int i = 0; i < n; i++) {
			getline(cin, oo);
			stringstream ss;
			ss << oo;
			string s;
			while (ss >> s) {
				_a[i].push_back(s);
				vct.push_back(s);
			}
		}
		sort(vct.begin(), vct.end());
		vct.resize(unique(vct.begin(), vct.end()) - vct.begin());
		int m = vct.size();

		vector<vector<int> > a(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < (int)_a[i].size(); j++) {
				a[i].push_back(lower_bound(vct.begin(), vct.end(), _a[i][j]) - vct.begin());
			}
			sort(a[i].begin(), a[i].end());
		}

		vector<int> type(m, 0);
		for (int k = 0; k < 2; k++) {
			for (int i = 0; i < (int)a[k].size(); i++) {
				type[a[k][i]] |= 1 << k;
			}
		}

		Graph gr(2 * m + 2);
		int ans = 0;
		for (int i = 0; i < m; i++) {
			if (type[i] == 3) {
				ans++;
			}
			if (type[i] == 1) {
				gr.addEdge(0, 2 * i + 1, 1);
			}
			if (type[i] == 2) {
				gr.addEdge(2 * i + 2, 2 * m + 1, 1);
			}
			gr.addEdge(2 * i + 1, 2 * i + 2, 1);
		}
		
		for (int i = 2; i < n; i++) {
			for (int j = 0; j < (int)a[i].size(); j++) {
				for (int k = 0; k < (int)a[i].size(); k++) if (a[i][j] != a[i][k]) {
					gr.addEdge(a[i][j] * 2 + 2, a[i][k] * 2 + 1, 1);
				}
			}
		}
		ans += gr.getFlow(0, 2 * m + 1);

		cout << ans << endl;
		cerr << ans << endl;
	}

    return 0;
}