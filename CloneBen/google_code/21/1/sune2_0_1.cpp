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

int main() {
  int n;
  cin >> n;
  REP(ii, n) {
    int m,c,w;
    cin>>m>>c>>w;
    int a[c], b[c];
    REP(i, c) {
      cin >> a[i] >> b[i];
    }
    int now = w;
    for (int i=c-1; i>=0; --i) {
      if (now <= b[i]) {
        now += a[i]-1;
      } else if (now < a[i] + b[i]) {
        now -= b[i];
      } else {
      }
      //cout << now << endl;
    }
    printf("Case #%d: %d\n", ii+1, now);
  }
}
