#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second

const int inf = 1e9;

int n, m, p, d[110][110];

using PDD = pair<double, double>;
using M = array<array<PDD, 101>, 101>;

M w;

M op(const M &a, const M &b) {
  M r;
  REP(i, n) REP(j, n) r[i][j] = PDD();
  REP(i, n) REP(j, n) REP(k, n) {
    double p = a[i][k].F * b[k][j].F;
    if (p <= 1e-18) continue;
    r[i][j].F += p;
    r[i][j].S += p * (a[i][k].S / a[i][k].F + b[k][j].S / b[k][j].F);
  }
  return r;
}

M f(M a, int p) {
  M r;
  REP(i, n) REP(j, n) r[i][j] = i == j ? PDD(1, 0) : PDD(0, 0);

  for (; p; p >>= 1, a = op(a, a))
    if (p & 1) r = op(r, a);
  return r;
}

double solve() {
  scanf("%d%d%d", &n, &m, &p);
  REP(i, n) REP(j, n) d[i][j] = i == j ? 0 : inf;
  REP(i, m) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    u--, v--;
    d[u][v] = min(d[u][v], w);
    d[v][u] = min(d[v][u], w);
  }
  REP(k, n) REP(i, n) REP(j, n)
    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  REP(i, n) REP(j, n) {
    if (i == j) w[i][j] = {0, 0};
    else w[i][j] = {1.0 / (n - 1), d[i][j] * 1.0 / (n - 1)};
  }
  M r = f(w, p);
  double sum = 0;
  REP(i, n) sum += r[0][i].S;
  return sum;
}

int main() {
  int T;
  scanf("%d", &T);
  REPE(kase, 1, T) printf("Case #%d: %.12f\n", kase, solve());
  return 0;
}

