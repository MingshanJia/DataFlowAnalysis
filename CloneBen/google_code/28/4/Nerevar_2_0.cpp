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

int d[10][1 << 10];
int n, k;
bool f[10][10];

void solve(int tc)
{
	cerr << tc << endl;
	printf("Case #%d: ", tc);
	memset(d, 0, sizeof(d));
	memset(f, 0, sizeof(f));
	cin >> n >> k;
	forn(i, k)
	{
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		f[u][v] = f[v][u] = true;
	}		
	d[0][1] = 1;
	forn(mask, (1 << n))
	{
		forn(i, n)
		{
			if (!(mask & (1 << i))) continue;
			forn(j, n)
			{
				if (mask & (1 << j)) continue;
				if (f[i][j]) continue;
				d[j][mask ^ (1 << j)] = (d[j][mask ^ (1 << j)] + d[i][mask]) % 9901;
			}
		}
	}
	int ans = 0;
	for1(i, n - 1)
	{
		if (!f[0][i]) ans = (ans + d[i][(1 << n) - 1]) % 9901;
	}
	printf("%d\n", (ans * 4951) % 9901);
}

int main()
{
	freopen(CIN_FILE, "rt", stdin);
	freopen(COUT_FILE, "wt", stdout);
	int tc;
	scanf("%d", &tc);
	forn(it, tc) solve(it + 1);	
	return 0;
}
         	
