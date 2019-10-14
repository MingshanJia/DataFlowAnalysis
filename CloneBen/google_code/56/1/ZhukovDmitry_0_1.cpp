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
typedef long long i64;
typedef __int128 i128;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

int qq;
int n, p, q, r, s;
i64 a[1024000];
i64 b[1024000];

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
		
		scanf("%d%d%d%d%d", &n, &p, &q, &r, &s);
		b[0] = 0;
		forn(i, n)
		{
			a[i] = (i * (i64)p + q) % r + s;
			b[i + 1] = a[i] + b[i];
		}
		
		i64 ans = b[n];
		int j = 0;
		forn(i, n)
		{
			i64 s2 = b[n] - b[i + 1];
			while (j + 1 <= i && b[j + 1] <= b[i + 1] - b[j + 1]) j++;
			i64 s0 = b[j];
			i64 s1 = b[i + 1] - b[j];
			i64 tmp = max(max(s0, s1), s2);
			if (j + 1 <= i)
			{
				i64 s0 = b[j + 1];
				i64 s1 = b[i + 1] - b[j + 1];
				i64 tmp1 = max(max(s0, s1), s2);
				if (tmp1 < tmp) tmp = tmp1;
			}
			if (tmp < ans) ans = tmp;
		}
		ans = b[n] - ans;
		printf("%0.10lf\n", (b[n] > 0 ? ans * 1.0 / b[n] : 0));

		fflush(stdout);
	}

	return 0;
}
