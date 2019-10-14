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

int main() {
  int T; scanf("%d", &T);
  for (int Ti = 1; Ti <= T; ++Ti) {
    int n, k; scanf("%d %d", &n, &k);
    k &= (1 << n) - 1;
    if (k + 1 != (1 << n)) printf("Case #%d: OFF\n", Ti);
    else printf("Case #%d: ON\n", Ti);
  }
  return 0;
}
