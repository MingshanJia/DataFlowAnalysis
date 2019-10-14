#include <cstdio>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <iostream>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 110;
const double eps = 1e-10;

int N;
double V, X;
double R[MAX], C[MAX];

double calc(double T) {
  double vol = V;
  double c = 0;
  REP(i, N) {
    double v = min(vol, R[i] * T);
    vol -= v;
    c += C[i] * v / V;
  }
  return c;
}

bool check(double T) {
  double sum = 0;
  REP(i, N) sum += R[i] * T;
  if (sum + eps < V) return 0;

  double lo = calc(T);
  reverse(R, R+N);
  reverse(C, C+N);

  double hi = calc(T);
  reverse(R, R+N);
  reverse(C, C+N);

  return lo - eps <= X && X <= hi + eps;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt, fflush(stdout)) {
    scanf("%d%lf%lf", &N, &V, &X);
    REP(i, N) scanf("%lf%lf", R+i, C+i);

    REP(i, N) FOR(j, i+1, N) if (C[i] > C[j]) {
      swap(R[i], R[j]);
      swap(C[i], C[j]);
    }

    printf("Case #%d: ", tt);

    bool le = false, ge = false;
    REP(i, N) le |= C[i] <= X;
    REP(i, N) ge |= C[i] >= X;

    if (!le || !ge) {
      puts("IMPOSSIBLE");
      continue;
    }

    double lo = 0, hi = 1e20;
    REP(step, 1000) {
      double mid = (lo+hi) / 2;
      check(mid) ? hi = mid : lo = mid;
    }

    // if (lo > 1e19) puts("IMPOSSIBLE");
    printf("%.9lf\n", (lo+hi) / 2);
  }
  return 0;
}
