#include <iostream>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  for (int t = 1; t <= tests; t++) {
    int L;
    cin >> L;
    long long emp = 0, level, cnt;
    for (int i = 0; i < L; i++) {
      cin >> cnt >> level;
      long long manage = level * cnt;
      emp = max(emp - manage, 0LL) + cnt;
    }
    cout << "Case #" << t << ": " << max(level + 1, emp) << "\n";
  }
  return 0;
}