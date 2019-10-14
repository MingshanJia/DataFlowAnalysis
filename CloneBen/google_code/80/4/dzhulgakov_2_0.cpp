#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define FN "C-small-attempt0"
int n,m;
VI c,best;
int bestcnt;
VI adj[16];
int uu[16],vv[16];

int sh(int x, int b)
{
	return (x-b+n)%n;
}

bool check(int colors)
{
	set<PII> edges;
	REP(ii,n) REP(jj,SZ(adj[ii])) if (edges.count(PII(ii,adj[ii][jj])) == 0)
	{
		set<int> clrs;
		clrs.insert(c[ii]);
		clrs.insert(c[adj[ii][jj]]);
		int prev = ii;
		int cur = adj[ii][jj];
		edges.insert(PII(prev,cur));
		while (cur != ii)
		{
			int mn = -1;
			REP(i,SZ(adj[cur]))
				if (sh(adj[cur][i], cur) < sh(prev, cur) && (mn == -1 || sh(adj[cur][i], cur) > sh(mn, cur)))
					mn = adj[cur][i];
			prev = cur;
			cur = mn;
			if (edges.count(PII(prev,cur)))
				fprintf(stderr,"BAD\n");
			edges.insert(PII(prev,cur));
			clrs.insert(c[cur]);
		}
		if (SZ(clrs) != colors)
			return false;
	}
	return true;
}

void rec(int v, int mxclr)
{
	if (v == n)
	{
		if (check(mxclr+1))
		{
			if (mxclr+1 > bestcnt)
			{
				bestcnt = mxclr+1;
				best = c;
			}
		}
		return;
	}
	FOR(i,0,mxclr+1)
	{
		c.pb(i);
		rec(v+1, max(mxclr,i));
		c.pop_back();
	}
}

int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"*");
		scanf("%d%d",&n,&m);
		REP(i,m) scanf("%d",uu+i);
		REP(i,m) scanf("%d",vv+i);
		REP(i,n) adj[i].clear();
		REP(i,n) adj[i].pb((i+1)%n);
		REP(i,m)
		{
			--uu[i];
			--vv[i];
			adj[uu[i]].pb(vv[i]);
			adj[vv[i]].pb(uu[i]);
		}
		c.clear();
		c.pb(0);
		bestcnt = 0;
		rec(1,0);
		printf("Case #%d: %d\n",test,bestcnt);
		REP(i,n)
			printf(" %d"+(i==0),best[i]+1);
		printf("\n");
	}
	return 0;
}