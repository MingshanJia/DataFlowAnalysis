#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

typedef long long ll;


int bitnum(ll a) {
  int res = 0;
  while(a) {
    if (a%2) res++;
    a >>= 1;
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  REP(ii, t) {
    ll n;
    cin >> n;
    ll a = 0;
    int res = 0;
    int ma = 0;
    while(a<=n) {
      ma = max(ma, res+bitnum(n-a));
      a = (a<<1) | 1;
      res++;
    }
    // res--;
    // cout << res << endl;
    // a >>= 1;
    // ll b = n-a;
    // res += bitnum(b);
    printf("Case #%d: %d\n", ii+1, ma);
  }
  
}
