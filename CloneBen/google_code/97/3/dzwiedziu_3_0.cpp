
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


const int nmx=905;
int E[nmx][nmx];
int ES[nmx][nmx];
int DS[nmx];
int h,w,n;
int N[nmx][nmx];
int P[nmx];
bool S[nmx];
VI spec;
char A[nmx][nmx];


const int inf=10000;

// STANDARD
const int DX[]={0,1,0,-1},DY[]={1,0,-1,0};


int parent(int x){
	if(P[x]==x) return x;
	return P[x]=parent(P[x]);
}


int main()
{
	int z; scanf("%d",&z);
	REP(zz,z)
	{
		spec.clear();
		CLR(S,0);
		n=0;
		CLR(N,-1);
		fprintf(stderr,"Working on %d / %d\n",zz+1,z);
		scanf("%d%d",&h,&w);
		REP(y,h) scanf("%s",A[y]);
		REP(y,h)REP(x,w) if(A[y][x]!='.'){
		 	if(A[y][x]=='T'){
				S[n]=1;
				spec.PB(n);
			}
			N[y][x]=n++;
		}
		REP(i,n) P[i]=i;
		REP(i,n)REP(j,n) E[i][j]=inf,ES[i][j]=inf*inf+inf;
		REP(i,n) E[i][i]=0;
		int xt,yt;
		REP(y,h)
			REP(x,w){
				if(N[y][x]==-1) continue;
				REP(d,4){
					xt=x+DX[d],yt=y+DY[d];
					if(xt< 0 || xt>=w || yt<0 || yt>=h || N[yt][xt]==-1) continue;
					E[N[y][x]][N[yt][xt]]=1;
					
				}
			}
		REP(k,n)	REP(a,n)	REP(b,n) E[a][b]=min(E[a][b],E[a][k]+E[k][b]);
		REP(i,n){
			DS[i]=inf;
			REP(j,n) if(S[j]) DS[i]=min(DS[i],E[i][j]);
		}			
		vector<pair<int,PI > > es;
		REP(i,n) ES[i][i]=-DS[i];
		REP(a,n)
			REP(b,n) if(E[a][b]==1) ES[a][b]=-DS[a]-DS[b];

		REP(k,n)
			REP(a,n)
			REP(b,n){
			
				if(a!=b && a!=k && b!=k && E[a][b] == E[a][k] + E[k][b])
					ES[a][b]=min(ES[a][b], ES[a][k]+ ES[k][b] - ES[k][k]);
			}

		REP(a,n)	REP(b,n) if(S[a] && S[b]&& a!=b) es.PB(MP(ES[a][b]+(E[a][b]*(E[a][b]+1))/2,MP(a,b)));
		sort(ALL(es));
		int k=SIZE(es);
		LL cost=0;
		REP(i,k){
			int cs=es[i].FI,a=es[i].SE.FI,b=es[i].SE.SE;
//			printf("cs:%d a:%d b:%d %d %d\n",cs,a,b,E[a][b],ES[a][b]); 
			if (parent(a) != parent(b)){
				cost+=cs;
				P[parent(a)]=parent(b);		
			}
		}
		LL result=cost;
		REP(i,n) result+=DS[i];
		printf("Case #%d: %lld\n",zz+1,result);
	}
	return 0;
}
