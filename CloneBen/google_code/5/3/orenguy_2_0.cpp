#include <bits/stdc++.h>

using namespace std;

typedef long long     LL;
typedef pair<int,int> pii;

double PI  = acos(-1);
double EPS = 1e-7;
int INF    = 1000000000;
LL INFLL   = 1000000000000000000LL;

#define fi            first
#define se            second
#define mp            make_pair
#define pb            push_back

#define input(in)     freopen(in,"r",stdin)
#define output(out)   freopen(out,"w",stdout)

#define MIN(a, b)     (a) = min((a), (b))
#define MAX(a, b)     (a) = max((a), (b))

#define RESET(a, b)   memset(a,b,sizeof(a))
#define ALL(a)        (a).begin(), (a).end()
#define SIZE(a)       (int)a.size()
#define SORT(a)       sort(ALL(a))
#define UNIQUE(a)     (a).erase( unique( ALL(a) ), (a).end() )
#define FOR(a, b, c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a, b, c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a, b)   for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); a++)

int mx[8] = {-1,1,0,0,-1,-1,1,1};
int my[8] = {0,0,-1,1,-1,1,-1,1};

// ----- //

string x[105];
char t[105];

int main() {
  int tc,T=0;
  scanf("%d",&tc);
  while(tc--) {
    T++;
    int n;
    scanf("%d",&n);
    gets(t);
    FOR(a,0,n-1) {
      gets(t);
      x[a] = t;
    }
    int ans = 0;
    FOR(a,1,n+3) {
      FOR(b,1,n-1) {
        if (x[b-1] > x[b]) {
          ans++;
          int place = 0;
          FOR(c,0,b-1) {
            if (x[c] < x[b]) {

              place++;
            }
          }
          string sav = x[b];
          FORD(c,b-1,place) {
            x[c+1] = x[c];
          }
          x[place] = sav;
        }
      }
    }
    printf("Case #%d: %d\n",T,ans);
  }
}