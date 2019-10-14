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

int qq;
int n;
int a[10240];
int l[10240];
int r[10240];
const int z = 1 << 11;
int t[4][z * 2];

void tadd(int *t, int x, int k)
{
	x += z;
	while (x)
	{
		t[x] = max(t[x], k);
		x >>= 1;
	}
}

void tsub(int *t, int x, int k)
{
	x += z;
	t[x] = k;
	while (x > 1)
	{
		x >>= 1;
		t[x] = min(t[x * 2], t[x * 2 + 1]);
	}
}

int tmax(int *t, int l, int r)
{
	int ans = 0;
	l += z;
	r += z;
	while (l <= r)
	{
		ans = max(ans, t[l]);
		ans = max(ans, t[r]);
		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}
	return ans;
}

int tmin(int *t, int l, int r)
{
	int ans = n + 2013;
	l += z;
	r += z;
	while (l <= r)
	{
		ans = min(ans, t[l]);
		ans = min(ans, t[r]);
		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}
	return ans;
}

bool check(int pos)
{
	return (
		tmax(t[0], 0, pos - 1) + 1 == l[pos] &&
		tmax(t[1], pos + 1, n - 1) + 1 == r[pos] &&
		tmin(t[2], pos + 1, n - 1) > l[pos] &&
		tmin(t[3], 0, pos - 1) > r[pos]
	);
}

void solve()
{
	clr(t);
	memset(t[2], 0x3f, sizeof(t[2]));
	memset(t[3], 0x3f, sizeof(t[3]));
	forn(i, n)
	{
		a[i] = -1;
	}
	forn(i, n)
	{
		t[2][z + i] = l[i];
		t[3][z + i] = r[i];
	}
	Ford(i, z - 1, 1)
	{
		t[2][i] = min(t[2][i * 2], t[2][i * 2 + 1]);
		t[3][i] = min(t[3][i * 2], t[3][i * 2 + 1]);
	}
	forn(i, n)
	{
		bool ok = false;
		forn(j, n)
		{
			if (a[j] >= 0) continue;
			if (check(j))
			{
				a[j] = i;
				ok = true;
				tadd(t[0], j, l[j]);
				tadd(t[1], j, r[j]);
				tsub(t[2], j, n + 2013);
				tsub(t[3], j, n + 2013);
				break;
			}
		}
		if (!ok)
		{
			cerr << "Botwa !!!" << endl;
		}
	}
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &qq);
	forn(ii, qq)
	{
		printf("Case #%d:", ii+1);
		fprintf(stderr, "Case #%d:\n", ii+1);
		
		scanf("%d", &n);
		forn(i, n)
		{
			scanf("%d", &l[i]);
		}
		forn(i, n)
		{
			scanf("%d", &r[i]);
		}
		solve();

		forn(i, n)
		{
			printf(" %d", a[i] + 1);
		}
		puts("");
		
		fflush(stdout);
	}

	return 0;
}
