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
#include <cassert>

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

#define N 2048
int n,m,p;
int xx[N],yy[N],mn[N],mx[N];
int path[N];
int d[N];
#define INF 1000000000

int main(int argc, char **argv)
{
	string FN = "C-small-attempt0";
	if (argc>1) FN = string(argv[1]);
	int shift = 0;
	if (argc>2) sscanf(argv[2],"%d",&shift);
	freopen((FN+".in").c_str(),"r",stdin);
	freopen((FN+".out").c_str(),"w",stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+shift);
		printf("Case #%d: ",test+shift);
		////////////////////////////////////////////////////////////
		cin >>n >> m>> p;
		REP(i,m)
		{
			cin >> xx[i] >> yy[i] >> mn[i] >> mx[i];
			--xx[i];
			--yy[i];
		}
		REP(i,p)
		{
			cin >> path[i];
			--path[i];
		}
		int res = 0;
		REP(mask,1<<m)
		{
			REP(i,n)
				d[i]=INF;
			d[1]=0;
			REP(step,n+1)
			{
				REP(i,m)
					d[xx[i]] = min(d[xx[i]],d[yy[i]]+(mask&(1<<i) ? mn[i] : mx[i]));
			}
			if (d[0] == INF)
				fprintf(stderr,"BAD!\n");
			int len = 0;
			REP(i,p)
			{
				int id = path[i];
				len += mask&(1<<id)?mn[id]:mx[id];
				int v = yy[id];
				if (d[0] < len+d[v])
					break;
				res = max(res,i+1);
			}
		}
		if (res == p)
			printf("Looks Good To Me\n");
		else
			printf("%d\n",path[res]+1);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}