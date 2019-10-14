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

struct state{
	int h,a,x,y;
};

int b,d;

int g[101][101][101][101];

int main(int argc, char **argv)
{
	string FN = "C-small-attempt0";
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
		printf("Case #%d: ",test+shift);
		////////////////////////////////////////////////////////////
		LL n,k;
		state s;
		scanf("%d%d%d%d%d%d",&s.h,&s.a,&s.x,&s.y,&b,&d);
		int inih = s.h;
		FILL(g,-1);
		g[s.h][s.a][s.x][s.y] = 0;
		queue<state> q;
		q.push(s);
		int res = -1;
		while (!q.empty()) {
			state ss = q.front();
			int gg = g[ss.h][ss.a][ss.x][ss.y];
			q.pop();
			REP(move,4){
				state s = ss;
				switch (move) {
				case 0:
					s.x = max(0, s.x-s.a);
					break;
				case 1:
					s.a = min(100, s.a + b);
					break;
				case 2:
					s.h = inih;
					break;
				case 3:
					s.y = max(0, s.y - d);
					break;
				};
				if (s.x > 0) s.h = max(0, s.h - s.y);
				if (s.h <= 0) continue;
				if (s.x == 0) {
					res = gg+1;
					goto ok;
				}
				int&t = g[s.h][s.a][s.x][s.y];
				if (t==-1) {
					t = gg+1;
					q.push(s);
				}
			}
		}
ok:;
		if (res==-1) printf("IMPOSSIBLE\n");
		else printf("%d\n",res);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}