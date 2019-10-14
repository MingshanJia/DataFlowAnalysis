#include <bits/stdc++.h>
using namespace std;

int last[402];
int add[402*402];

long double dp[402][402 * 402];

int main() {
  last[1] = 1;
  for (int i = 2; i <= 401; i++) {
    last[i] = last[i-1] + i;
  }
  int temp = 401;
  for (int i = last[401]; i >= 1; i--) {
    if (temp > 0 && i <= last[temp - 1]) {
      temp--;
    }
    add[i] = temp;
  }
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int b, l, n; cin >> b >> l >> n;
    assert(n <= last[l]);
    for (int i = 1; i <= l; i++) {
      for (int j = 1; j <= last[i]; j++) {
        dp[i][j] = 0;
      }
    }
    dp[1][1] += 750.0 * b;
    for (int i = 1; i <= l; i++) {
      for (int j = 1; j <= last[i]; j++) {
        if (250 <= dp[i][j]) {
          double t = dp[i][j] - 250;
          dp[i + 1][j] += t / 3;
          dp[i + 1][j + add[j]] += t / 3;
          dp[i + 1][j + add[j] + 1] += t / 3; 
          dp[i][j] -= t;
        }
      }
    }
    cout << "Case #" << t << ": " << fixed << setprecision(7) << dp[l][n] << endl;
  }
  return 0;
}
