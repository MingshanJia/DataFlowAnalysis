#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;

#ifdef WIN32
#define INT64 "%I64d"
#define UINT64 "%I64u"
#else
#define INT64 "%lld"
#define UINT64 "%llu"
#endif

#ifdef DEBUG
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
#else
#define eprintf(...) assert (true)
#endif

const int MaxN = 1003, MaxC = 0x3F3F3F3F, NA = -1;

struct triple
{
 int x, y, z;
};

inline bool operator < (triple a, triple b)
{
 int left, right;
 left  = a.x * a.y + (100 - a.x) * b.x * (a.y + b.y);
 right = b.x * b.y + (100 - b.x) * a.x * (a.y + b.y);
 if (left != right)
  return left < right;
 return a.z < b.z;
}

triple a [MaxN];
int n;

int main (void)
{
 int test, tests;
 int i;

 scanf (" %d ", &tests);
 for (test = 1; test <= tests; test++)
 {
  scanf (" %d", &n);
  for (i = 0; i < n; i++)
   scanf (" %d", &a[i].y);
  for (i = 0; i < n; i++)
   scanf (" %d", &a[i].x);
  for (i = 0; i < n; i++)
   a[i].z = i;

  sort (a, a + n);

  printf ("Case #%d:", test);
  for (i = 0; i < n; i++)
   printf (" %d", a[i].z);
  printf ("\n");
 }

 return 0;
}
