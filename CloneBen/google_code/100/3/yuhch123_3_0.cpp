#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
#define PI 3.14159265358979323846264338327950288
int C;
int N, M;
int graph1[15][15], graph2[15][15];
int mark[15];
int cnt[15];
int check() {
   int i, j;
   for (i = 0; i < M; i ++)
      for (j = 0; j < M; j ++)
	 if (graph2[i][j] != graph1[cnt[i]][cnt[j]])
	    return 0;
   return 1;
}
int dfs(int x) {
   int i;
   if (x == M)
      return check();
   for (i = 0; i < N; i ++)
      if (!mark[i]) {
	 cnt[x] = i;
	 mark[i] = 1;
	 if (dfs(x + 1))
	    return 1;
	 mark[i] = 0;
      }
   return 0;
}
int main() {
   int i, j, Case = 1, k;
   scanf("%d", &C);
   while (C --) {
      scanf("%d", &N);
      memset(graph1, 0, sizeof(graph1));
      memset(graph2, 0, sizeof(graph2));
      for (i = 0; i < N - 1; i ++) {
	 scanf("%d%d", &j, &k);
	 j --;
	 k --;
	 graph1[j][k] = graph1[k][j] = 1;
      }
      scanf("%d", &M);
      for (i = 0; i < M - 1; i ++) {
	 scanf("%d%d", &j, &k);
	 j --;
	 k --;
	 graph2[j][k] = graph2[k][j] = 1;
      }
      memset(mark, 0, sizeof(mark));
      printf("Case #%d: ", Case ++);
      if (dfs(0))
	 printf("YES\n");
      else
	 printf("NO\n");
   }
   return 0;
}

