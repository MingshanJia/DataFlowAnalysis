#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9 + 7;

const int N = 101;

int C[N][N];

int dp[N][N];

int main() {
  memset(C, 0, sizeof(C));
  for (int i = 0; i < N; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = C[i-1][j] + C[i-1][j-1];
      if (C[i][j] >= MOD) {
        C[i][j] -= MOD;
      }
    }
  }
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int m, n; cin >> m >> n;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j <= n; j++) {
        if (dp[i][j] > 0) {
          for (int k = 1; k + j <= n; k++) {
            dp[i + 1][j + k] += (int)(1LL * dp[i][j] * C[j + k][j] % MOD);
            if (dp[i + 1][j + k] >= MOD) {
              dp[i + 1][j + k] -= MOD;
            }
          }
        }
      }
    }
    cout << "Case #" << t << ": " << dp[m][n] << endl;
  }
  return 0;
}
