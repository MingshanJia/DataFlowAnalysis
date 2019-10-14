#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cassert>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forv(i, v) forn(i, v.size())
#define for1(i, n) for (int i = 1; i <= int(n); i++)

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef vector<int> VI;
typedef long long ll;

#define NMAX 12
#define MASK (1 << 10)
#define MOD 9901

int n, k;
bool g[NMAX][NMAX];
int d[NMAX][MASK];

void solve(int test)
{
	printf("Case #%d: ", test);
	scanf("%d %d", &n, &k);
	forn(i, n)
	{
		forn(j, n)
		{
			if (i != j) g[i][j] = true;
		}
	}
	forn(i, k)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		g[u][v] = g[v][u] = false;
	}
	memset(d, 0, sizeof(d));
	d[0][0] = 1;

	forn(mask, (1 << n))
	{
		forn(i, n)
		{
			forn(j, n)
			{
				if (mask & (1 << j)) continue;
				if (g[i][j])
				{
					d[j][mask ^ (1 << j)] = (d[j][mask ^ (1 << j)] + d[i][mask]) % MOD;
				}
			}
		}
	}
	int ans = 0;
	forn(i, MOD)
	{
		if ((i * 2) % MOD == d[0][(1 << n) - 1]) ans = i;
	}
	printf("%d\n", ans);
}
int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tc; scanf("%d", &tc);
	forn(it, tc)
	{
		solve(it + 1);
	}
	return 0;
}
