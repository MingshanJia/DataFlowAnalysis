#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 500 + 10;
const int MAXLEN = 20 + 10;
const int MAXM = 4000 + 10;
const long long MOD = 1000000007;
char rec[MAX][MAXLEN];
char arr[MAXM];
char tmp[MAXLEN];
long long dp[MAXM];

int main(){
  int TN;
  scanf("%d", &TN);
  for(int casen = 1 ; casen <= TN ; casen++){
    printf("Case #%d:", casen);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < n ; i ++){
      scanf("%s", rec[i]);
      int len = strlen(rec[i]);
      sort(rec[i], rec[i]+len);
    }
    while(m--) {
      memset(dp, 0, sizeof(dp));
      dp[0] = 1;
      scanf("%s", arr);
      int len = strlen(arr);
      for(int i = 0 ; i < len ; i++) if(dp[i]){
        for(int j = 0 ; j < n ; j++){
          int tlen = strlen(rec[j]);
          for(int k = 0 ; k < tlen ; k++){
            tmp[k] = arr[i+k];
          }
          tmp[tlen] = '\0';
          sort(tmp, tmp+tlen);
          if(strcmp(tmp, rec[j]) == 0) dp[i+tlen] = (dp[i+tlen] + dp[i]) % MOD;
        }
      }
      printf(" %lld", dp[len] % MOD);
    }
    puts("");
  }
  return 0;
}
