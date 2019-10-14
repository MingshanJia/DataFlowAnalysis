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

set<string> lol;
map<string, vector<string> > adj;
char u[100005];
char v[100005];
map<string, bool> done;
bool fail = 0;

void dfs(string u) {
  bool col = done[u];
  FORIT(it, adj[u]) {
    string v = (*it);
    if (done.count(v)==0) {
      done[v] = !col;
      dfs(v);
    }
    else {
      if (done[v] == col) {
        fail = 1;
      }
    }
  }
}

int main() {
  int t,tc=0;
  scanf("%d",&t);
  while(t--) {
    lol.clear();
    done.clear();
    adj.clear();
    fail = 0;
    tc++;
    int n;
    scanf("%d",&n);
    FOR(a,1,n) {
      scanf("%s %s", u, v);
      lol.insert(u);
      lol.insert(v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    FORIT(it, lol) {
      if (done.count(*it) == 0) {
        done[*it] = 0;
        dfs((*it));
      }
    }
    printf("Case #%d: ", tc);
    puts(!fail?"Yes":"No");
  }
}