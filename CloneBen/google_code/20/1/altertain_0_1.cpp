#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <queue>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define MP make_pair
#define ST first
#define ND second
#define PB push_back
#define FOR(i,a,b) for( int i=(a); i<(b); ++i)
#define FORD(i,a,b) for( int i=(a); i>(b); --i)
#define REP(i,n) for(int i=0; i<(n); ++i)
#define ALL(X) (X).begin(),(X).end()
#define SZ(X) (int)(X).size()
#define FORE(it,X) for(__typeof((X).begin()) it=(X).begin(); it!=(X).end();++it)

LL n,m,p;

int main()
{
	int tn;
	cin>>tn;
	
	while (tn--) {
		cin>>n>>m>>p;

		vector<LL> ln; ln.PB(0);
		LL t=1;
		LL s=m%p;
		LL l=(m+p-1)/p;
		ln.PB(l);

		while (s) {
			l++;
			if (s+m>p)
				l+=(m-(p-s)+p-1)/p;
			ln.PB(l);
			s=(s+m)%p;
			t++;
		}

		static int tt=0;
		printf("Case #%d: ",++tt);
		cout<<l*(n/t)+ln[n%t]<<endl;
	}
	return 0;
}
