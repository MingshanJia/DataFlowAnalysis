#include <bits/stdc++.h>
using namespace std;

const int N = 7777;

int n;
long long a[N];

int solve() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%lld", a + i);
  
  map<long long, int> m;
  long long ans = 0;
  for (int i=n-2; i>=0; i--) {
    if (m.find(a[i+1]) == m.end()) {
      m[a[i+1]] = 0;
    }
    ++m[a[i+1]];
    
    for (int j=0; j<i; j++) {
      if (a[i] == 0 && a[j] == 0) {
        ans += n - i - 1;
        continue;
      }
      
      set<long long> tmp;
      
      if (m.find(a[i] * a[j]) != m.end()) {
        tmp.insert(a[i] * a[j]);
      }
      
      if (a[j] > 0 && a[i] % a[j] == 0 && m.find(a[i] / a[j]) != m.end()) {
        tmp.insert(a[i] / a[j]);
      }
      
      if (a[i] > 0 && a[j] % a[i] == 0 && m.find(a[j] / a[i]) != m.end()) {
        tmp.insert(a[j] / a[i]);
      }
      
      for (long long num: tmp) {
        ans += m[num];
      }
    }
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
