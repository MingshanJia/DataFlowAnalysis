#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
//#define TASKNAME ""

#ifdef DEBUG
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define sz(x) ((int)(x).size())

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<pii> vpii;

//const int inf = 1e9;
const double eps = 1e-7;
//const int INF = inf;
const double EPS = eps;

#ifdef DEBUG
struct __timestamper {
	~__timestamper(){
		TIMESTAMP(end);
	}
} __Timestamper;
#else
struct __timestamper {};
#endif

/*Template end*/

const int MAXN = 10;
int facs[MAXN + 1];
vi cache[MAXN + 1];

int getId(const vi &as) {
  int ans = 0;
  for (int i = 0; i < sz(as); i++) {
    int id = 0;
    for (int i2 = i + 1; i2 < sz(as); i2++)
      id += as[i2] < as[i];
    ans += id * facs[sz(as) - i - 1];
  }
  assert(0 <= ans && ans < facs[sz(as)]);
  return ans;
}

bool isok(const vi &a) {
  int mid = 0;
  while (mid + 1 < sz(a) && a[mid] < a[mid + 1]) mid++;
  while (mid + 1 < sz(a) && a[mid] > a[mid + 1]) mid++;
  return mid == sz(a) - 1;
}

void precalc() {
  facs[0] = 1;
  for (int i = 1; i <= MAXN; i++)
    facs[i] = facs[i - 1] * i;

  for (int n = 1; n <= MAXN; n++) {
    cache[n] = vi(facs[n], -1);

    deque<vi> q;
    vi cur(n);
    for (int i = 0; i < n; i++) cur[i] = i;
    do {
      if (!isok(cur)) continue;
      cache[n][getId(cur)] = 0;
      q.pb(cur);
    } while (next_permutation(cur.begin(), cur.end()));

    while (!q.empty()) {
      vi v = q.front(); q.pop_front();
      int od = cache[n][getId(v)];
      assert(od >= 0);

      for (int i = 0; i + 1 < n; i++) {
        swap(v[i], v[i + 1]);
        int nid = getId(v);
        if (cache[n][nid] < 0) {
          cache[n][nid] = od + 1;
          q.pb(v);
        }
        swap(v[i], v[i + 1]);
      }
    }
  }
}

void solve() {
  int n;
  scanf("%d", &n);
  vi as(n);
  for (int &x : as) scanf("%d", &x);

  vi vals = as;
  sort(vals.begin(), vals.end());
  assert(unique(vals.begin(), vals.end()) == vals.end());
  for (int &x : as)
    x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();

  printf("%d\n", cache[n][getId(as)]);
}

bool endsWith(string a, string b) {
  return a.length() >= b.length() && string(a, a.length() - b.length()) == b;
}

int main(int argc, char *argv[]) {
  {
    string fn = "";
    if (argc >= 2) fn = argv[1];
    if (endsWith(fn, ".in")) fn = string(fn, 0, fn.length() - 3);
    freopen((fn + ".in").c_str(), "r", stdin);
    freopen((fn + ".out").c_str(), "w", stdout);
  }

  precalc();

  int TC;
  assert(scanf("%d", &TC) >= 1);
  for (int TN = 1; TN <= TC; TN++) {
    eprintf("Case #%d:\n", TN);
    printf("Case #%d: ", TN);
    try {
      solve();
    } catch (...) {
      eprintf("Caught exception at test case #%d\n", TN);
      return 1;
    }
  }
  return 0;
}
