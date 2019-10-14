#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <numeric>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define REP(i,n) FOR(i,0,n)

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;

#define TEST_NAME "C-small"

int main() {
     freopen(TEST_NAME ".in","r",stdin);
     freopen(TEST_NAME ".out","w",stdout);
     int tn,test;
	
     for(cin>>tn,test=1;test<=tn;++test) {
          int p,q;
          int ans=INF;
          scanf("%d%d",&p,&q);
          VI pr(q);
          REP(i,q)scanf("%d",&pr[i]);
          SORT(pr);
          do {
               int cur=0;
               VI filled(p+2,1);
               filled[0]=filled[p+1]=0;
               REP(k,q) {
                    filled[pr[k]]=0;
                    for(int i=pr[k]+1;filled[i];i++,cur++);
                    for(int i=pr[k]-1;filled[i];i--,cur++);
               }
               ans=min(cur,ans);
          }while(next_permutation(ALL(pr)));
          printf("Case #%d: %d\n",test,ans);
     }
	
     fprintf(stderr,"running time=%.3lf\n",clock()/(double)CLOCKS_PER_SEC);
     return 0;
} 
