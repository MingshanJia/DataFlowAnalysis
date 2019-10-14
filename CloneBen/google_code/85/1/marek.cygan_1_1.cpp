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

const int N = 2200;
const int K = 13;
const LL INF = 1000000000LL * 1000000000LL;
int musi[N];
int cena[N];
LL wynik[N][K];
LL nowy[N][K];

inline int between(LL a, LL b, LL c){
  return a >= b && a <= c;
}

int main(){
  int testy;
  scanf("%d",&testy);
  int numer=0;
  while (testy--){
    printf("Case #%d: ",++numer);
    int k;
    scanf("%d",&k);
    int ile = 1<<k;
    assert(ile < N);
    REP(i,ile) scanf("%d",musi+i);
    int gora = k;
    REP(runda,k){
      ile/=2;
      gora--;
      REP(i,ile) scanf("%d",cena+i);
      REP(i,ile) FOR(j,0,gora){
        //licze nowy[i][j]
        nowy[i][j] = INF;
        REP(biore,2){
          LL kand = biore ? cena[i] : 0;
          if (runda == 0){
            if (min(musi[2*i],musi[2*i+1]) < (k-j-biore)) kand = INF;
          } else {
            kand += wynik[2*i][j+biore] + wynik[2*i+1][j+biore];
          }
          nowy[i][j] = min(nowy[i][j], kand);
        }
      }
      REP(i,ile) FOR(j,0,gora) wynik[i][j] = nowy[i][j];
    }
    printf("%lld\n", wynik[0][0]);
  }
  return 0;
}
