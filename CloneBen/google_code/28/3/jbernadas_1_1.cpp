#include "assert.h"
#include "ctype.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"
#include "algorithm"
#include "numeric"
#include "functional"
#include "bitset"
#include "vector"
#include "list"
#include "set"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "sstream"
#include "iostream"
using namespace std;

#ifndef ONLINE_JUDGE
#pragma warning(disable:4786)  // long identifiers
#pragma warning(disable:4996)  // deprecations
#endif

typedef long long i64;

//////////////////////////////////////////////////////////////////////////////////////////

int coverMasks[15][15];
int memo[1 << 15];

int GetCoverMask(const vector<int>& x, const vector<int>& y, int px, int py, int size) {
  int mask = 0;
  for (int i = 0; i < (int)x.size(); ++i)
    if (px <= x[i] && x[i] <= px + size && py <= y[i] && y[i] <= py + size)
      mask |= 1 << i;
  return mask;
}

int GetMinSquares(const vector<int>& x, const vector<int>& y, const vector<int>& cx, const vector<int>& cy, int size, int mask) {
  if (mask == 0) return 0;
  int& best = memo[mask];
  if (best != -1) return best;
  best = INT_MAX;
  for (int i = 0; i < (int)cx.size(); ++i) for (int j = 0; j < (int)cy.size(); ++j) {
    const int coverMask = coverMasks[i][j], nmask = mask & ~coverMask;
    if (nmask != mask) best = min(best, GetMinSquares(x, y, cx, cy, size, nmask) + 1);
  }
  return best;
}

bool IsPossible(const vector<int>& x, const vector<int>& y, const vector<int>& cx, const vector<int>& cy, int size, int k) {
  const int n = (int)x.size();
  for (int i = 0; i < (int)cx.size(); ++i) for (int j = 0; j < (int)cy.size(); ++j)
    coverMasks[i][j] = GetCoverMask(x, y, cx[i], cy[j], size);
  memset(memo, -1, sizeof(memo));
  return GetMinSquares(x, y, cx, cy, size, (1 << n) - 1) <= k;
}

int FindMinSize(const vector<int>& x, const vector<int>& y, int k) {
  const int n = (int)x.size();
  vector<int> cx(x), cy(y), sizes;
  for (int i = 0; i < n - 1; ++i) for (int j = i + 1; j < n; ++j) {
    sizes.push_back(abs(x[i] - x[j]));
    sizes.push_back(abs(y[i] - y[j]));
  }
  sort(cx.begin(), cx.end()); cx.erase(unique(cx.begin(), cx.end()), cx.end());
  sort(cy.begin(), cy.end()); cy.erase(unique(cy.begin(), cy.end()), cy.end());
  sort(sizes.begin(), sizes.end()); sizes.erase(unique(sizes.begin(), sizes.end()), sizes.end());
  int low = 0, high = (int)sizes.size();
  while (low < high) {
    const int mid = (low + high) / 2;
    const bool ok = IsPossible(x, y, cx, cy, sizes[mid], k);
    if (ok) high = mid;
    else low = mid + 1;
  }
  return sizes[low];
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int T; scanf("%d", &T);
  for (int Ti = 1; Ti <= T; ++Ti) {
    int n, k; scanf("%d %d", &n, &k);
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
      scanf("%d %d", &x[i], &y[i]);
    const int res = FindMinSize(x, y, k);
    printf("Case #%d: %d\n", Ti, res);
  }
  return 0;
}
