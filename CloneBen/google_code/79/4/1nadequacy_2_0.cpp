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

const int maxn = 105;

int a[maxn];
int n, l, r;

bool solve(int x)
{
  forn (i, n)
  {
    if (a[i] == 0) continue;
    if (!(x%a[i]==0 || a[i]%x==0)) return false;
  }
  return true;
}

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  
  int tc; scanf("%d", &tc);
  for (int tt=1; tt<=tc; ++tt)
  {
    scanf("%d %d %d", &n, &l, &r);
    forn (i, n) scanf("%d", a+i);
    int res = -1;
    for (int i=l; i<=r; ++i)
      if (solve(i))
      {
        res = i;
        break;
      }    
    printf("Case #%d: ", tt);
    if (res == -1) puts("NO");
    else printf("%d\n", res);  
  }
  
  return 0;
}
