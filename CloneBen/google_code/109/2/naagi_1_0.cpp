#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define abs(x) (((x)<0)?(-(x)):(x))

using namespace std;

int main (void)
{
  int test, tests;
  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int d, k, n;
    scanf ("%d %d %d", &d, &k, &n);
    n %= d/2;

    int y, z;
    if (k % 2 == 0)
    {
      y = (((k - 1 - 2LL * n) % d) + d - 1) % d + 1;
      z = (y + 1) % d + 1;
    }
    else
    {
      y = (((k - 1 + 2LL * n) % d) + d - 1) % d + 1;
      z = (y + 1) % d + 1;
    }
    printf ("Case #%d: %d %d\n", test + 1, z, y);
  }
  return 0;
}
