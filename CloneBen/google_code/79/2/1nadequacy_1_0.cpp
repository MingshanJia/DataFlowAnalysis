#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
#include <string.h>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define forn(i, n) for (int i=0; i<(n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it=(a).begin(); it!=(a).end(); ++it)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 1005;
const ll inf = 1LL<<61;

ll a[maxn];
ll f[maxn][maxn];
int n, k;
ll t;

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  
  int tc; scanf("%d", &tc);
  for (int tt=1; tt<=tc; ++tt)
  {
    int c;
    cin >> k >> t >> n >> c;
    forn (i, c) cin >> a[i];
    forn (i, n) a[i] = a[i%c];
    forn (i, n+1) forn (j, k+1) f[i][j] = inf;
    f[0][0] = 0;
    forn (i, n+1) forn (j, k+1) if (f[i][j] != inf)
    {
      f[i+1][j] = min(f[i+1][j], f[i][j]+2*a[i]);
      if (t >= f[i][j]+2*a[i])
        f[i+1][j+1] = min(f[i+1][j+1], f[i][j]+2*a[i]);
      else if (t <= f[i][j])
        f[i+1][j+1] = min(f[i+1][j+1], f[i][j]+a[i]);
      else
      {
        ll q = t-f[i][j];
        ll add = a[i]-q/2+q;
        f[i+1][j+1] = min(f[i+1][j+1], f[i][j]+add);
      }  
    }
    printf("Case #%d: %lld\n", tt, f[n][k]);
  }
  
  return 0;
}
