#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define bublic public
#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const i64 INF = 7e18;
const int MOD = 1000002013;

int qq;
int n, m;
int a[10240][3];
int xs[10240];
i64 d[10240];

inline void add(int &a, int b)
{
	a += b;
	a -= (a >= MOD) * MOD;
}

inline void sub(int &a, int b)
{
	a -= b;
	a += (a < 0) * MOD;
}

void solve(int l, int r, int &ans)
{
	if (l > r) return;
	i64 mi = INF;
	int mj = -1;
	For(i, l, r)
	{
		if (d[i] < mi)
		{
			mi = d[i];
			mj = i;
		}
	}
	if (mi == 0)
	{
		solve(l, mj - 1, ans);
		solve(mj + 1, r, ans);
		return;
	}
	i64 z = xs[r + 1] - xs[l];
	add(ans, (z * (z - 1) / 2) % MOD * (mi % MOD) % MOD);
	For(i, l, r)
	{
		d[i] -= mi;
	}
	solve(l, r, ans);
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &qq);
	forn(ii, qq)
	{
		printf("Case #%d: ", ii+1);
		fprintf(stderr, "Case #%d:\n", ii+1);
		
		int k = 0;
		scanf("%*d%d", &m);
		int ans = 0;

		forn(i, m)
		{
			forn(j, 3)
			{
				scanf("%d", &a[i][j]);
			}
			xs[k++] = a[i][0];
			xs[k++] = a[i][1];
			i64 z = a[i][1] - a[i][0];
			sub(ans, (z * (z - 1) / 2 % MOD) * a[i][2] % MOD);
		}
		sort(xs, xs + k);
		k = unique(xs, xs + k) - xs;
		forn(i, m)
		{
			forn(j, 2)
			{
				a[i][j] = lower_bound(xs, xs + k, a[i][j]) - xs;
			}
		}
		clr(d);

		forn(i, m)
		{
			For(j, a[i][0], a[i][1] - 1)
			{
				d[j] += a[i][2];
			}
		}

		solve(0, k - 2, ans);

		ans %= MOD;
		ans += MOD;
		ans %= MOD;
		printf("%d\n", ans);
		
		fflush(stdout);
	}

	return 0;
}
