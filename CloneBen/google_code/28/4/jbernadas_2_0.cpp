#include "assert.h"
#include "ctype.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"
#include "algorithm"
#include "numeric"
#include "functional"
#include "bitset"
#include "vector"
#include "list"
#include "set"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "sstream"
#include "iostream"
using namespace std;

#ifndef ONLINE_JUDGE
#pragma warning(disable:4786)  // long identifiers
#pragma warning(disable:4996)  // deprecations
#endif

typedef long long i64;

//////////////////////////////////////////////////////////////////////////////////////////
template <class T> T Modulo(T x, T n) {
  return (n + x % n) % n;
}
template <class T> T ExtendedGCD(T a, T b, T& x, T& y) {
  // xa + yb = GCD(a, b)
  if (b > a) return ExtendedGCD(b, a, y, x);
  if (b == 0) return x = 1, y = 0, a;
  T x1, y1, d = ExtendedGCD(b, a % b, x1, y1);
  return x = y1, y = x1 - (a / b) * y1, d;
}
template <class T> pair<T, bool> ModularInverse(T a, T b, T n) {
  // ax = b (mod n), all solutions are of the form x + k * (n / GCD(a, n))
  a = Modulo(a, n), b = Modulo(b, n);
  T x, y, d = ExtendedGCD(a, n, x, y);
  if (b % d != 0) return make_pair(0, false);
  else return make_pair(Modulo((x * b) / d, n), true);
}
//////////////////////////////////////////////////////////////////////////////////////////

const int MOD = 9901, INV = 4951;
bool graph[10][10];
int memo[10][1 << 10], n;

int f(int node, int mask) {
  if (mask == 0) return graph[node][0] ? 1 : 0;
  int& count = memo[node][mask];
  if (count != -1) return count;
  count = 0;
  for (int i = 0; i < n; ++i)
    if (graph[node][i] && (mask & (1 << i)))
      (count += f(i, mask & ~(1 << i))) %= MOD;
  return count;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int T; scanf("%d", &T);
  for (int Ti = 1; Ti <= T; ++Ti) {
    int k; scanf("%d %d", &n, &k);
    memset(graph, true, sizeof(graph));
    for (int i = 0; i < n; ++i) graph[i][i] = false;
    for (int i = 0; i < k; ++i) {
      int u, v; scanf("%d %d", &u, &v);
      graph[u - 1][v - 1] = false;
      graph[v - 1][u - 1] = false;
    }
    memset(memo, -1, sizeof(memo));
    const int res = (f(0, ((1 << n) - 1) & ~(1 << 0)) * INV) % MOD;
    printf("Case #%d: %d\n", Ti, res);
  }
  return 0;
}
