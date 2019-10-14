
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

int h,w;
int T[10][10];
int O[10][1<<12];
int A[10][10];
const int DX[]={0,0,1,1,1,0,-1,-1,-1},DY[]={0,1,1,0,-1,-1,-1,0,1};
int result;


bool ok(int x,int y){
	int xt,yt;
	int s=0;
	REP(d,9){
		xt=x+DX[d];
		yt=y+DY[d];
		if( xt <  0 || xt >=w || yt< 0 || yt>=h) continue;
		if(A[yt][xt]) s++;
	}
	return s==T[y][x];
}



bool fun(int mask,int n){
//	if(O[n][mask]!=-1) return O[n][mask];
	if (n==h){
		bool o=1;
		REP(x,w) o&=ok(x,n-1);
		return O[n][mask]=o;
	}
	bool res=0;
	REP(x,w) A[n-2][x]=(mask&(1<<x))?1:0;
	REP(x,w) A[n-1][x]=(mask&(1<<(x+w)))?1:0;
	if (n==2) {
		bool o=1;
		REP(x,w)	o&=ok(x,0);
		if(!o) return O[n][mask]=0;
	}
	REP(d,1<<w){
		REP(x,w) A[n-2][x]=(mask&(1<<x))?1:0;
		REP(x,w) A[n-1][x]=(mask&(1<<(x+w)))?1:0;
		REP(x,w) A[n][x]=(d&(1<<x))?1:0;
		bool o=1;
		REP(x,w) o&=ok(x,n-1);
		if (o){
			res|=fun((mask>>w)|(d<<w),n+1);
		}
		if(res)break;
	}
	if(res && h/2+1 == n){
		int r=0;
		REP(x,w) if(mask&(1<<(x+w))) r++;
		result=max(r,result);	
	}
	O[n][mask]=res;
	return res;
}



int main()
{
	int z; scanf("%d",&z);
	REP(zz,z)
	{
		result=0;
		fprintf(stderr,"Working on %d / %d\n",zz+1,z);
		scanf("%d%d",&h,&w);
		REP(y,h)REP(x,w) scanf("%d",T[y]+x);
		CLR(O,-1);
		int res=0;
		REP(m,1<<(w*2)){
			fun(m,2);
		}
		printf("Case #%d: %d\n",zz+1,result);
	}
	return 0;
}
