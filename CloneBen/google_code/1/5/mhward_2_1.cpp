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

int G[105][105];
bool vis[105][105];
V<V<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
V<pair<int, int>> negs;
int negind[105][105];


void dfs(int bs) {
	stack<pair<int, int>> S;
	memset(vis, 0, sizeof vis);
	vis[sr][sc] = 1;
	S.emplace(sr, sc);
	while (S.size()) {
		int r, c;
		tie(r, c) = S.top();
		S.pop();
		for (auto &dir : dirs) {
			int rr = r+dir[0], cc = c+dir[1];
			if (rr<0||rr>=N||cc<0||cc>=M) continue;
			if (G[rr][cc] == -1e5) continue;
			if (negind[rr][cc] != -1 && !(bs&(1<<negind[rr][cc]))) continue;
			if (vis[rr][cc]) continue;
			vis[rr][cc] = 1;
			S.emplace(rr, cc);
		}
	}
}

ll sumvis() {
	ll sum = 0;
	FO(i, N) FO(j, M) if (vis[i][j]) {
		sum += G[i][j];
	}
	return sum;
}


pair<bool, ll> DP[1<<15+5];

pair<bool, ll> f(int bs) {
	if (DP[bs].second != -1e18) return DP[bs];
	dfs(bs);
	ll s = E+sumvis();
	// cout << bs << " " << s << " " << vis[tarr][tarc] << endl;
	if (s < 0) return make_pair(0, s);
	auto best = make_pair(vis[tarr][tarc], s);
	FO(i, negs.size()) if (!(bs&(1<<i))) {
		if (s >= -G[negs[i].first][negs[i].second]) {
			best = max(best, f(bs|(1<<i)));
		}
	}
	return DP[bs] = best;
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cout << "Case #" << tc << ": ";
		cin >> N >> M >> E >> sr >> sc >> tarr >> tarc;
		--sr;--sc;--tarr;--tarc;

		FO(i, N) {
			FO(j, M) {
				cin >> G[i][j];
			}
		}

		negs.clear();
		memset(negind, -1, sizeof negind);

		FO(i, 1<<15+1) {
			DP[i] = make_pair(0, -1e18);
		}

		FO(i, N) FO(j, M) {
			if (G[i][j] > -1e5 && G[i][j] < 0) {
				negind[i][j] = negs.size();
				negs.emplace_back(i, j);
			}
		}

		auto p = f(0);

		if (!p.first) cout << -1 << endl;
		else cout << p.second << endl;

		// cout << p.first << " " << p.second << endl;

		
	}
}