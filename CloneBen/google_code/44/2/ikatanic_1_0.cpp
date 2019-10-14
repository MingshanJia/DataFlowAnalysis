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

const int MAX = 222;

double p[MAX];

int main(void) {
  int TC;
  scanf("%d", &TC);
  for (int tp = 1; tp <= TC; ++tp, fflush(stdout)) {
    int n, k;
    scanf("%d %d", &n, &k);
    REP(i, n) scanf("%lf", &p[i]);

    double ans = 0;
    REP(s, 1<<n) {
      vector<int> a;
      REP(i, n) if (s & (1<<i)) a.push_back(i);
      if ((int)a.size() == k) {
        double total = 0;
        REP(ms, 1<<k) {
          double prob = 1;
          int bal = 0;
          REP(i, k)
            if (ms & (1<<i)) prob *= p[a[i]], bal++;
            else prob *= 1 - p[a[i]], bal--;
          if (bal == 0) total += prob;
        }
        ans = max(ans, total);
      }
    }
    printf("Case #%d: ", tp);
    printf("%.12lf\n", ans);
  }
  return 0;
}
