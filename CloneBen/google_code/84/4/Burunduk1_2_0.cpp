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

const int maxn = 203;

int n;
map <int, int> m1, m2;

int main()
{
  int tn;
  scanf("%d", &tn);
  for (int tt = 1; tt <= tn; tt++)
  {
    fprintf(stderr, "%d\n", tt);
    scanf("%d", &n);

    m1.clear();
    forn(i, n)
    {
      int p, v;
      scanf("%d%d", &p, &v);
      m1[p] = v;
    }

    int cnt = 0;
    while (1)
    {
      int fail = 0;
      m2.clear();
      forit(it, m1)
      {
        int x = it->first;
        int val = it->second;
//        printf("%d,%d\n", x, val);
        if (!val)
          continue;
        if (val > 1)
          fail = 1;
        
        int half = val / 2;
        m2[x - 1] += half;
        m2[x + 1] += half;
        cnt += half;
        m2[x] += val & 1;
      }

//      printf("fail=%d\n", fail);

      if (!fail)
        break;
      m1 = m2;
    }

    printf("Case #%d: %d\n", tt, cnt);
  }
  return 0;
}
