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

#define N 1024

int n,m;
char a[N][N];

bool valid(int l, int r, int u, int d){
	if (l < 0 || r >= m || u < 0 || d >= n) return false;
	FOR(i,u,d) FOR(j,l,r) if (a[i][j] != '?') return false;
	return true;
}

int main(int argc, char **argv)
{
	string FN = "A-small-attempt0";
	if (argc>1) FN = string(argv[1]);
	int shift = 0;
	if (argc>2) sscanf(argv[2],"%d",&shift);
	freopen((FN+".in").c_str(),"r",stdin);
	freopen((FN+".out").c_str(),"w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+shift);
		printf("Case #%d:\n",test+shift);
		////////////////////////////////////////////////////////////
		scanf("%d%d",&n,&m);
		REP(i,n) scanf("%s",a[i]);
		set<char> s;
		REP(i,n) REP(j,m) if (a[i][j] != '?' && !s.count(a[i][j])){
			char c = a[i][j];
			a[i][j]='?';
			s.insert(c);
			int l = j, r = j;
			int u = i, d = i;
			while (valid(l-1,r,u,d)) --l;
			while (valid(l,r+1,u,d)) ++r;
			while (valid(l,r,u-1,d)) --u;
			while (valid(l,r,u,d+1)) ++d;
			FOR(ii,u,d) FOR(jj,l,r) a[ii][jj]=c;
		}
		REP(i,n) REP(j,n) if (a[i][j]=='?') fprintf(stderr,"BAD!!!!!!!\n\n\n");
		REP(i,n)
		printf("%s\n",a[i]);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}