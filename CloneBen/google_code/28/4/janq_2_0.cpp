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


int n,m;
int p[10];
int MODU=9901;
int res=0;
bool h[10][10];
bool mark[10];

void hladaj(int q, int kolko){
   mark[q]=true;
   if(kolko==n) if(!h[q][0]) res++;
   FOR(i,n) if(!h[q][i]) if(!mark[i]) hladaj(i,kolko+1);
   mark[q]=false;
}

void solve(){
   scanf("%d %d",&n,&m);
   CL(h); CL(mark);
   while(m--){
      int a,b; scanf("%d %d",&a,&b);      
      a--; b--;
      h[a][b]=h[b][a]=true;
   }
   res=0;
   hladaj(0,1);
   res/=2;
   printf("%d\n",res%MODU);
}

main(){
  int pvs; scanf("%d",&pvs);
  FR(ppp,1,pvs+1){
     printf("Case #%d: ",ppp);

     solve();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
