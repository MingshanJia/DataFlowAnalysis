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

const int p10[] = {
	1,
	10,
	100,
	1000,
	10000,
	100000,
	1000000,
	10000000,
	100000000,
	1000000000
};

bool vis[100000];

struct Cc {
	vector < int > good;
	vector < vector < int > > e;
	vector < int > cnt;
	int len;

	void go(int x, int clen, int csum) {
		if (csum > len)
			return;
		if (clen == len) {
			if (x)
				good.push_back(x);
			return;
		}
		for (int y = 0; y <= len; ++y)
			go(x*10+y, clen + 1, csum + y);
	}

	void comp(int _len) {
		len = _len;
		go(0, 0, 0);
		sort(good.begin(), good.end());
		e.resize(sz(good));
		cnt.resize(sz(good));
		for (int i = 0; i < sz(good); ++i) {
			int cx = good[i];
			int y = 0;
			while (cx) {
				if (cx % 10)
					y += p10[cx % 10 - 1];
				cx /= 10;
			}
			e[lower_bound(good.begin(), good.end(), y) - good.begin()].push_back(i);

			cnt[i] = 1;
			vector < int > nv;
			cx = good[i];
			int nvs = 0;
			for (int j = 0; j < len; ++j) {
				for (int k = 0; k < cx % 10; ++k) {
					nv.push_back(j + 1);
					nvs += j + 1;
				}
				cx /= 10;
			}
			if (sz(nv) > len || nvs <= len)
				continue;
			while (sz(nv) < len)
				nv.push_back(0);
			sort(nv.begin(), nv.end());
			do
				++cnt[i];
			while (next_permutation(nv.begin(), nv.end()));
		}
		cerr << len << " ok\n";
	}

	int gog(int x) {
		if (vis[x])
			return 0;
		vis[x] = 1;
		int r = cnt[x];
		for (int y : e[x])
			r += gog(y);
		return r;
	}
} cc[11];

void solve()
{
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	int x = 0;
	int l = sz(s);
	for (char c : s)
		x = x*10 + (c-'0');
	memset(vis, 0, sizeof(vis));
	int pos = lower_bound(cc[l].good.begin(), cc[l].good.end(), x) - cc[l].good.begin();
	if (cc[l].good[pos] == x)
		cout << cc[l].gog(lower_bound(cc[l].good.begin(), cc[l].good.end(), x) - cc[l].good.begin()) << "\n";
	else
		cout << "1\n";
}

int main()
{
    ios::sync_with_stdio(false);
	cout.precision(20);

	for (int i = 1; i <= 9; ++i)
		cc[i].comp(i);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
    {
		cout << "Case #" << i << ": ";
		solve();
        //cerr << "Case " << i << "/" << t << " done\n";
    }

    return 0;
}
