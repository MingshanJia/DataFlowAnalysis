#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

long long x[N], t[N], z[N];
pair <long long, int> p[N];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int cnt;
    scanf("%d", &cnt);
    vector < pair <int, int> > a;
    while (cnt--) {
      int d, h, m;
      scanf("%d %d %d", &d, &h, &m);
      for (int i = 0; i < h; i++) {
        a.push_back(make_pair(d, m));
        m++;
      }
    }
    sort(a.begin(), a.end());
    int n = a.size();
    for (int i = 0; i < n; i++) {
      x[i] = a[i].first;
      t[i] = a[i].second;
      z[i] = (360 - x[i]) * t[i];
      cerr << i << " -> " << 360 * t[i] << " " << z[i] << endl;
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
      vector < pair <long long, int> > b;
      for (int j = 0; j < n; j++) {
        long long u = z[j];
/*        while (u > z[i]) {
          u -= 360 * t[j];
        }
        while (u <= z[i]) {
          u += 360 * t[j];
        }*/
        for (int it = 0; it < 2 * n; it++) {
          b.push_back(make_pair(u, it == 0 ? -1 : 1));
          u += 360 * t[j];
        }
      }
      sort(b.begin(), b.end());
      int bs = b.size();
      for (int q = 0; q < bs; q++) {
//        cerr << "i = " << i << endl;
//        cerr << "q = " << q << ": " << b[q].first << " " << b[q].second << endl;
      }
      int cur = n;
      for (int q = 0; q < bs; q++) {
        cur += b[q].second;
        if (q + 1 < bs && b[q].first != b[q + 1].first) {
          ans = min(ans, cur);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
