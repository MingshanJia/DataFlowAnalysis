#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define PI 3.14159265358979323846264338327950288
int T;
long long L;
int N;
int B[105];
long long ans[2][1000005];
int tot;
int main() {
   int i, j, Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%lld%d", &L, &N);
      tot = 0;
      int maxi;
      for (i = 0; i < N; i ++) {
	 scanf("%d", &B[i]);
	 tot = max(tot, B[i]);
      }
      maxi = tot;
      tot *= N * tot;
      for (i = 0; i <= N; i ++)
	 for (j = 0; j <= tot; j ++)
	    if (i == 0)
	       if (j == 0)
		  ans[i & 1][j] = 0;
	       else
		  ans[i & 1][j] = 1000000000000000001LL;
	    else {
	       ans[i & 1][j] = ans[1 - (i & 1)][j];
	       if (j >= B[i - 1] && ans[i & 1][j] > ans[(i & 1)][j - B[i - 1]] + 1)
		  ans[i & 1][j] = ans[(i & 1)][j - B[i - 1]] + 1;
	    }
      long long ret = 1000000000000000001LL;
      for (j = 0; j <= tot; j ++)
	 if ((L - j) % maxi == 0 && ret > ans[N & 1][j] + (L - j) / maxi)
	    ret = ans[N & 1][j] + (L - j) / maxi;
      if (ret == 1000000000000000001LL)
	 printf("Case #%d: IMPOSSIBLE\n", Case ++);
      else
	 printf("Case #%d: %lld\n", Case ++, ret);
   }
   return 0;
}

