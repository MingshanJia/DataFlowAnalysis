
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


bool B[200][200];
int res;
int DX[2],DY[2];
int w,h;

		queue<int> X,Y; 
	
void add(int x,int y){
	if(x < 0 || x>= w || y< 0 || y>=h ) return;
	if(B[y][x]) return;
	B[y][x]=1;
	res++;
	X.push(x);
	Y.push(y);


}

int main()
{
	int z; scanf("%d",&z);
	REP(zz,z)
	{
		fprintf(stderr,"Working on %d / %d\n",zz+1,z);
CLR(B,0);
		res=0;
		scanf("%d%d",&w,&h);
		REP(i,2) scanf("%d%d",DX+i,DY+i);
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);

		while(!X.empty()){
			x=X.front();
			y=Y.front();
X.pop();
Y.pop();
			REP(d,2)
				add(x+DX[d],y+DY[d]);
		}	

		printf("Case #%d: %d\n",zz+1,res);
	}
	return 0;
}
