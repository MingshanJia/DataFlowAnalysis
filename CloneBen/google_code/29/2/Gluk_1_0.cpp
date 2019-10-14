

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

map <PII, int> M;

void go (int x, int y, int v)
{
	if (!M.count (PII (x, y)))
		M[PII (x, y)] = 0;
	//cout << "go " << x << " " << y << " " << v << endl;
	M[PII (x, y)] |= v;
}

int make (int d)
{
	d+=8;
	d%=4;
	return 1<<d;
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w+", stdout);
	
	VPII d;
	d.pb (PII (-1, 0));
	d.pb (PII (0, 1));
	d.pb (PII (1, 0));
	d.pb (PII (0, -1));
	
	
	int t;
	cin >> t;
	REP (tt, t)
	{
		M.clear();
		cout << "Case #" << (tt+1)<<":" << endl;
		
		string s1, s2;
		cin >> s1 >> s2;
		
		int x = -1;
		int y = 0;
		
		int x1 = 0;
		int x2 = 0;
		int y1 = 0;
		int y2 = 0;
		
		int dd = 2;
		bool left = false;
		REP (i, s1.size ())
		{
			if (s1[i]=='W')
			{
				if (!left) go (x, y, make (dd-1));
				left = false;
				//cout << x << " " << y << " " << dd << endl;
				x += d[dd].X;
				y += d[dd].Y;
				
				if (i==s1.size ()-1)
					break;
				x1<?=x; x2>?=x;
				y1<?=y; y2>?=y;
			}
			if (s1[i]=='L')
			{
				dd = (dd+3)%4;
				left = true;
			}
			if (s1[i]=='R')
			{
				go (x, y, make (dd-1) | make (dd));
				dd = (dd+1)%4;
			}
		}
		
		dd = (dd+2)%4;
		left = false;
		REP (i, s2.size ())
		{
			if (s2[i]=='W')
			{
				if (!left) go (x, y, make (dd-1));
				left = false;
				//cout << x << " " << y << " " << dd << endl;
				x += d[dd].X;
				y += d[dd].Y;
				
				if (i==s2.size ()-1)
					break;
				x1<?=x; x2>?=x;
				y1<?=y; y2>?=y;
			}
			if (s2[i]=='L')
			{
				dd = (dd+3)%4;
				left = true;
			}
			if (s2[i]=='R')
			{
				go (x, y, make (dd-1) | make (dd));
				dd = (dd+1)%4;
			}
		}
		
		vector <char> c;
		REP (i, 10)
			c.pb ('0'+i);
		REP (i, 6)
			c.pb ('a'+i);
		//cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
		FOR (i, x1, x2+1)
		{
			FOR (j, y1, y2+1)
			{
				int v = 0;
				if (M.count (PII (i, j)))
					v = M[PII (i, j)];
				//cout << v << " = "  << i << " " << j << endl;
				
				int vv = 0;
				if (v & 1) vv |= 1;
				if (v & 2) vv |= 8;
				if (v & 4) vv |= 2;
				if (v & 8) vv |= 4;
				
				cout << c[15^vv];
			}
			cout << endl;
		}
	}
	

	
	return 0;
}

