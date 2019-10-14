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
int n;
int b[1024][2];
int xx[1024];
int xs;
bool d[16][1 << 15];

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
		
		scanf("%d", &n);
		xs = 0;
		forn(i, n)
		{
			char cc;
			scanf(" %c%d", &cc, &b[i][1]);
			b[i][0] = (cc == 'E');
			xx[xs++] = b[i][1];
		}
		xx[xs++] = 0;
		sort(xx, xx + xs);
		xs = unique(xx, xx + xs) - xx;
		forn(i, n)
		{
			b[i][1] = lower_bound(xx, xx + xs, b[i][1]) - xx - 1;
		}
		clr(d);
		forn(i, 1 << n)
		{
			d[0][i] = true;
		}
		int ans = n + 10;

		forn(i, n)
		{
			forn(mask, 1 << n)
			{
				if (!d[i][mask]) continue;
				if (b[i][0]) // 'E'
				{
					if (b[i][1] < 0)
					{
						forn(j, n)
						{
							if (mask & (1 << j))
							{
								d[i + 1][mask & ~(1 << j)] = true;
							}
						}
					}
					else if (mask & (1 << b[i][1]))
					{
						d[i + 1][mask & ~(1 << b[i][1])] = true;
					}
				}
				else // 'L'
				{
					if (b[i][1] < 0) 
					{
						forn(j, n)
						{
							if (!(mask & (1 << j)))
							{
								d[i + 1][mask | (1 << j)] = true;
							}
						}
					}
					else if (!(mask & (1 << b[i][1])))
					{
						d[i + 1][mask | (1 << b[i][1])] = true;
					}
				}
			}
		}

		forn(i, 1 << n)
		{
			if (d[n][i])
			{
				ans = min(ans, n - __builtin_popcount(i));
			}
		}

		if (ans > n) puts("CRIME TIME");
		else printf("%d\n", ans);
		
		fflush(stdout);
	}

	return 0;
}
