#include "climits"
#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "stack"
#include "string"
#include "utility"
#include "vector"
using namespace std;
typedef long long i64;

////////////////////////////////////////////////////////////////////////////////
template <class T>
T GCD(T a, T b) {
  if (a < 0) a = -a; if (b < 0) b = -b;
  if (b > a) swap(a, b);
  while (b != 0) {a %= b; swap(a, b);}
  return a == 0 ? 1 : a;
}
template <class T>
T Modulo(T x, T n) {
  return (n + x % n) % n;
}
////////////////////////////////////////////////////////////////////////////////
int main() {
  int T; scanf("%d", &T);
  for (int Ti = 1; Ti <= T; ++Ti) {
    int n; scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    int d = v[n - 1] - v[0];
    for (int i = 0; i < n - 1; ++i)
      for (int j = i + 1; j < n; ++j)
        d = GCD(d, v[j] - v[i]);
    printf("Case #%d: %d\n", Ti, Modulo(-v[0], d));
  }
  return 0;
}
