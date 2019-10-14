#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define abs(x) (((x)<0)?(-(x)):(x))

using namespace std;

const int Mod = 1000000007;

const int MaxN = 555;

long long dp[MaxN][2];

int main (void)
{
  int test, tests;
  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int c, v, l;
    scanf ("%d %d %d", &c, &v, &l);
    memset (dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 1; i <= l; i++)
    {
      dp[i][0] = (dp[i-1][0] + dp[i-1][1]) * v % Mod;
      dp[i][1] = dp[i-1][0] * c % Mod;
    }
    printf ("Case #%d: %d\n", test + 1, (int) (dp[l][0] % Mod));
  }
  return 0;
}
