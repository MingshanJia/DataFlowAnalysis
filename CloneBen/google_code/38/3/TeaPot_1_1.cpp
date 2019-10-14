#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long int64;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

bool DFS(const vector<vector<pair<int, int>>>& adj,
		 vector<bool>& used,
		 vector<int>& res,
		 vector<int>& cur,
		 int v, int  cur_edge) {
	used[v] = true;

	for (int i = 0; i < sz(adj[v]); ++i) {
		int u = adj[v][i].fs;
		int num_edge = abs(adj[v][i].sc) - 1;
		int sign = (adj[v][i].sc > 0 ? 1 : -1);
		if (!used[u]) {
			if (!DFS(adj, used, res, cur, u, num_edge)) {
				return false;
			}
			if (cur[u] == 0) {
				return false;
			}

			res[num_edge] = -cur[u] * sign;
			
            cur[v] += cur[u];
			cur[u] = 0;
		} else if (res[num_edge] == 0 && num_edge != cur_edge) {
			res[num_edge] = sign;
			--cur[v];
			++cur[u]; 
		}
	}

	return true;
}


int main () {
    ios_base::sync_with_stdio(0);
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

    int tc;
	cin >> tc;
	for (int ti = 0; ti < tc; ++ti) {
		int n, m;
		cin >> n >> m;

		vector<vector<pair<int, int>>> adj(n);
		for (int i = 0; i < m; ++i) {
			int v1, v2;
			cin >> v1 >> v2;
			--v1, --v2;
        	adj[v1].pb(mp(v2, i + 1));
        	adj[v2].pb(mp(v1, -(i + 1)));
        }

        vector<int> res(m, 0);
        vector<bool> used(n, false);
        vector<int> cur(n, 0);

        bool key = true;
        for (int i = 0; i < n; ++i) {
        	if (!used[i] && !DFS(adj, used, res, cur, i, -1)) {
        		key = false;
        		break;
        	}
        }

        cout << "Case #" << ti + 1 << ": ";
		if (!key) {
			cout << "IMPOSSIBLE" << "\n";
        } else {
        	for (int i = 0; i < m; ++i) {
        		cout << res[i] << (i + 1 < m ? ' ' : '\n');
        	}
		}
	}


	return 0;
}
