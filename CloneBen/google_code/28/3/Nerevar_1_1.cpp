#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>

using namespace std;

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define VI vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define all(v) v.begin(), v.end()

#define NMAX 15
#define MMAX (1 << 15)
#define INF 1000000

int d[NMAX + 1][MMAX], len[MMAX];
int n, k;
int x[NMAX], y[NMAX];

void solve(int tc)
{
	printf("Case #%d: ", tc);
	scanf("%d %d", &n, &k);
	forn(i, n)
	{
		scanf("%d %d", &x[i], &y[i]);
	}
	forn(mask, (1 << n)) d[0][mask] = INF;
	d[0][0] = 0;
	for1(mask, (1 << n) - 1)
	{
		int minX = INF, minY = INF, maxX = -INF, maxY = -INF;
		forn(i, n)
		{
			if (mask & (1 << i))
			{
				minX = min(minX, x[i]);
				minY = min(minY, y[i]);
				maxX = max(maxX, x[i]);
				maxY = max(maxY, y[i]);
			}
		} 
		len[mask] = max(maxX - minX, maxY - minY);
	}
	for1(i, k)	
	{
		for1(mask, (1 << n) - 1)
		{
			d[i][mask] = INF;
			for (int subMask = mask; subMask > 0; subMask = (subMask - 1) & mask)
			{
				d[i][mask] = min(d[i][mask], max(d[i - 1][mask ^ subMask], len[subMask]));	
			}
		}			
	}
	cout << d[k][(1 << n) - 1] << endl;
}

int main()
{
	freopen(CIN_FILE, "rt", stdin);
	freopen(COUT_FILE, "wt", stdout);
	int tc;
	scanf("%d", &tc);
	for1(it, tc) solve(it);
	return 0;
}
         	
