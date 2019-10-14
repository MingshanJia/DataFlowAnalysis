#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;

long long dp[202][202];

long long add(long long a, long long b) {
  if (a == INF || b == INF) {
    return INF;
  } else {
    if (a >= INF - b) {
      return INF;
    } else {
      return a + b;
    }
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0); 
  dp[100][0] = 1;
  for (int i = 99; i >= 0; i--) {
    for (int j = 0; j <= 100; j++) {
      if (dp[i + 1][j] != 0) {
        dp[i][j + 1] = add(dp[i][j + 1], dp[i + 1][j]);
        if (j > 0) {
          dp[i][j - 1] = add(dp[i][j - 1], dp[i + 1][j]);
        }
      }
    }
  }
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int n; long long k; cin >> n >> k;
    n *= 2;
    int balance = 0;
    string ans = "";
    for (int i = 0; i < n; i++) {
      if (dp[100 - n + i + 1][balance + 1] >= k) {
        balance++;
        ans += "(";
      } else {
        if (balance == 0) {
          break;
        } else {
          k -= dp[100 - n + i + 1][balance + 1];
          balance--;
          ans += ")";
        }
      }
    }
    cout << "Case #" << t << ": ";
    if (balance == 0 && (int)ans.length() == n) {
      cout << ans << endl;
    } else {
      cout << "Doesn't Exist!" << endl;
    }
  }
  return 0;
}
