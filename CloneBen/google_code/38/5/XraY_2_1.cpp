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


const int maxn = (int) 2e3 + 10;
int n;

int go[maxn * 2][3];

int read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  for (int v = 0; v < 2 * n; ++v) {
    for (int i = 0; i < 3; ++i) {
      scanf("%d", go[v] + i);
    }
    --go[v][0];
  }
  return 1;
}

int prec[maxn * 2][2];

vector<int> edges[maxn];


int ne[maxn * 2];


int vals[maxn][2];

int type[maxn];


int pr[maxn * 2], w[maxn * 2];

int get(int v) {
  return pr[v] == v ? v : (pr[v] = get(pr[v]));
}

void join(int s, int t) {
  s = get(s), t = get(t);
  if (s == t) {
    return;
  }
  if (w[s] == w[t]) {
    ++w[s];
  }
  if (w[s] < w[t]) {
    swap(s, t);
  }
  pr[t] = s;
}

int whos[maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    edges[i].clear();
  }
  for (int i = 0; i < n * 2; ++i) {
    int u = go[i][0];
    edges[u].pb(i);
    for (int it = 0; it < 2; ++it) {
      int e = u * 2 + it;

      auto &cur = prec[i][it];
      cur = go[e][1] - ((go[i][1] + go[i][2]) % 24);
      if (cur < 0) {
        cur += 24;
      }
      //eprintf("prec[%d][%d] = %d\n", i, it, cur);
    }
  }

  for (int v = 0; v < n; ++v) {
    for (int it = 0; it < 2; ++it) {
      vals[v][it] = prec[edges[v][it]][0] + prec[edges[v][!it]][1];
    }
  }

  long long whole = 1e18;
  for (int it = 0; it < 2; ++it) {
    long long val = 0;
    for (int i = 1; i < n; ++i) {
      auto &who = whos[i];
      who = 0;
      if (vals[i][who] > vals[i][!who]) {
        who = !who;
      }
      val += vals[i][who];
      type[i] = (vals[i][who] != vals[i][!who]);
      if (type[i]) {
        assert(vals[i][!who] - vals[i][who] == 24);
      }
    }
    {
      auto &who = whos[0];
      who = it;
      val += min(prec[edges[0][it]][0] + go[1][1], prec[edges[0][!it]][1] + go[0][1]);
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 2; ++j) {
        ne[edges[i][j ^ whos[i]]] = i * 2 + j;
      }
    }

    for (int i = 0; i < n * 2; ++i) {
      pr[i] = i, w[i] = 0;
    }

    for (int i = 0; i < n * 2; ++i) {
      join(i, ne[i]);
    }

    for (int iter = 0; iter < 2; ++iter) {
      for (int v = 1; v < n; ++v) {
        if (type[v] != iter) {
          continue;
        }
        if (get(v * 2) == get(v * 2 + 1)) {
          continue;
        }
        join(v * 2, v * 2 + 1);
        if (iter) {
          val += 24;
        }
      }
    }
    whole = min(whole, val);
    //eprintf("val = %lld\n", val);
  }
  int res = whole % mod;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      add(res, go[i * 2 + j][2]);
    }
  }
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
