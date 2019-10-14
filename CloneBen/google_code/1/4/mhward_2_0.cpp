#include <bits/stdc++.h>

using namespace std;

template <typename T>
using V = vector<T>;

typedef long double ld;
typedef long long ll;

#define FO(i, N) for (int (i) = 0; (i) < (N); ++(i))
#define FOll(i, N) for (ll (i) = 0; (i) < (N); ++(i))
#define READALL(c) for (auto &e : c) { cin >> e; }
#define PRINTALL(c) for (const auto &e : c) { cout << e << "\t"; } cout << "\n";
#define MP(x, y) (make_pair((x), (y)))
#define MT(...) make_tuple(__VA_ARGS__)
#define ALL(x) begin(x), end(x)

int N, M, E;
int sr, sc, tarr, tarc;




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cout << "Case #" << tc << ": ";
		cin >> N >> M >> E >> sr >> sc >> tarr >> tarc;
		--sr;--sc;--tarr;--tarc;

		V<V<ll>> G(N, V<ll>(M));
		FO(i, N) READALL(G[i]);

		FO(i, N) FO(j, M) {
			if (G[i][j] > -1e5) G[i][j] = -G[i][j];
		}

		priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> Q;
		Q.emplace(0, sr, sc);
		V<V<int>> vis(N, V<int>(M));
		V<V<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
		ll dist = 1e18;
		while (!Q.empty()) {
			ll d, r, c;
			tie(d, r, c) = Q.top();
			Q.pop();
			// cout << r << " " << c << " " << d << endl;
			if (vis[r][c]) continue;
			vis[r][c] = 1;
			if (r == tarr && c == tarc) {
				dist = d;
				break;
			}
			for (auto &dir : dirs) {
				int rr = r+dir[0], cc = c+dir[1];
				if (rr<0||rr>=N||cc<0||cc>=M) {
					continue;
				}
				// cout <<rr << " " << cc << endl;
				if (G[rr][cc] == -1e5) continue;
				if (vis[rr][cc]) continue;
				Q.emplace(d+G[rr][cc], rr, cc);
			}
		}

		if (dist == 1e18 || dist > E) {
			cout << -1 << endl;
		} else {
			cout << E-dist << endl;
		}

		
	}
}