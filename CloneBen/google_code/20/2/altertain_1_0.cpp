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

string dt[3];
string ops,dump;
char op;

bool good(int v,int idx)
{
	int l=SZ(dt[idx]);
	REP(i,l) {
		if (l>1 && v==0) return false;
		if (dt[idx][i]!='?')
			if (dt[idx][i]!=v%10+48) return false;
		v/=10;
	}
	if (v) return false;
	return true;
}

int main()
{
	int tn;
	cin>>tn;

	while (tn--) {
		cin>>dt[0]>>ops>>dt[1]>>dump>>dt[2];
		reverse(ALL(dt[0]));
		reverse(ALL(dt[1]));
		reverse(ALL(dt[2]));
		op=ops[0];

		int l1,l2,l3;
		l1=SZ(dt[0]);
		l2=SZ(dt[1]);
		l3=SZ(dt[2]);

		int amn,amx;
		int bmn,bmx;
		amn=bmn=1;

		while (--l1) amn*=10;
		while (--l2) bmn*=10;
		amx=amn*10;
		bmx=bmn*10;

		if (amn==1) amn=0;
		if (bmn==1) bmn=0;

		static int qq=0;
		printf("Case #%d: ",++qq);
		FOR(i,amn,amx) {
			if (!good(i,0)) continue;
//			cout<<"i "<<i<<" ";

			int s=bmx;
			if (op=='-')
				s=min(s,i+1);
			FOR(j,bmn,s) {
				if (!good(j,1)) continue;
//				cout<<"j "<<j<<endl;

				int k = i + j;
				if (op=='-')
					k = i - j;

				if (k<0) continue;
				
				if (!good(k,2)) continue;

				cout<<i<<" "<<op<<" "<<j<<" = "<<k<<endl;
				i=j=max(amx,bmx);
			}
		}
	}
	return 0;
}
