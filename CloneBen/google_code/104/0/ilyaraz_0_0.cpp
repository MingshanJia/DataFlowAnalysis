#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:64000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
//#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)((x).size()))

#define forn(i, x) for (int i = 0; i < int(x); i++)
#define fors(i, x) forn(i, sz(x))

template<typename T> T sqr(T x) { return x * x;            }
template<typename T> T abs(T x) { return (x > 0) ? x : -x; }

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int nt;
	scanf("%d", &nt);
	forn(it, nt)
	{
		ll n, a, b, c, d, x0, y0, m;
		cin >> n >> a >> b >> c >> d >> x0 >> y0 >> m;
		vll x, y;
		ll cx = x0, cy = y0;
		x.pb(cx);
		y.pb(cy);
		forn(i, n - 1)
		{
			cx = (a * cx + b) % m;
			cy = (c * cy + d) % m;
			x.pb(cx);
			y.pb(cy);
		}
		int ans = 0;
		forn(i, n) forn(j, i) forn(k, j)
		{
			int o1 = (x[i] + x[j] + x[k]) % 3;
			int o2 = (y[i] + y[j] + y[k]) % 3;
			if (!o1 && !o2) ans++;
		}
		cout << "Case #" << (it + 1) << ": " << ans << "\n";
	}
	return 0;
}
