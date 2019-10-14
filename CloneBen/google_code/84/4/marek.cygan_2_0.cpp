#include <cstring>
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

const int N = 200000;
const int K = 10;
char opis[N][K];
int przejscia[N][K];

map<VI,int> mapa;

int gen(VI &v){
  if (mapa.count(v)) return mapa[v];
  REP(i,K){
    if (v[i] < K && (i==0 || v[i-1] >= v[i]+1)){
      v[i]++; gen(v); v[i]--;
    } 
  }
  int res = SIZE(mapa);
  REP(i,K) opis[res][i] = v[i];
  mapa[v] = res;
  REP(i,K){
    if (v[i] < K && (i==0 || v[i-1] >= v[i]+1)){
      v[i]++;
      przejscia[res][i] = gen(v);
      v[i]--;
    } else przejscia[res][i] = -1;
  }
  return res;
}

void init(){
  VI v(K,0);
  gen(v);
  //printf("rozmiar = %d\n", SIZE(mapa));
  /*
  FOREACH(it, mapa){
    FOREACH(it2, (it->ST)) printf("%d ",*it2);
    puts("");
  }
  */
  assert(SIZE(mapa) < N);
}

int t[N][K];
int nowy[N][K];
const int MOD = 10007;
char plansza[K+5][K+5];

int licz(int r, int c){
  memset(t,0,sizeof(t));
  int stany = SIZE(mapa);
  assert(mapa[VI(K,0)] == stany-1);
  t[stany-1][0] = 1;
  REP(litera,26){
    memset(nowy,0,sizeof(t));
    FORD(i,stany-1,0) REP(j,c) if (t[i][j] != 0){
      if (j+1 == c) nowy[i][0] = (nowy[i][0] + t[i][j]) % MOD;
      else t[i][j+1] = (t[i][j+1] + t[i][j]) % MOD;

      int x = przejscia[i][j];
      if (x >= 0){
        assert(x < i);
        if (opis[i][j] < r){
          int wiersz = opis[i][j];
          if (plansza[wiersz][j] == '.' || plansza[wiersz][j] == 'a' + litera){
            t[x][j] = (t[x][j] + t[i][j]) % MOD;
          }
        }
      }
    }
    REP(i,stany) REP(j,c) t[i][j] = nowy[i][j];
  }
  VI v(K,0);
  REP(i,c) v[i] = r;
  assert(mapa.count(v));
  int stan = mapa[v];
  return t[stan][0];
}

int main(){
  init();
  int testy;
  scanf("%d",&testy);
  int numer=0;
  while (testy--){
    printf("Case #%d: ",++numer);
    int r,c;
    scanf("%d %d",&r,&c);
    REP(i,r) scanf("%s",plansza[i]);
    printf("%d\n",licz(r,c));
    fflush(stdout);
  }
  return 0;
}
