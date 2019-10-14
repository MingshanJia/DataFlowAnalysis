#include <cstdio>
#include <cmath>

using namespace std;

int
main(void)
{
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; t++)
    {
      int N, K;
      scanf("%d%d", &N, &K);
      if ((K+1) % (1 << N) == 0)
        printf("Case #%d: ON\n", t+1);
      else
        printf("Case #%d: OFF\n", t+1);
    }
  return 0;
}
