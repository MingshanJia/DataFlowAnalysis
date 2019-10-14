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

int dsu[N];
int getRoot(int v) {
	return dsu[v] == -1 ? v : dsu[v] = getRoot(dsu[v]);
}
bool merge(int x, int y) {
	x = getRoot(x);
	y = getRoot(y);
	if (x == y)
		return false;
	dsu[x] = y;
	return true;
}

int n;
int dest[N], start[N], dur[N], in1[N], in2[N];

int costWait(int x, int y) {
	int t = start[y] - (start[x] + dur[x]);
	t %= 24;
	if (t < 0)
		t += 24;
	return t;
}

struct Edge {
	int cost;
	int x, y;
};
vector < Edge > edges;
int perm[N];

void solve()
{
	cin >> n;
	memset(in1, -1, sizeof(in1));
	memset(in2, -1, sizeof(in2));
	for (int i = 0; i < n * 2; ++i) {
		cin >> dest[i] >> start[i] >> dur[i];
		--dest[i];
		if (in1[dest[i]] == -1)
			in1[dest[i]] = i;
		else
			in2[dest[i]] = i;
	}

	int answer = IINF;
	for (int iii = 0; iii < 2; ++iii) {
		edges.clear();
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int cost1, cost2;
			if (i == 0) {
				cost1 = start[i*2] + costWait(in2[i], i*2+1);
				cost2 = start[i*2] + costWait(in1[i], i*2+1);
			} else {
				cost1 = costWait(in1[i], i*2) + costWait(in2[i], i*2+1);
				cost2 = costWait(in2[i], i*2) + costWait(in1[i], i*2+1);
			}
			if (cost1 < cost2) {
				ans += cost1;
				perm[in1[i]] = i*2;
				perm[in2[i]] = i*2 + 1;
				edges.push_back({cost2 - cost1, i*2, i*2+1});
			} else {
				ans += cost2;
				perm[in1[i]] = i*2 + 1;
				perm[in2[i]] = i*2;
				edges.push_back({cost1 - cost2, i*2, i*2+1});
			}
			ans += dur[i*2];
			ans += dur[i*2+1];
		}
		memset(dsu, -1, sizeof(dsu));
		for (int i = 0; i < n*2; ++i)
			merge(i, perm[i]);
		sort(edges.begin(), edges.end(), [](Edge const & a, Edge const & b) { return a.cost < b.cost; });
		for (Edge e : edges)
			if (merge(e.x, e.y))
				ans += e.cost;
		int okk = 0;
		for (int i = 0; i < n*2; ++i)
			if (dsu[i] == -1)
				++okk;
		if (okk == 1)
			answer = min(answer, ans);

		swap(dest[0], dest[1]);
		swap(start[0], start[1]);
		swap(dur[0], dur[1]);
		memset(in1, -1, sizeof(in1));
		memset(in2, -1, sizeof(in2));
		for (int i = 0; i < n * 2; ++i) {
			if (in1[dest[i]] == -1)
				in1[dest[i]] = i;
			else
				in2[dest[i]] = i;
		}
	}
	cout << answer << "\n";
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
