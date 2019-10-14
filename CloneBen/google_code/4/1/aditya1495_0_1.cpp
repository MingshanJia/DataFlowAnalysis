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

const int N = 2001;

LD dp[N][N];

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cerr << "testCase: " << t << "\n";
    printf("Case #%d: ", t);
    int n, m;
    cin >> n >> m;
    memset(dp, 0, sizeof dp);
    dp[1][0] = n * 1.0 / (n + m);
    for (int i = 2; i <= n; ++i) {
      dp[i][0] = dp[i - 1][0] * (n - i + 1) * 1.0 / (n + m - i + 1);
      for (int j = 1; j < i; ++j) {
        int exTot = m + n - i - j + 1;
        dp[i][j] = ((n - i + 1) * dp[i - 1][j] + (m - j + 1) * dp[i][j - 1]) / (LD)exTot;
      }
    }
    cout << fixed << setprecision(10) << dp[n][m] << "\n";
  }
  return 0;
}