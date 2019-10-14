
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (c).size()
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

long long a[8000][40];

const long long inf = 1LL<<32;

long long get (long long i, long long j)
{
	if (j==0)
		return 0;
	if (j==1)
		return i;
	if (j==2)
		return min(i*(i+1)/2, inf);
	j<?=39;
	i<?=7999;
	return a[i][j];
}


int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w+", stdout);
	
	memset (a, 0, sizeof (a));
	
	REP (i, 8000)
		REP (j, 40)
		{
			if (!i || !j)
				continue;
			a[i][j] = a[i-1][j]+a[i-1][j-1]+1LL;		
			a[i][j] <?=inf;
		}
	
	int t;
	cin >> t;
	REP (tt, t)
	{
		long long a, b, c;
		cout << "Case #"<<(tt+1)<<": ";
		cin >> a >> b >> c;
		
		int b1 = 0;
		int b2 = b;
		while (b1<b2)
		{
			int bb = (b1+b2)/2;
			
			if (get (bb, c)<a)
				b1 = bb+1;
			else
				b2 = bb;
		}
		//cout << "ok1" << endl;
		int c1 = 0;
		int c2 = c;
		
		while (c1<c2)
		{
			int cc = (c1+c2)/2;
			if (get (b, cc)<a)
				c1 = cc+1;
			else
				c2 = cc;
		}
		long long aa = get (b, c);
		if (aa==inf)
			aa = -1;
		cout << aa << " " << b1 << " " << c1 << endl;
	}
	
	return 0;
}
