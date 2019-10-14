#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define abs(x) (((x)<0)?(-(x)):(x))

using namespace std;

const int MaxN = 123;

int a [2 * MaxN], b[MaxN];
              
int main (void)
{
  int test, tests;
  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int i, n;
    scanf ("%d", &n);
    for (i = 0; i < 2 * n; i++)
      scanf ("%d", &a[i]);
    sort (a, a + 2 * n);
    int j, k = 0;
    for (i = 0; i < 2 * n; i++)
    {
      if (a[i] == 0)
        continue;
      b[k++] = a[i];
      for (j = i+1; j < 2 * n; j++)
        if (a[j] % 4 == 0 && a[j] / 4 * 3 == a[i])   
        {
          a[j] = 0;
          break;
        }
    }
    
    printf ("Case #%d:", test + 1);
    for (i = 0; i < n; i++)
      printf (" %d", b[i]);
    printf ("\n");
  }
  return 0;
}
