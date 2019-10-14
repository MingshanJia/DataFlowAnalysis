#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int maxn = 103;

ll L;
int n, b[maxn];
int f[maxn * maxn];

int main()
{
  int tn;
  scanf("%d", &tn);
  for (int tt = 1; tt <= tn; tt++)
  {
    fprintf(stderr, "%d\n", tt);
    scanf("%I64d%d", &L, &n);
   
    int ma = 0;
    forn(i, n)
      scanf("%d", &b[i]), ma = max(ma, b[i]);

    memset(f, 0x10, sizeof(f));
    f[0] = 0;
    forn(i, ma * ma + 1)
      forn(j, n)
        f[i + b[j]] = min(f[i + b[j]], f[i] + 1);

    ll ans = (L + ma - 1) / ma - ma;
    int rest = L - ans * ma;

    printf("Case #%d: ", tt);
    if (f[rest] > rest)
      puts("IMPOSSIBLE");
    else
      printf("%I64d\n", ans + f[rest]);
  }
  return 0;
}
