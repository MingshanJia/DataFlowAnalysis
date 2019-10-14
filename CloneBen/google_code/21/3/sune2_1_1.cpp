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

struct P {
  ll c,t;
  int s;
};

int main() {
  int t;
  cin >> t;
  REP(ii, t) {
    int n;
    ll k;
    cin >> n >> k;
    vector<P> v(n);
    REP(i,n) {
      ll c,t,s;
      cin>>c>>t>>s;
      v[i] = (P){c,t,s};
    }
    ll day = k;
    ll res = 0;
    while(day && v.size()) {
      int ma = 0, nomu = -1;
      ll day2 = 0;
      REP(i, v.size()) {
        if (v[i].t >= day) {
          if (ma < v[i].s) {
            ma = v[i].s;
            nomu = i;
          }
        } else {
          day2 = max(day2, v[i].t);
        }
      }
      if (nomu == -1) {
        day = day2;
        continue;
      }
      ll hoge = min(min(v[nomu].c, day), day-day2);
      day -= hoge;
      res += hoge * v[nomu].s;
      v[nomu].c -= hoge;
      if (v[nomu].c == 0)
        v.erase(v.begin() + nomu);
      //cout << day << " " << res << endl;
    }
    printf("Case #%d: %lld\n", ii+1, res);
  }
}
