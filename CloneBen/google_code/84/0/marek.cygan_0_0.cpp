#include <cassert>
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

inline int between(LL a, LL b, LL c){
  return a >= b && a <= c;
}

int licz(int p, int a, int ogr, const VI &v, int &next){
  assert(0 <= a && a < p);
  if (SIZE(v) == 1) return 2;
  FOREACH(it, v) if (*it >= p) return 0;
  int b = v[1] + p - ((LL)v[0] * a) % p;
  b %= p;
  REP(i,SIZE(v)-1){
    LL x = (LL)v[i] * a + b;
    x %= p;
    if (v[i+1] != x) return 0;
  }
  int kand = ((LL)v.back() * (LL)a + b)% p;
  if (kand != next){
    next = kand;
    return 1;
  }
  return 0;
}

const int N = 1100 * 1000;
int prime[N];

void init(){
  REP(i,N) prime[i] = 1;
  prime[0] = prime[1] = 0;
  FOR(i,2,N-1) if (prime[i]){
    for (int j = 2*i; j < N; j += i) prime[j] = 0;
  }
}

int main(){
  init();
  int testy;
  scanf("%d",&testy);
  int numer=0;
  while (testy--){
    printf("Case #%d: ",++numer);
    int d,n;
    scanf("%d %d",&d,&n);
    VI v;
    REP(i,n){
      int x;
      scanf("%d",&x);
      v.PB(x);
    }
    int ogr = 1;
    REP(foo,d) ogr *= 10;
    int next = -1;
    int mozliwosci = 0;
    FOR(p,2,ogr) if (prime[p]){
      REP(a, p) {
        mozliwosci += licz(p, a, ogr, v, next);
//        printf("p = %d, a = %d, mozliwosci = %d, next = %d\n", p, a, mozliwosci, next);
        if (mozliwosci >= 2) goto hell;
      }
    }
hell:
    assert(mozliwosci > 0 && (mozliwosci >= 2 || next >= 0));
    if (mozliwosci >= 2) puts("I don't know.");
    else printf("%d\n",next);
    fflush(stdout);
  }
  return 0;
}
