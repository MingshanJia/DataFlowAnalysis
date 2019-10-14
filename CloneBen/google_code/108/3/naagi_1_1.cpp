#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MaxN = 123;

double p [2 * MaxN];
              
int main (void)
{
  int test, tests;
  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int i, n;
    scanf ("%d", &n);
    for (i = 0; i < 2 * n; i++)
      scanf ("%lf", &p[i]);
    sort (p, p + 2 * n);
    double res = 1;
    for (i = 0; i < n; i++)
    {
      res *= ((1 - p[i]) + (1 - p[2 * n - i - 1]) - (1 - p[i]) * (1 - p[2 * n - i - 1]));
//      res2 *= ((1 - p[i]) + (1 - p[i + n]) - (1 - p[i]) * (1 - p[i + n])); 
    }
    printf ("Case #%d: %.12lf\n", test + 1, res);
  }
  return 0;
}
