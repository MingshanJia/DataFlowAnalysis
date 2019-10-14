#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <sstream>
#include <set>
#include <complex>
#include <algorithm>
using namespace std;
#define PI 3.14159265358979323846264338327950288
int mat[55][55];
int cnt[55][55];
int T, N, M, ret, sum;
int add(int x, int y, int d) {
   int i, j, ret = 1;
   for (i = x - 1; i <= x + 1; i ++)
      if (i >= 0 && i < N)
   	 for (j = y - 1; j <= y + 1; j ++)
   	    if (j >= 0 && j < M) {
	       mat[i][j] += d;
	       if (mat[i][j] < 0)
		  ret = 0;
	    }
   return ret;
}
int dfs(int x, int y) {
   int i, j;
   if (x >= N) {
      for (i = 0; i < M; i ++)
	 if (mat[N - 1][i] != 0)
	    return 0;
      ret = sum;
      return 0;
   }
   if (x == (N + 1) / 2 && y == 0) {
      sum = 0;
      for (i = 0; i < M; i ++)
	 sum += cnt[N / 2][i];
      if (sum <= ret)
	 return 0;
   }
   if (y >= M) {
      if (x < 1 || mat[x - 1][y - 1] == 0)
   	 return dfs(x + 1, 0);
      return 0;
   }
   cnt[x][y] = 1;
   if (add(x, y, -1) && (x < 1 || y < 1 || mat[x - 1][y - 1] == 0))
      dfs(x, y + 1);
   add(x, y, 1);
   cnt[x][y] = 0;
   if (x < 1 || y < 1 || mat[x - 1][y - 1] == 0)
      dfs(x, y + 1);
   return 0;
}
int main() {
   int i, j, k, Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%d%d", &N, &M);
      for (i = 0; i < N; i ++)
	 for (j = 0; j < M; j ++)
	    scanf("%d", &mat[i][j]);
      ret = 0;
      dfs(0, 0);
      printf("Case #%d: %d\n", Case ++, ret);
   }
   return 0;
}

