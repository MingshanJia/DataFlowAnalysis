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
int n, p, q;
int h[222];
int g[222];
int d[102][402][1020];

inline void upd(int &a, int b)
{
	if (a < b) a = b;
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
		
		scanf("%d%d%d", &p, &q, &n);
		forn(i, n)
		{
			scanf("%d%d", &h[i], &g[i]);
		}
		memset(d, 0x80, sizeof(d));
		h[n] = 401;
		g[n] = 0;
		d[0][0][0] = 0;
		int ans = 0;
		int m = 1001;
		forn(i, n)
		{
			forn(j, h[i])
			{
				forn(k, m + 1)
				{
					if (d[i][j][k] < 0) continue;
					int dd = d[i][j][k];
					if (k < m)
					{
						int in = i;
						int jn = j + q;
						if (jn >= h[i])
						{
							jn = 0;
							in++;
						}
						upd(d[in][jn][k + 1], dd);
					}

					if (k > 0)
					{
						int add = 0;
						int in = i;
						int jn = j + p;
						if (jn >= h[i])
						{
							add = g[i];
							jn = 0;
							in++;
						}
						upd(d[in][jn][k - 1], dd + add);
					}

					{
						int add = 0;
						int in = i;
						int jn = j + p;
						if (jn >= h[i])
						{
							jn = 0;
							in++;
							add = g[i];
						}
						jn += q;
						if (jn >= h[in])
						{
							jn = 0;
							in++;
						}
						upd(d[in][jn][k], dd + add);
					}
				}
			}
		}
		forn(j, h[n])
		{
			forn(k, m + 1)
			{
				upd(ans, d[n][j][k]);
			}
		}
		printf("%d\n", ans);
		
		fflush(stdout);
	}

	return 0;
}
