#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

typedef long long ll;

using namespace std;

int main (void) {
  int tn;
  scanf ("%d", &tn);
  for (int tt = 1; tt <= tn; tt++) {
    printf ("Case #%d: ", tt);

    int n;
    cin >> n;
    ll l, r;
    cin >> l >> r;

    vector <ll> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    ll res = -1;
    for (ll x = l; x <= r; x++) {
      int i;
      for (i = 0; i < n; i++) {
        if (v[i] % x  && x % v[i]) {
          break;
        }
      }
        
      if (i == n) {
        res = x;
        break;
      }
    }
    if (res == -1) {
      puts ("NO");
    } else {
      cout << res << endl;
    }
  }
  return 0;
}