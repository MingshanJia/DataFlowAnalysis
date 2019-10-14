#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

const long long MaxC = 0x3f3f3f3f3f3f3f3fLL, MaxB = 55;
long long g[MaxB][MaxB];
const double eps = 1e-9;

              
int main (void)
{
  int test, tests;
  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int i, j, k, t, b;
    scanf ("%d", &b);
    memset (g, 0, sizeof g);
    for (i = 0; i < b; i++)
      for (j = 0; j < i; j++)
      {
        scanf ("%d", &t);
        if (t != -1)
          g[i][j] = g[j][i] = t;
        else g[i][j] = g[j][i] = MaxC; 
      }


    for (k = 0; k < b; k++)
      for (i = 0; i < b; i++)
        for (j = 0; j < b; j++)
          g[i][j] = min (g[i][j], g[i][k] + g[j][k]);

/*    for (i = 0; i < b; i++, printf("\n"))
      for (j = 0; j < b; j++)
        printf ("%10lf ", (double)g[i][j]);
*/
    long double res = MaxC, tres;
    for (i = 0; i < b; i++)
    {
      tres = 0;
      for (j = 0; j < b; j++)
        tres = max (tres, g[i][j]);
      res = min (res, tres); 
    }

    for (i = 0; i < b; i++)
      for (j = 0; j < b; j++) if (i != j)
      {
        long double l = 0, r = 1, m1, m2, tres1, tres2;
        while (r - l > eps)
        {
          m1 = l + (r - l) * 1 / 3;
          m2 = l + (r - l) * 2 / 3;
          tres1 = tres2 = 0;
          for (k = 0; k < b; k++)
          {
            tres1 = max (tres1, min (g[i][k] + g[i][j] * m1, g[j][k] + g[i][j] * (1 - m1)));
            tres2 = max (tres2, min (g[i][k] + g[i][j] * m2, g[j][k] + g[i][j] * (1 - m2)));
          }
          res = min (res, min(tres1, tres2));
          if (tres2 > tres1)
            r = m2;
          else
            l = m1;
        }
        
      }   
    

    printf ("Case #%d: %.7lf\n", test + 1, (double) res);
  }
  return 0;
}
