#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <sstream>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define eps 1e-9

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define sz(v)((v).size())

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

using namespace std;

int a[110], b[110];

int main( void )
{
  int tn;
  scanf("%d", &tn);

  for (int tt = 1; tt <= tn; tt++)
  {
    printf("Case #%d: ", tt);

    int n;
    scanf("%d", &n);
    string s;
    for (int i = 0; i < n; i++)
    {
      cin >> s;
      int t = n - 1;
      while (t && s[t] == '0') t--;
      a[i] = t;
    }

    vector <int> p(n);
    for (int i = 0; i < n; i++)
      p[i] = i;

    int res = 10000000;
    do
    {
      for (int i = 0; i < n; i++)
        b[i] = a[p[i]];
      int ok = 1;
       
      for (int i = 0; i < n; i++)
        if (b[i] > i)
          ok = 0;
      if (ok)
      {
        int t = 0;
        for (int i = 0; i < n; i++)
          for (int j = i + 1; j < n; j++)
            if (p[i] > p[j])
              t++;
        res <?= t;
      }
    } while (next_permutation(p.begin(), p.end()));



    printf("%d\n", res);
  }

   
  
  return 0;
}