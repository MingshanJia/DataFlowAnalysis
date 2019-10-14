#include <bits/stdc++.h>
using namespace std;

const int N = 400005;

int n, q;
int l[N], r[N], k[N];

int x[N], y[N], z[N];

void read() {
  scanf("%d %d", &n, &q);
  
  int a, b, c, m;
  
  scanf("%d %d", x + 0, x + 1); scanf("%d %d %d %d", &a, &b, &c, &m);
  for (int i=2; i<n; i++) {
    x[i] = (1LL * x[i-1] * a + 1LL * x[i-2] * b + c) % m;
  }
  
  scanf("%d %d", y + 0, y + 1); scanf("%d %d %d %d", &a, &b, &c, &m);
  for (int i=2; i<n; i++) {
    y[i] = (1LL * y[i-1] * a + 1LL * y[i-2] * b + c) % m;
  }
  
  scanf("%d %d", z + 0, z + 1); scanf("%d %d %d %d", &a, &b, &c, &m);
  for (int i=2; i<q; i++) {
    z[i] = (1LL * z[i-1] * a + 1LL * z[i-2] * b + c) % m;
  }
  
  for (int i=0; i<n; i++) {
    l[i] = min(x[i], y[i]) + 1;
    r[i] = max(x[i], y[i]) + 1;
  }
  
  for (int i=0; i<q; i++) {
    k[i] = z[i] + 1;
  }
}

int solve() {
  read();
  
  vector<pair<int, int>> v;
  for (int i=0; i<n; i++) {
    v.push_back({r[i], 1});
    v.push_back({l[i] - 1, -1});
  }
  sort(v.begin(), v.end(), greater<pair<int, int>>());
  
  vector<pair<int, int>> queries;
  for (int i=0; i<q; i++) {
    queries.push_back({k[i], i+1});
  }
  sort(queries.begin(), queries.end(), greater<pair<int, int>>());
  
  int cur = 0;
  int lst = 1000000005;
  long long cnt = 0;
  long long ans = 0;
  for (pair<int, int> p: v) {
    cnt += 1LL * (lst - p.first) * cur;
    while (queries.size() && cnt >= queries.back().first) {
      long long pos = (cnt - queries.back().first) / cur + p.first + 1;
      ans += pos * queries.back().second;
      // cerr << pos << " " << queries.back().second << endl;
      queries.pop_back();
    }
    
    lst = p.first;
    cur += p.second;
  }
  
  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tc=0; tc<t; ++tc) {
    printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}
