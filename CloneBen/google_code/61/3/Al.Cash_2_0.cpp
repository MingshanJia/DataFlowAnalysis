#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <thread>
#include <mutex>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define UN(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T sqr(T a) { return a * a; }

class TestCase {
 public:
  static const int h = 55;
  int r, c, m;
  char a[h][h];

  void input() {
    scanf("%d%d%d", &r, &c, &m);
  }

  void solve() {
    int e = r * c - m;
    REP(i, r) {
      REP(j, c) a[i][j] = '*';
      a[i][c] = 0;
    }
    bool ok = false;
    if (r == 1 || c == 1) {
      ok = true;
      if (r == 1) {
        REP(i, e) a[0][i] = '.';
      } else {
        REP(i, e) a[i][0] = '.';
      }
    } else {
      if (e == 1) {
        ok = true;
      } else if (e >= 4) {
        FOR(i, 2, r+1) FOR(j, 2, c+1)
          if (2*i + 2*j - 4 <= e && e <= i*j) {
            //outp("%d %d\n", i, j);
            REP(ii, i) a[ii][0] = a[ii][1] = '.';
            REP(jj, j) a[0][jj] = a[1][jj] = '.';
            e -= 2*i + 2*j - 4;
            int x = 2, y = 2;
            while (e > 0) {
              a[x][y] = '.';
              --e;
              ++y;
              if (y == j) {
                ++x;
                y = 2;
              }
            }
            ok = true;
            break;
          }
      }
    }
    if (ok) {
      a[0][0] = 'c';
      REP(i, r) outp("%s\n", a[i]);
    } else {
      outp("Impossible\n");
    }
  }

  string out;
 private:
  static const int L = 1024;
  char buf[L+1];

  void outp(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, L, fmt, args);
    va_end(args);
    out.append(buf);
  }
};

mutex io_mutex;
int itest, ntest;
vector<string> answer;

void work() {
  while (true) {
    io_mutex.lock();
    if (itest >= ntest) {
      io_mutex.unlock();
      break;
    }
    int wtest = itest;
    ++itest;
    cerr << "Case " << wtest+1 << " started\n";
    TestCase test;
    test.input();
    io_mutex.unlock();
    test.solve();
    answer[wtest].swap(test.out);
  }
}

int main() {
  freopen("c-small-attempt0.in", "r", stdin);  // -small-attempt0
  freopen("c-small-attempt0.out", "w", stdout);  // -large
  itest = 0;
  scanf("%d", &ntest);
  answer.resize(ntest);
#ifdef MULTITHREADING
  vector<thread> threads;
  REP (i, thread::hardware_concurrency()) threads.pb(thread(work));
  REP (i, sz(threads)) threads[i].join();
  REP (i, ntest) printf("Case #%d:\n%s", i + 1, answer[i].c_str());
#else
  REP (i, ntest) {
    cerr << "Case " << i+1 << " started\n";
    TestCase test;
    test.input();
    test.solve();
    printf("Case #%d: %s\n", i + 1, test.out.c_str());
  }
#endif
  cerr << endl << endl << "TIME: " << clock() << endl;
  return 0;
}
