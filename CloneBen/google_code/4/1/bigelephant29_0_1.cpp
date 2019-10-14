#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 2000 + 10;
double dp[MAX][MAX];
int main(){
  int TN;
  scanf("%d", &TN);
  for(int casen = 1 ; casen <= TN ; casen ++) {
    memset(dp, 0, sizeof(dp));
    printf("Case #%d: ", casen);
    dp[0][0] = 1.0;
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i <= n ; i ++) {
      for(int j = 0 ; j <= m ; j++) if((i == j && i == 0) || i > j){
        dp[i+1][j] += dp[i][j] * (n - i) / (n + m - i - j);
        if(i > j+1)
          dp[i][j+1] += dp[i][j] * (m - j) / (n + m - i - j);
      }
    }
    printf("%.9f\n", dp[n][m]);
  }
  return 0;
}
