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


int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w+", stdout);
	
	int t;
	cin >> t;
	REP (tt, t)
	{
		cout << "Case #" << (tt+1)<<": ";
		
		string s;
		string l1;
		string l2;
		cin >> s >> l1 >> l2;
		
		map <char, int> m1;
		map <int, char> m2;
		
		int n1 = l1.size ();
		int n2 = l2.size ();
		REP (i, n1)
			m1[l1[i]] = i;
		REP (i, n2)
			m2[i] = l2[i];
		
		int num = 0;
		REP (i, s.size ())
		{
			num *=n1;
			num += m1[s[i]];
		}
		
		string res;
		
		if (num == 0)
			res += m2[0];
		while (num)
		{
			res = m2[num%n2]+res;
			num/=n2;
		}
		
		cout << res<< endl;
	}

	
	return 0;
}

