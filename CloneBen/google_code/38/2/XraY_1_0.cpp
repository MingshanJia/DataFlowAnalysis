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


const int maxn = (int) 1e3 + 10;
int n, m;

const int maxm = maxn * 2;
int ans[maxm];

vector<vector<int> > es, ids;

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return 0;
  }
  es = ids = vector<vector<int> >(n);
  for (int i = 0; i < m; ++i) {
    int s, t;
    scanf("%d%d", &s, &t);
    --s, --t;
    ans[i + 1] = 0;
    es[s].pb(t), ids[s].pb(i + 1);
    es[t].pb(s), ids[t].pb(-i - 1);
  }
  return 1;
}

int used[maxn];

vector<pair<int, int> > st;

void madd(int id, int toadd) {
  if (id < 0) {
    toadd = -toadd;
    id = -id;
  }
  ans[id] += toadd;
}

void dfs(int v, int pid = -1) {
  used[v] = 1;
  for (int it = 0; it < sz(es[v]); ++it) {
    if (ids[v][it] == -pid) {
      continue;
    }
    int u = es[v][it];
    if (used[u]) {
      if (used[u] == 1) {
        madd(ids[v][it], 1);
        for (int i = sz(st) - 1; i >= 0; --i) {
          madd(st[i].second, 1);
          if (st[i].first == u) {
            break;
          }
        }
      }
      continue;
    }

    st.pb({v, ids[v][it]});
    dfs(u, ids[v][it]);
    st.pop_back();
  }
  used[v] = 2;
}

void solve() {
  for (int i = 0; i < n; ++i) {
    used[i] = 0;
  }

  for (int i = 0; i < n; ++i) {
    if (used[i]) {
      continue;
    }
    st.clear();
    dfs(i);
  }

  for (int i = 1; i <= m; ++i) {
    if (!ans[i]) {
      printf("IMPOSSIBLE\n");
      return;
    }
  }
  for (int i = 1; i <= m; ++i) {
    printf("%d%c", ans[i], " \n"[i == m]);
  }
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
