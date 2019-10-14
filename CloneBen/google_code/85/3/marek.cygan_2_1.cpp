#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
#include <cassert>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

const int N = 1100;
const int INF = 1000000000;
int wym[N][4];
int vis[N];
int n;

inline int between(LL a, LL b, LL c){
  return a >= b && a <= c;
}

int najdalszy;
int maxx, maxy;

int przecina_przedzial(int a,int b,int c,int d){
  if (b < c || d < a) return 0;
  return 1;
}

int przerwa(int a,int b,int c,int d){
  if (b + 1 < c || d + 1 < a) return 1;
  return 0;
}

int przecina(int a,int b){
  if (przecina_przedzial(wym[a][0], wym[a][2], wym[b][0], wym[b][2]) &&
         przecina_przedzial(wym[a][1], wym[a][3], wym[b][1], wym[b][3])) return 1;
  if (przerwa(wym[a][0], wym[a][2], wym[b][0], wym[b][2]) ||
         przerwa(wym[a][1], wym[a][3], wym[b][1], wym[b][3])) return 0;
  if (wym[a][0] > wym[b][0]) swap(a,b);
  if (wym[a][2]+1==wym[b][0] && wym[a][3]+1 == wym[b][1]) return 0;
  return 1;
}

void dfs(int x){
  vis[x] = 1;
  najdalszy = min(najdalszy, wym[x][0]+wym[x][1]);
  maxx = max(maxx, wym[x][2]);
  maxy = max(maxy, wym[x][3]);
  REP(j,n) if (!vis[j] && przecina(x,j)){
    dfs(j);
  }
}

int main(){
  int testy;
  scanf("%d",&testy);
  int numer=0;
  while (testy--){
    printf("Case #%d: ",++numer);
    scanf("%d",&n);
    assert(n < N);
    REP(i,n){
      REP(j,4) scanf("%d", wym[i]+j);
    }

    REP(i,n) vis[i] = 0;
    int res = 0;
    REP(i,n) REP(j,i) assert(przecina(i,j) == przecina(i,j));
    REP(i,n) if (!vis[i]){
      najdalszy = INF;
      maxx = -INF, maxy = -INF;
      dfs(i);
      res = max(res,(maxx+maxy) - najdalszy + 1);
    }
    printf("%d\n", res);
  }
  return 0;
}
