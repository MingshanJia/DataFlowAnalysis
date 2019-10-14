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
   
    freopen("B-large.in","r",stdin);
    freopen("b.out","w",stdout);
   
   
     int c;
     scanf("%d",&c);
     REP(k,c) {
         int numtowns, office;
         scanf("%d %d",&numtowns, &office);
         int emp;
         scanf("%d",&emp);
         vector<int> home, pass;
         REP(i,emp) {
                    int a,b;
                    scanf("%d",&a); scanf("%d",&b);
                    home.PB(a); pass.PB(b);           
         }
         int count = 0;
         bool impo = false;
         vector<int> res;
          printf("Case #%d:",k+1);
         for(int i = 1; i <= numtowns; i++) {
               
              int curt = i;
              vector<int> mrkoub;
              int numHab = 0;
              REP(j,home.size()) if(home[j] == curt && home[j]!= office) mrkoub.PB(pass[j]), numHab++;
              //printf("town=%d numhab=%d\n",i, numHab);
              sort(rALL(mrkoub));
              int cars = 0;
              REP(v,mrkoub.size()) {
                  if(numHab <=0) break;
                  numHab -= mrkoub[v];                                      
                  cars++;
              }
              if(numHab > 0) {
                 impo = true; break;                         
              }
              count+=cars;
              res.PB(cars);
//              printf(" %d",cars);
         }
        
         if(impo == true) printf(" IMPOSSIBLE");
         else {
              
              for(int e = 0; e < res.size(); e++) printf(" %d",res[e]);     
         }
         printf("\n");
     }

     return 0;
}
