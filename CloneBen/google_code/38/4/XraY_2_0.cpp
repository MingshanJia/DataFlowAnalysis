#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1.0);

const int mod = (int) 1e9 + 7;

void add(int &x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int mult(int x, int y) {
  return (long long) x * y % mod;
}

int power(int x, int pw) {
  int res = 1;
  for (; pw; pw >>= 1) {
    if (pw & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
  }
  return res;
}

void precalc() {
}


const int maxn = 15;
int n;

int go[maxn][2][3];

int read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  for (int v = 0; v < n; ++v) {
    for (int it = 0; it < 2; ++it) {
      for (int i = 0; i < 3; ++i) {
        scanf("%d", go[v][it] + i);
      }
      --go[v][it][0];
    }
  }
  return 1;
}

int used[maxn][2];
int res;

void gen(int iter, int v, int hour) {
  if (iter == 2 * n) {
    res = min(res, hour);
    return;
  }
  for (int it = 0; it < 2; ++it) {
    if (used[v][it]) {
      continue;
    }
    used[v][it] = 1;

    int nhour = hour;
    int rem = hour % 24;
    if (rem > go[v][it][1]) {
      nhour += 24 - rem;
      rem = 0;
    }
    nhour += go[v][it][1] - rem;
    nhour += go[v][it][2];
    gen(iter + 1, go[v][it][0], nhour);
    used[v][it] = 0;
  }
}

void solve() {
  for (int i = 0; i < n; ++i) {
    used[i][0] = used[i][1] = 0;
  }
  res = inf;
  gen(0, 0, 0);
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef LOCAL
  freopen(TASK ".out", "w", stdout);
  assert(freopen(TASK ".in", "r", stdin));
#endif

  int t;
  scanf("%d", &t);
  t = 0;
  while (1) {
    if (!read()) {
      break;
    }
    printf("Case #%d: ", ++t);
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
