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

PII dt[100005];
LL val[10001];
int n,m,b;
LL da[100005];
LL db[100005];

int main()
{
	int tn;
	cin>>tn;

	while (tn--) {
		cin>>n>>m>>b;
		REP(i,m) scanf("%d%d",&dt[i].ST, &dt[i].ND);

		sort(dt,dt+m);
		int r=-1;
		FORD(i,m-1,-1) {
			if (dt[i].ST<b) {
				r=i;
				break;
			}
		}

		memset(da,-1,sizeof(da));
		memset(db,-1,sizeof(db));
		int c=0;
		da[0]=db[0]=0;
		REP(i,m) if (dt[i].ST>=b) {
			REP(j,dt[i].ND) {
				c++;
				da[c]=da[c-1]+dt[i].ST-b;
				if (c>n) break;
			}
			if (c>n) break;
		}

		memset(val,0,sizeof(val));
		REP(i,r+1)
			val[dt[i].ST] += dt[i].ND;
	//	REP(i,b)
	//		cout<<val[i]<<" "; cout<<endl;

		c=0;
		REP(ch,b) {
			REP(i,b) {
				while (val[i] && val[b+ch-i]) {
					if (i==b+ch-i && val[i]<2)
						break;
					//cout<<"ch : "<<ch<<endl;
					//cout<<"i : "<<i<<endl;
					val[i]--;
					val[b+ch-i]--;
					c++;
					db[c]=db[c-1]+ch;
					if (c>n) break;
				}
				if (c>n) break;
			}
			if (c>n) break;
		}

	/*	REP(i,n+1)
			cout<<da[i]<<" "; cout<<endl;
		REP(i,n+1)
			cout<<db[i]<<" "; cout<<endl;
*/
		LL dp=1e18;
		REP(i,n+1) if (da[i]>=0 && db[n-i]>=0)
		{
	//		cout<<da[i]<<"+"<<db[n-i]<<endl;
			dp=min(dp,da[i]+db[n-i]);
		}

		static int qq=0;
		printf("Case #%d: ",++qq);
		if (dp==1e18)
			cout<<-1<<endl;
		else
			cout<<(LL)n*b+dp<<endl;
	}
	return 0;
}
