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

vector<int> ans[10];

int ten[10];

void gen(int pos, int len, int val, int nval, int sum, vector<int> &ans) {
  if (sum < 0 || (len - pos) * len < sum) {
    return;
  }
  if (pos == len) {
    //eprintf("%d->%d\n", val, nval);
    if (val != nval) {
      ans[nval] += ans[val];
    }
    return;
  }
  for (int c = (pos + 1 == len ? sum : 0); c <= len && c <= sum; ++c) {
    gen(pos + 1, len, val + c * ten[len - pos - 1], nval + (c ? ten[len - c] : 0), sum - c, ans);
  }
}

void precalc() {
  ten[0] = 1;
  for (int len = 1; len <= 8; ++len) {
    ten[len] = ten[len - 1] * 10;

    //eprintf("%d\n", len);
    int mx = 1;
    for (int i = 0; i < len; ++i) {
      mx *= 10;
    }
    auto &cur = ans[len];
    cur = vector<int>(mx, 1);
    for (int sum = len * len; sum; --sum) {
      gen(0, len, 0, 0, sum, cur);
    }
  }
}


char str[20];

int read() {
  if (scanf("%s", str) < 1) {
    return 0;
  }
  return 1;
}

void solve() {
  int len = (int) strlen(str);
  int val;
  sscanf(str, "%d", &val);
  printf("%d\n", ans[len][val]);
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
