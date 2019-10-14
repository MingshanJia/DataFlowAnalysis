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

const int MaxK = 7, MaxN = 1000006, MaxC = 0x3F3F3F3F, NA = -1;

bool s [MaxN];
int a [MaxN];
int p [MaxN];
int lim [MaxK] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int n, d, k;

int main (void)
{
 int test, tests;
 int i, j, u;
 memset (s, 1, sizeof (s));
 s[0] = s[1] = false;
 for (i = 2; i * i < MaxN; i++)
  if (s[i])
   for (j = i * i; j < MaxN; j += i)
    s[j] = false;
 n = 0;
 for (i = 0; i < MaxN; i++)
  if (s[i])
   p[n++] = i;
// printf ("%d\n", n);
 scanf (" %d", &tests);
 for (test = 1; test <= tests; test++)
 {
  int ok, res;
  scanf (" %d %d", &d, &k);
  for (u = 0; u < k; u++)
   scanf (" %d", &a[u]);
  ok = (k == 1) << 1;
  res = NA;
  for (i = 0; p[i] <= lim[d] && ok <= 1; i++)
  {
   for (u = 0; u < k; u++)
    if (p[i] <= a[u])
     break;
   if (u < k)
    continue;
   for (j = 0; j < p[i] && ok <= 1; j++)
   {
    int t = ((int64) a[0] * j) % p[i];
    int r = (a[1] - t + p[i]) % p[i];
//    a[1] == (a[0] * x + y) % p;
//    a[2] == (a[1] * x + y) % p;
    for (u = 2; u < k; u++)
     if (a[u] != ((int64) a[u - 1] * j + r) % p[i])
      break;
    if (u >= k)
    {
     ok++;
     int cur = ((int64) a[k - 1] * j + r) % p[i];
//     printf ("%d %d %d: %d\n", j, r, p[i], cur);
     if (ok == 1)
      res = cur;
     else if (res == cur)
      ok--;
    }
   }
  }
  printf ("Case #%d: ", test);
  assert (ok > 0);
  if (ok > 1)
   printf ("I don't know.\n");
  else
   printf ("%d\n", res);
 }
 return 0;
}

