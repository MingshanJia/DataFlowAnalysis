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

#define MASK (1 << 15)
#define NMAX 17
#define INF 1000006

int n, k;
int d[NMAX][MASK];
int x[NMAX], y[NMAX];

void solve(int test)
{
	printf("Case #%d: ", test);
	scanf("%d %d", &n, &k);
	forn(i, n)
	{
		scanf("%d %d", &x[i], &y[i]);
	}
	forn(mask, (1 << n))
	{
		if (mask == 0) continue;
		int l = INF, r = -INF, u = -INF, down = INF;
		forn(i, n)
		{
			if (mask & (1 << i))
			{
				l = min(l, x[i]);
				r = max(r, x[i]);
				u = max(u, y[i]);
				down = min(down, y[i]);
			}
		}
		d[1][mask] = max(u - down, r - l);
	}

	for (int i = 2; i <= k; i++)
	{
		forn(mask, (1 << n))
		{
			if (mask == 0) continue;
			d[i][mask] = INF;
			for (int m1 = (mask - 1) & mask; m1 > 0; m1 = (m1 - 1) & mask)
			{
				d[i][mask] = min(d[i][mask], max(d[i - 1][m1], d[1][m1 ^ mask]));
			}
		}
	}

	printf("%d\n", d[k][(1 << n) - 1]);
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
