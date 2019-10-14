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

i64 solve(i64 x)
{
	i64 ans = 0;
	int cnt = 0;
	forn(i, n)
	{
		if ((x >> i) & 1)
		{
			cnt++;
		}
	}
	ford(i, n)
	{
		if (cnt > 0)
		{
			ans ^= 1LL << i;
			cnt--;
		}
	}
	return ans;
}

i64 go(int n, i64 x)
{
	i64 ans = solve(x);
	ford(i, n)
	{
		if ((x >> i) & 1)
		{
			x ^= 1LL << i;
			x |= (1LL << i) - 1;
			ans = max(ans, solve(x));
			break;
		}
	}
	return ans;
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
		
		i64 x;
		scanf("%d%I64d", &n, &x);

		i64 ans = go(n, x - 1);

		i64 ans2;
		if (x == (1LL << n)) ans2 = (1LL << n) - 1;
		else ans2 = (1LL << n) - 1 - go(n, (1LL << n) - x - 1) - 1;

		printf("%I64d %I64d\n", ans2, ans);
		
		fflush(stdout);
	}

	return 0;
}
