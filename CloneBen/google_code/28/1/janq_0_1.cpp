// pre-written code {{{
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <numeric>
#include <iostream>
#include <cassert>
#include <set>
#define FOR(i,n) for(int _n=n,i=0;i<_n;++i)
#define FR(i,a,b) for(int _b=b,i=a;i<_b;++i)
#define CL(x) memset(x,0,sizeof(x))
#define PN printf("\n");
#define MP make_pair
#define PB push_back
#define SZ size()
#define ALL(x) x.begin(),x.end()
#define FORSZ(i,v) FOR(i,v.size())
#define FORIT(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
using namespace std;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long LL;
///////////////////////////////////////////////////////////////////////////////////
// }}}


void solve(){
   int a,b;
   scanf("%d %d",&a,&b);
   if(b%2==0) printf("WHITE\n"); else printf("BLACK\n");
}

main(){
  int pvs; scanf("%d",&pvs);
  FR(ppp,1,pvs+1){
     printf("Case #%d: ",ppp);

     solve();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
