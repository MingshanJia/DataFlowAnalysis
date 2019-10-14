#include <bits/stdc++.h>

using namespace std;

int f[1234567];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    long long n;
    cin >> n;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
      if (i % 10 == 0) {
        f[i] = f[i - 1] + 1;
        continue;
      }
      string s = "";
      int x = i;
      while (x > 0) {
        s += (char)(x % 10 + '0');
        x /= 10;
      }
      int v = 0;
      for (int j = 0; j < (int)s.size(); j++) {
        v = v * 10 + s[j] - '0';
      }
      f[i] = f[i - 1] + 1;
      if (v < i) {
        f[i] = min(f[i], f[v] + 1);
      }
    }
    printf("%d\n", f[n]);
  }
  return 0;
}
