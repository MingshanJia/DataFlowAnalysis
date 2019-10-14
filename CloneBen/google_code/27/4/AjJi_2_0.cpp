#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);(int)i<(b);i++)
#define REP(i,a) for(int i=0;i<(int)(a);i++)
#define ALL(i) i.begin(),i.end()
#define rALL(i) i.rbegin(),i.rend()
#define PB push_back

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
template<class T> string i2a(T x) {ostringstream oss; oss<<x; return oss.str();}

void printvec(vector<int> a)
{
 cout<<"Vecteur:  ";
 REP(i,a.size()) cout<<a[i]<<"  ";
 cout<<endl;
}


int main()
{
   
    freopen("C-small-attempt0.in","r",stdin);
    freopen("c.out","w",stdout);
   
     int cases;
     scanf("%d",&cases);
     REP(k,cases) {
                  int cnt = 0;
                  int probs, req;
                  scanf("%d",&probs); scanf("%d",&req);
                  vector<int> solv;
                  REP(i,probs) { int tmp; scanf("%d",&tmp); solv.PB(tmp); }
                  sort(rALL(solv));
                  while(true) {
                      bool wa = false;
                      for(int i = 0; i < req; i++) {
                              solv[i]--;    
                              if(solv[i]<0){wa = true; break;}
                      }       
                      if(wa) break;          
                      cnt++;
                      sort(rALL(solv));   
                  }
                  printf("Case #%d: %d\n",k+1,cnt);
     }
     return 0;
}
