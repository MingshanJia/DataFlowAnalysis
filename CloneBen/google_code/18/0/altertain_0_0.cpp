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

typedef LL Flow;
typedef LL Cost;
#define ERR 0

//e.PB( fe( u, v, 1, 0, c ) ), e.PB( fe( v, u, 1, 0, c ) ); // if undirect graph

typedef struct fe {
   LL u, v;
   Cost cost;
   Flow c, f;
   Flow res() { return c - f; } //rest
   fe() {}
   fe(LL _u, LL _v, Flow _c, Flow _f=0, Cost _cost = 0)
      : u(_u), v(_v), c(_c), f(_f), cost(_cost) { }
   fe rev(){ return fe( v, u, c, c-f, -cost ); }
}fe;

typedef struct mcmf{

   // n, s, t, e should be set
   int n, s, t;
   Flow flow;
   Cost cost;
   vector<fe> e;

   LL fp_bf() {
      // should be careful : type of inf, Cost, Flow
      Cost cinf = 1e18*2;
     Flow finf = 1e18*2;
      vector<LL> p(n);
      vector<Cost> mc(n, cinf);
      vector<Flow> mf(n, finf);
      mc[s] = 0;

      LL flag = 1;
      for( LL cnt = 0 ; flag ; cnt++ ){
         flag = 0;
         REP( i, SZ(e) ){
            fe t = e[i]; LL k = i+1;
            if( t.res() && mc[t.u] != cinf && mc[ t.v ] > mc[ t.u ] + t.cost + ERR ){
               //printf("%d %d\n", t.u, t.v );
               if( cnt >= n ) while(1) printf(" ");
               flag = 1;
               mf[ t.v ] = min( mf[ t.u ], t.res() );
               mc[ t.v ] = mc[ t.u ] + t.cost;
               p[ t.v ] = k;
            }
            t = t.rev(), k = -k;
            if( t.res() && mc[t.u] != cinf && mc[ t.v ] > mc[ t.u ] + t.cost + ERR ){
               //printf("%d %d\n", t.u, t.v );
               if( cnt >= n ) while(1) printf(" ");
               flag = 1;
               mf[ t.v ] = min( mf[ t.u ], t.res() );
               mc[ t.v ] = mc[ t.u ] + t.cost;
               p[ t.v ] = k;
            }
         }
      }

      if(p[t] == 0) return 0;
      LL v = t;
     Flow inc = mf[t];
      while (v != s){
         fe t = ( p[v] > 0 )? e[ p[v]-1 ] : e[ -p[v]-1 ].rev() ;
         t.f += inc;
         if( p[v] > 0 ) e[ p[v]-1 ] = t;
         else e[ -p[v]-1 ] = t.rev();
         v = t.u;
      }
      flow += inc;
      cost += inc * mc[t];
      return ( inc != 0 ); // if there is no more flow
   }

   Flow process() {
      // should be careful : type of flow, cost
      flow = 0;
      cost = 0;
      while( fp_bf() );
      return flow;
   }

}mcmf;

LL n,A,B,C,D,E,F;
LL dt[3][3];

int main()
{
	int tn;
	cin>>tn;

	while (tn--) {
		cin>>n>>A>>B>>C>>D>>E>>F;
		REP(i,3) REP(j,3)
			cin>>dt[i][j];

		mcmf mf;
		mf.n=8;
		mf.s=0;
		mf.t=7;

		mf.e.PB( fe( 0, 1, A, 0, 0 ) );
		mf.e.PB( fe( 0, 2, B, 0, 0 ) );
		mf.e.PB( fe( 0, 3, C, 0, 0 ) );

		mf.e.PB( fe( 4, 7, D, 0, 0 ) );
		mf.e.PB( fe( 5, 7, E, 0, 0 ) );
		mf.e.PB( fe( 6, 7, F, 0, 0 ) );

		REP(i,3) REP(j,3)
			mf.e.PB(fe(i+1,j+4,n,0,-dt[i][j]));

		mf.process();
		LL dp=-mf.cost;

		static int tt=0;
		printf("Case #%d: ",++tt);
		cout<<dp<<endl;
	}
	return 0;
}
