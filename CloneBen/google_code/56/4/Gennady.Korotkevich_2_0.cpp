#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int inf = (int)1e9;

const int N = 1234567;

char c[N];
int id[N];
int f[N];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      c[i] = getchar();
      while (c[i] != 'E' && c[i] != 'L') {
        c[i] = getchar();
      }
      scanf("%d", id + i);
    }
    for (int t = 0; t < (1 << n); t++) {
      f[t] = inf;
    }
    f[0] = 0;
    for (int t = 0; t < (1 << n); t++) {
      int u = (1 << n) - 1 - t;
      int s = u;
      while (s > 0) {
        int cur = 0;
        bool ok = true;
        char prev = 'N';
        for (int i = 0; i < n; i++) {
          if (s & (1 << i)) {
            if (cur != 0 && id[i] != 0 && cur != id[i]) {
              ok = false;
              break;
            }
            if (id[i] != 0) {
              cur = id[i];
            }
            if (prev == c[i]) {
              ok = false;
              break;
            }
            prev = c[i];
          }
        }
        if (cur != 0) {
          for (int i = 0; i < n; i++) {
            if (id[i] == cur && !(s & (1 << i))) {
              ok = false;
              break;
            }
          }
        }
        if (ok) {
          int add = (prev == 'E');
          if (f[t] + add < f[t | s]) {
            f[t | s] = f[t] + add;
          }
        }
        s = (s - 1) & u;
      }
    }
    if (f[(1 << n) - 1] == inf) {
      printf("CRIME TIME\n");
    } else {
      printf("%d\n", f[(1 << n) - 1]);
    }
    fflush(stdout);
  }
  return 0;
}
