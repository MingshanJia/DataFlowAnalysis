#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;

#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

const int MaxK = 102, MaxN = 100005, MaxC = 0x3F3F3F3F, NA = -1;
const int64 MaxL = 0x3F3F3F3F3F3F3F3Fll;

typedef set <pair <int64, int> > pairset;

int64 a [MaxN];
int b [MaxK], d [MaxK];
int64 l;
int m, n;

int main (void)
{
 int test, tests;
 int64 res, r;
 int i; 
 scanf (" %d", &tests);
 for (test = 1; test <= tests; test++)
 {
  scanf (" " INT64 " %d", &l, &n);
  m = NA;
  for (i = 0; i < n; i++)
  {
   scanf (" %d", &b[i]);
   m = max (m, b[i]);
  }
  for (i = 0; i < n; i++)
   d[i] = m - b[i];
  
  r = l % m;

  memset (a, (char) MaxL, sizeof (a));  
  pairset s;
  s.insert (make_pair (0, 0));
  for (i = 1; i < m; i++)
   s.insert (make_pair (MaxL, i));
  a[0] = 0;
  while (!s.empty ())
  {
   pairset :: iterator cur = s.lower_bound (make_pair (NA, NA));
   int64 curx = cur -> first;
   int cury = cur -> second;
//   printf ("%d " INT64 " %d\n", s.size (), curx, cury);
   s.erase (cur);
   for (i = 0; i < n; i++)
   {
    int64 nextx = curx + d[i];
    int nexty = cury + b[i];
    if (nexty >= m) nexty -= m;
    if (a[nexty] > nextx)
    {
//     printf ("%d: " INT64 " -> " INT64 "\n", nexty, a[nexty], nextx);
     s.erase (make_pair (a[nexty], nexty));
     s.insert (make_pair (nextx, nexty));
     a[nexty] = nextx;
    }
   }
  }
  printf ("Case #%d: ", test);
  if (a[r] >= MaxL)
   printf ("IMPOSSIBLE\n");
  else
  {
   assert ((l + a[r]) % m == 0);
   res = (l + a[r]) / m;
   printf (INT64 "\n", res);
  }
 }
 return 0;
}

