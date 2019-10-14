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

const int N = 4000;

int dp[N + 10];

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cerr << "testCase: " << t << "\n";
    printf("Case #%d: ", t);
    map<string, int> M;
    int V, S;
    cin >> V >> S;
    string s;
    while (V--) {
      cin >> s;
      sort(all(s));
      M[s]++;
    }
    while (S--) {
      memset(dp, 0, sizeof dp);
      dp[0] = 1;
      cin >> s; s = "#" + s;
      for (int i = 1; i < s.size(); ++i) {
        string t = "";
        for (int j = i, cnt = 20; j >= 1 && cnt > 0; --j, --cnt) {
          t = t + s[j];
          sort(all(t));
          if (M.find(t) != M.end()) {
            dp[i] = (dp[j - 1] * 1LL * M[t] + dp[i]) % MOD;
          }
        }
      }
      cout << dp[s.size() - 1] << " ";
    }
    cout << "\n";
  }
  return 0;
}