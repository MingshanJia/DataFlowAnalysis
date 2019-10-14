#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool done = false;
    while (!done) {
      done = true;
      for (int i = 0; i + 2 < (int)a.size(); i++) {
        if (a[i + 1] - a[i] == k && a[i + 2] - a[i + 1] == k) {
          done = false;
          a.erase(a.begin() + i, a.begin() + i + 3);
          break;
        }
      }
    }
    cout << "Case #" << t << ": " << a.size() << endl;
  }
  return 0;
}
