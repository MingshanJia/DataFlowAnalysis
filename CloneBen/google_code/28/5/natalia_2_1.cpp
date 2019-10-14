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

#define MOD 9901
#define KMAX 20
#define MASK (1 << 16)
#define NMAX 305

int n, k;
struct Edge
{
	int u, v;
	int num;
};

Edge e[KMAX];
int d[MASK];
int div2[MOD];
bool used[NMAX];
int deg[NMAX];
vector<Edge> g[NMAX];
int curCnt;

void dfs(int v, int mask)
{
	if (used[v]) return;
	used[v] = true;
	curCnt++;
	forv(i, g[v])
	{
		if (!(mask & (1 << g[v][i].num))) continue;
		int u = g[v][i].v;
		dfs(u, mask);
	}
}

int fact[NMAX];
int pow2[KMAX];

int calc(int mask)
{
	memset(used, 0, sizeof(used));
	memset(deg, 0, sizeof(deg));
	forn(i, k)
	{
		if (mask & (1 << i))
		{
			deg[e[i].u]++;
			deg[e[i].v]++;
		}
	}
	int p = 0;
	int m = 0;
	forn(i, n)
	{
		if (used[i]) continue;
		curCnt = 0;
		dfs(i, mask);
		if (curCnt == 1) m++;
		else p++;
	}

	int c1 = 0, c2 = 0;
	forn(i, n)
	{
		if (deg[i] == 1) ++c1;
		if (deg[i] == 2) ++c2;
		if (deg[i] > 2) return 0;
	}
	if (p == 1 && c2 == n && m == 0)
	{
		return 1;		
	}
	if (c1 != p * 2) return 0;
	int ans = (fact[p + m - 1] * pow2[p]) % MOD;
	ans = div2[ans];
	return ans;

}

void solve(int test)
{
	printf("Case #%d: ", test);
	scanf("%d %d", &n, &k);
	forn(i, n) g[i].clear();
	forn(i, k)
	{
		scanf("%d %d", &e[i].u, &e[i].v);
		--e[i].u; --e[i].v;
		e[i].num = i;
		g[e[i].u].pb(e[i]);
		swap(e[i].u, e[i].v);
		g[e[i].u].pb(e[i]);
	}

	int nn = (1 << k) - 1;
	for (int mask = nn; mask >= 0; mask--)
	{
		d[mask] = calc(mask);
		if (mask == nn) continue;
		int im = mask ^ nn;
		int m1;
		for (int im1 = (im - 1) & im; ; im1 = (im1 - 1) & im)
		{
			m1 = im1 ^ nn;
			d[mask] = (d[mask] - d[m1] + MOD) % MOD;	
			if (im1 == 0) break;
		}
	}
	printf("%d\n", d[0]);
}
int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	forn(i, MOD)
	{
		div2[(2 * i) % MOD] = i;
	}
	fact[0] = 1;
	for1(i, NMAX - 1)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	pow2[0] = 1;
	for1(i, KMAX - 1)
	{
		pow2[i] = (pow2[i - 1] * 2) % MOD;
	}

	int tc; scanf("%d", &tc);
	forn(it, tc)
	{
		solve(it + 1);
	}
	return 0;
}
