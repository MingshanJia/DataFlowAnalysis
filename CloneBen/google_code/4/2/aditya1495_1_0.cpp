#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

typedef long long LL;
typedef pair<int, int> PII;
typedef long double LD;
typedef vector<int> VI;
typedef vector<VI> VVI;

#define all(x) (x).begin(), (x).end()
#define bitCount __builtin_popcount

const int N = 201;

int dp[N << 2];

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cerr << "testCase: " << t << "\n";
    printf("Case #%d: ", t);
    int n, m, res = 0;
    cin >> n >> m;
    if (n > m) swap(n, m);
    if (n == 2) {
      cout << (n * (m - m / 3)) << "\n";
      continue;
    }
    memset(dp, 0, sizeof dp);
    VI a(1, 0);
    for (int i = 1; i < min(n, m); ++i) a.push_back(i);
    for (int i = 0; i < abs(n - m) + 1; ++i) a.push_back(min(n, m));
    for (int i = min(n, m) - 1; i >= 1; --i) a.push_back(i);
    dp[0] = a[0];
    dp[1] = a[1];
    res = max(a[0], a[1]);
    for (int i = 2; i < a.size(); ++i) {
      dp[i] = a[i] + a[i - 1] + (i - 3 >= 0 ? dp[i - 3] : 0);
      dp[i] = max(dp[i], a[i] + dp[i - 2]);
      res = max(dp[i], res);
    }
    cout << res << "\n";
  }
  return 0;
}