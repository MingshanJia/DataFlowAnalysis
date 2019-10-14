#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MaxN = 123;

int a[MaxN], b[MaxN], u[MaxN];
              
int main (void)
{
  int test, tests;
  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int i, j, f, s;
    scanf ("%d %d", &f, &s);
    for (i = 0; i < f; i++)
      scanf ("%d %d", &a[i], &b[i]);
    
    int res = 0;
    for (i = 1; i <= s; i++)
    {
      memset (u, 0, sizeof (u));
      for (j = 0; j < f; j++)
        if (a[j] == i || b[j] == i)
          u[a[j] + b[j] - i] = 1;
      int tres = 0;
      for (j = 1; j <= s; j++)
        tres += u[j];
      res = max (res, tres);
    }

    printf ("Case #%d: %d\n", test + 1, res);
  }
  return 0;
}
