#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int rationalNum(vector<bool> &hasDigit, int num) {
  int len = 0;
  while (num != 0) {
    int digit = num % 10;
    if (!hasDigit[digit]) return -1;
    num /= 10;
    len++;
  }
  return len;
}

int dfs(map<int, int> &dp, vector<bool> &hasDigit, int num) {
  if (dp.find(num) != dp.end()) return dp[num];
  int len = rationalNum(hasDigit, num);
  if (len != -1) {
    return len;
  }
  int maxFactor = sqrt(num);
  int minLen = -1;
  for (int i = 2; i <= maxFactor; ++i) {
    if (num % i == 0) {
      int len1 = dfs(dp, hasDigit, i);
      dp.insert(make_pair(i, len1));
      int len2 = dfs(dp, hasDigit, num / i);
      dp.insert(make_pair(num / i, len2));
      if (len1 != -1 && len2 != -1) {
        if (minLen == -1) minLen = len1 + len2 + 1;
        else {
          minLen = min(minLen, len1 + len2 + 1);
        }
      }
    }
  }
  return minLen;
}

int main() {
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("C-small-attempt0.out", "w", stdout);

  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    vector<bool> hasDigit(10, false);
    for (int j = 0; j < 10; ++j) {
      int good;
      cin >> good;
      if (good == 1) hasDigit[j] = true;
    }
    int X;
    cin >> X;
    // find solutions
    map<int, int> dp;
    int minLen = dfs(dp, hasDigit, X);
    if (minLen != -1) {
      cout << "Case #" << i + 1 << ": " << minLen + 1 << endl;
    }
    else {
      cout << "Case #" << i + 1 << ": Impossible" << endl;
    }
  }
  return 1;
}