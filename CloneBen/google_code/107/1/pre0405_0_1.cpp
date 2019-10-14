#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> A;

int main() {
  int tests;
  cin >> tests;
  for (int t = 1; t <= tests; t++) {
    int n;
    cin >> n;
    A.clear();
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      A.push_back(x);
    }
    sort(A.begin(), A.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int tmp = i / 2;
      ans += (tmp - A[i]) * (tmp - A[i]);
    }
    cout << "Case #" << t <<  ": " << ans << "\n";
  }
  return 0;
}