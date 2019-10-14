#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 30;

char a[MAX][MAX];

bool rec(int sw, int sm, int N, char b[MAX][MAX]) {
  if (sw == (1<<N)-1) return true;
  REP(i, N)
    if ((sw & (1<<i)) == 0) {
      bool can = false;
      REP(j, N)
        if (b[i][j] && !(sm & (1<<j))) {
          can = true;
          if (!rec(sw | (1<<i), sm | (1<<j), N, b)) return false;
        }
      if (!can) return false;
    }
  return true;
}

int main(void) {
  int TC;
  scanf("%d", &TC);
  for (int tp = 1; tp <= TC; ++tp, fflush(stdout)) {
    int N;
    scanf("%d", &N);
    REP(i, N) {
      scanf("%s", a[i]);
      REP(j, N) a[i][j] -= '0';
    }

    int ans = N*N;
    REP(s, 1<<(N*N)) {
      static char b[MAX][MAX];
      REP(i, N) REP(j, N) b[i][j] = (s >> (i*N+j)) & 1;

      int cnt = 0;
      bool ok = true;
      REP(i, N) REP(j, N) {
        if (a[i][j] && !b[i][j]) ok = false;
        if (!a[i][j] && b[i][j]) cnt++;
      }
      if (!ok) continue;
      
      if (rec(0, 0, N, b)) {
        ans = min(ans, cnt);
      }
    }
    
    printf("Case #%d: ", tp);
    printf("%d\n", ans);
  }
  return 0;
}
