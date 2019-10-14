#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 5555;

int n, m;
struct Edge {
	int x, y, f;
} edges[N];
vector < ipair > e[N];

int pred[N], predI[N];
void dfs(int v, int p, int pi) {
	if (pred[v] != -1)
		return;
	pred[v] = p;
	predI[v] = pi;
	for (ipair nvp : e[v]) {
		int nv = nvp.X;
		if (pred[nv] == -1)
			dfs(nv, v, nvp.Y);
		else {
			bool was = false;
			int u = v;
			while (true) {
				if (u == nv) {
					was = true;
					break;
				}
				if (pred[u] < 0)
					break;
				u = pred[u];
			}
			if (was) {
				u = v;
				while (u != nv) {
					edges[predI[u]].f += (edges[predI[u]].y == pred[u] ? 1 : -1);
					u = pred[u];
				}
				edges[nvp.Y].f += (edges[nvp.Y].y == v ? 1 : -1);
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		e[i].clear();
	for (int i = 0; i < m; ++i) {
		cin >> edges[i].x >> edges[i].y;
		--edges[i].x;
		--edges[i].y;
		edges[i].f = 0;
		e[edges[i].x].emplace_back(edges[i].y, i);
		e[edges[i].y].emplace_back(edges[i].x, i);
	}

	memset(pred, -1, sizeof(pred));
	for (int i = 0; i < n; ++i)
		if (pred[i] == -1)
			dfs(i, -2, -2);

	static int ans[N];
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < m; ++i) {
		assert(abs(edges[i].f) <= n*n);
		if (edges[i].f == 0) {
			cout << "IMPOSSIBLE\n";
			return;
		}
		ans[edges[i].x] -= edges[i].f;
		ans[edges[i].y] += edges[i].f;
	}
	for (int i = 0; i < n; ++i)
		assert(!ans[i]);
	for (int i = 0; i < m; ++i)
		cout << edges[i].f << " ";
	cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
	cout.precision(20);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
    {
		cout << "Case #" << i << ": ";
		solve();
        cerr << "Case " << i << "/" << t << " done\n";
    }

    return 0;
}
