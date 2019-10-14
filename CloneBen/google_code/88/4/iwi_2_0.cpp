#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>

#ifdef _OPENMP
#include <omp.h>
#endif

using namespace std;

#define BEGIN_SOLVER struct solver {
#define END_SOLVER };

const int MAX_OUT = 1000;
const char *OUTPUT_FORMAT = "Case #%d: %s"; //"Case #%d:\n%s";
 
#define all(c) (c).begin(), (c).end() 
#define iter(c) __typeof((c).begin())
#define present(c, e) ((c).find((e)) != (c).end()) 
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 50;
bool dp[N + 1][N + 1];

const int M = 1000000;
int res[1000010];

void init() {
  res[0] = 1;
  
  int b = 1;
  for (int a = 1; a <= M; a++) {
    for (;;) {
      for (int k = 1; a * k <= b; k++) {
        int tb = b - a * k;
        if (a <= tb) goto ok;
        else if (a < res[tb]) goto ok;
      }
      b++;
    }
  ok:
    res[a] = b;
  }
  

  /*
  for (int a = 1; a <= N; a++) dp[0][a] = true;
  for (int a = 1; a <= N; a++) {
    for (int b = a; b <= N; b++) {
      dp[a][b] = false;
      for (int k = 1; a * k <= b; k++) {
        int ta = a, tb = b - a * k;
        if (tb < ta) swap(ta, tb);
        if (!dp[ta][tb]) dp[a][b] = true;
      }
    }
  }

  for (int a = 0; a <= N; a++) {
    int b;
    for (b = a; b <= N; b++) if (dp[a][b]) break;
    printf("%3d: %d %d\n", a, b, res[a]);
    continue;
  }
  */
}



BEGIN_SOLVER ///////////////////////////////////////////////////////////////////

int A1, A2, B1, B2;

void input() {
  scanf("%d%d%d%d", &A1, &A2, &B1, &B2);
}


void solve() {
  ll ans = 0;
  
  rep (d, 2) {
    for (int a = A1; a <= A2; a++) {
      int b = max(a, B1);
      b = max(b, res[a]);
      ans += max(0, B2 - b + 1);
    }
    
    swap(A1, B1);
    swap(A2, B2);
  }

  printf("%lld\n", ans);
}










////////////////////////////////////////////////////////////////////////////////
// Template
////////////////////////////////////////////////////////////////////////////////
  
char out_buf[MAX_OUT], *out_p;
  
solver() : out_p(NULL) {}


  
void printf(const char* format, ...)
  __attribute__((format(printf, 2, 3)))
{
  if (!out_p) out_p = out_buf;
    
  va_list args;
  va_start(args, format);
  out_p += vsnprintf(out_p, sizeof(char) * (MAX_OUT - (out_p - out_buf)), format, args);
  va_end(args);

  if (out_p - out_buf >= MAX_OUT) {
    fprintf(stderr, "error: Output Limit Exceeded !!\n");
    exit(EXIT_FAILURE);
  }
}



void puts(const char *s) {
  printf("%s\n", s);
}



void debug(const char* format, ...) 
  __attribute__((format(printf, 2, 3)))
{
  va_list args;
  va_start(args, format);
  vfprintf(stderr, format, args);
  va_end(args);
}


END_SOLVER /////////////////////////////////////////////////////////////////////


double sec() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec * 1e-6;
}



void print_status(int c, int C, double t0, double t1, int nth) {
  static const int L = 20;
  if (C > L && c % (C / L) != 0) return;
  else if (c - (nth - 1) / 2 <= 0) fprintf(stderr, "[ case: %d / %d ]\n", c, C);
  else {
    double t = sec();
    fprintf(stderr, "[ case: %d / %d | time: %.3f / %.3f ]\n",
            c, C, t - t0, (t1 - t0) + (t - t1) / (c - (nth - 1) / 2) * C);
  }
}



int main(int argc, char **argv) {
  bool parallel = false, status = false;
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-p") == 0) parallel = true;
    else if (strcmp(argv[i], "-s") == 0) status = true;
    else {
      fprintf(stderr, "usage: %s [-p] [-s]\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }

  double t0 = sec();
  init();
  double t1 = sec();
  if (status) fprintf(stderr, "[ init: %.3f ]\n", t1 - t0);
  
  int C;
  scanf("%d", &C);
  
  if (!parallel) {
    if (status) fprintf(stderr, "[ mode: single thread ]\n");
    
    rep (c, C) {
      if (status) print_status(c, C, t0, t1, 1);
      
      solver *s = new solver();
      assert(s != NULL);
      s->input();
      s->solve();
      printf(OUTPUT_FORMAT, c + 1, s->out_buf);
      delete s;
    }
  }
  else {
#ifdef _OPENMP

    int nth = omp_get_max_threads();
    if (status) fprintf(stderr, "[ mode: parallel (%d) ]\n", nth);

    vector<string> out(C);
    int done = 0;
    omp_lock_t lock;
    omp_init_lock(&lock);
    
#pragma omp parallel for schedule(dynamic, 1)
    rep (c, C) {
      solver *s = new solver();
      assert(s != NULL);

      omp_set_lock(&lock);
      if (status) print_status(done, C, t0, t1, nth);
      int myid = done++;
      s->input();
      omp_unset_lock(&lock);

      s->solve();

      out[myid] = s->out_buf;
      delete s;
    }

    omp_destroy_lock(&lock);

    rep (c, C) {
      printf(OUTPUT_FORMAT, c + 1, out[c].c_str());
    }
    
#else
    fprintf(stderr, "error: compile with -fopenmp !!\n");
#endif
  }

  exit(EXIT_SUCCESS);
}
