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

int n,k;
int x[20],y[20];

int r[1<<15][15];
int d;

bool ries(int mask, int k){
   if(k==0){
       if(mask==0) return true;
       return false;
   }
   if(mask==0) return true;
   int &ret=r[mask][k];
   if(ret){ return ret-1; }
   VI xx, yy;
   ret=1;
   FOR(i,n) if(mask&(1<<i)) { xx.PB(x[i]); yy.PB(y[i]); }
   FORSZ(i,xx) FORSZ(j,yy){
      //zistit vsetkych, koho by sme pokryli...
      int nmask=mask;
      FOR(h,n) if(mask&(1<<h)) {
          if(xx[i]<=x[h] && x[h] <=xx[i]+d)
          if(yy[j]<=y[h] && y[h] <=yy[j]+d)
             nmask-=(1<<h);          
      }
      if(ries(nmask,k-1)) { ret=2; return true; }
   }
   return false;
}

bool dasa(int mid){
   d=mid;
   CL(r);
   return ries((1<<n)-1,k);
}

void solve(){
   scanf("%d %d",&n,&k);
   FOR(i,n) scanf("%d %d",&x[i],&y[i]);
   int left=0, right=64005;
   while(right-left>3){
       int mid=(right+left)/2;
       if(dasa(mid)) right=mid; else left=mid;
   }
//   printf("%d %d\n",left,right);
   FR(mid,left,right+1) if(dasa(mid)) { printf("%d\n",mid); break; }
   
}

main(){
  int pvs; scanf("%d",&pvs);
  FR(ppp,1,pvs+1){
     printf("Case #%d: ",ppp);

     solve();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
