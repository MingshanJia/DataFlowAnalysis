#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second

int isq[10010];

int solve() {
    int n;
    scanf("%d", &n);
    while ((n & 3) == 0) n >>= 2;
    if ((n & 7) == 7) return 4;
    if (isq[n] >= 0) return 1;
    int t = sqrt(n);
    REPE(i, 1, t)
      if (isq[n - i * i] >= 0) return 2;
    return 3;
}

int main() {
  memset(isq, -1, sizeof isq);
  for (int i = 0; i * i < 10010; ++i)
    isq[i * i] = i;
  int T;
  scanf("%d", &T);
  REPE(kase, 1, T) {
    printf("Case #%d: %d\n", kase, solve());
  }
  return 0;
}

