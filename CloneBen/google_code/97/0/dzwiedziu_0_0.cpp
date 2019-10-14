
// Headers {{{
#include<iostream>
#include<assert.h>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
#include<bitset>
#include<numeric>
using namespace std;


#define FOR(I,A,B) for(int I=(A);I<=(B);++I)
#define FORD(I,A,B) for(int I=(A);I>=(B);--I)
#define REP(I,N) for(int I=0;I<(N);++I)
#define VAR(V,init) __typeof(init) V=(init)
#define FORE(I,C) for(VAR(I,(C).begin());I!=(C).end();++I)
#define CLR(A,v) memset((A),v,sizeof((A)))

#define SIZE(x) ((int)((x).size()))
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

typedef vector<int> VI;
typedef pair<int,int> PI;
typedef long long LL;
typedef vector<string> VS;
// }}}

const int nmx=5000;
int n;
int A[3];
int T[5000][3];

const int  poj=10000;


inline int fun(){
	assert(A[0]+A[1]+A[2]==poj);
	int r=0;
	REP(i,n){
		if(A[0] >= T[i][0] && A[1] >= T[i][1] && A[2]>=T[i][2]) r++;
	}
	return r;
}

int main()
{
	int z; scanf("%d",&z);
	REP(zz,z)
	{
		fprintf(stderr,"Working on %d / %d\n",zz+1,z);
		scanf("%d",&n);
		REP(i,n) scanf("%d%d%d",T[i],T[i]+1,T[i]+2);
		int best=0;
		REP(a,poj+1){
			A[0]=a;
			int l=0,r=poj-a;
			int fa,fb;
			while( l + 3 < r ){
				int lk= l+(r-l)/3;
				int rk= l+2*((r-l)/3);
				A[1]=lk;
				A[2]=poj-a-lk;
				fa=fun();
				A[1]=rk;
				A[2]=poj-a-rk;
				fb=fun();
				best=max(best,fa);
				best=max(best,fb);
				if ( fa <= fb ) l=lk;
				else r=rk;
			}
			FOR(i,l,r)
			{
				A[1]=i;
				A[2]=poj-i-a;
				best=max(best,fun());
			}
		}
		printf("Case #%d: %d\n",zz+1,best);
	}
	return 0;
}
