#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i=(a), _b=(b); i>=_b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define INF 1000000000
#define INF_LL 1000000000000000000LL
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int h = 2111;
int n,m, u[h], v[h];

typedef pair<int, bool> pib;
vector<pib> r[h];
vector<vi> p;

int cur;
bool comp (pib x, pib y)
{
	if(x.X < cur)
	{
		if(y.X < cur) return x.X < y.X;
		else return false;
	}
	else
	{
		if(y.X < cur) return true;
		else return x.X < y.X;
	}
}

int ans = 0;

int col[h], best[h];
bool y[8];

void go (int v, int k)
{
	if(v==n)
	{
		REP(i, sz(p))
		{
			REP(j, k) y[j] = 0;
			REP(j, sz(p[i])) y[col[ p[i][j] ]] = 1;
			REP(j, k) if(!y[j]) return;
		}
		if(k > ans)
		{
			ans = k;
			REP(i, n) best[i] = col[i] + 1;
		}
	}
	else
	{
		REP(i, k)
		{
			col[v] = i;
			go(v+1, k);
		}
		col[v] = k;
		go(v+1, k+1);
	}
}

int main()
{
	freopen("c-small-attempt0.in", "r", stdin); //-small-attempt
	freopen("c-small-attempt0.out", "w", stdout); //-large
	int T, it=1;
for(scanf("%d", &T); it<=T; ++it)
{
	scanf("%d%d", &n, &m);
	REP(i, m) scanf("%d", u+i), --u[i];
	REP(i, m) scanf("%d", v+i), --v[i];
	REP(i, n)
	{
		r[i].clear();
		r[i].pb( pib((i+1)%n, 0) );
		r[i].pb( pib((i+n-1)%n, 0) );
	}
	REP(i, m)
	{
		r[u[i]].pb( pib(v[i], 0) );
		r[v[i]].pb( pib(u[i], 0) );
	}
	REP(i, n)
	{
		cur = i;
		sort(all(r[i]), comp);
		//printf("%d:\n", i); REP(j, sz(r[i])) printf("%d ", r[i][j].X); printf("\n");
	}
	p.clear();
	vi a;
	REP(i, n) REP(j, sz(r[i])-1) if(!r[i][j].Y)
	{
		a = vi(1, i);
		int x = r[i][j].X, px = i;
		r[i][j].Y = true;
		while(x != i)
		{
			a.pb(x);
			int l = 0;
			while(r[x][l].X != px) ++l;
			l = (l+sz(r[x])-1) % sz(r[x]);
			int tmp = x;
			r[x][l].Y = true;
			x = r[x][l].X;
			px = tmp;
		}
		p.pb(a);
	}
	//REP(i, sz(p)) { REP(j, sz(p[i])) printf("%d ", p[i][j]); printf("\n"); }
	ans = 0;
	go(0, 0);
	printf("Case #%d: %d\n", it, ans);
	REP(i, n) printf("%d ", best[i]);
	printf("\n");
}
	return 0;
}
