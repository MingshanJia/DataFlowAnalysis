#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int H, W;
int modw(int x) { return (x + 2*W) % W; }
set<vector<string> > mem;
int res;
void rec(const vector<string>& now) {
	tuple<int, int, int, int> best(-1, -1, -1, -1);
	rep(i,0,H) rep(j,0,W) {
		char c = now[i][j];
		int ci = c - '0';
#define MATCH(y,x) (y >= 0 && y < H && now[y][modw(x)] == c ? 1 : 0)
#define USED(y,x) (y < 0 || y >= H || now[y][modw(x)] != '0' ? 1 : 0)
		int v = MATCH(i,j-1) + MATCH(i-1,j) + MATCH(i,j+1) + MATCH(i+1,j);
		int adj = USED(i,j-1) + USED(i-1,j) + USED(i,j+1) + USED(i+1,j);
// cerr << v << ' ' << ci << endl;
		if (ci && v > ci) return;
		if (adj == 4) {
			if (ci != 0 && v != ci) return;
			continue;
		}
		best = max(best, make_tuple(ci, adj, i, j));
	}
	int y, x;
	tie(ignore, ignore, y, x) = best;
// cerr << y << ' ' << x << endl;
	if (y == -1) {
		if (!mem.count(now)) {
			vector<string> then = now;
			rep(i,0,W) {
				rep(j,0,H)
					rotate(then[j].begin(), then[j].begin() + 1, then[j].end());
				mem.insert(then);
			}
			res++;
			// rep(i,0,H) cout << now[i] << endl;
			// cout << endl;
			return;
		}
	}

	// int ci = now[y][x] - '0';
	rep(dx,-1,2) rep(dy,-1,2) {
		if (abs(dx) + abs(dy) != 1) continue;
		int nx = x + dx, ny = y + dy;
		if (USED(ny, nx)) continue;
// cerr << "testing " << ny << ' ' << nx << endl;
		rep(as,1,4) {
			vector<string> then = now;
			then[ny][modw(nx)] = (char)(as + '0');
			rec(then);
		}
		return;
	}
}

int solve() {
	cin >> H >> W;
	mem.clear();
	res = 0;
	vector<string> state(H, string(W, '0'));
	rec(state);
	return res;
}

int main() {
	int N;
	cin.sync_with_stdio(false);
	cin >> N;
	rep(i,0,N) {
		printf("Case #%d: %d\n", i+1, solve());
	}
}
