#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
  const int NO = -10000;
  int T;
  scanf("%d", &T);
  for(int CN=1; CN<=T; ++CN) {
    long long N;
    scanf("%lld", &N);
    int dp[100][2];
    for(int i=0; i<100; ++i)
      dp[i][0] = dp[i][1] = NO;
    if(N & 1) {
      dp[0][0] = 1;
      dp[0][1] = NO;
    } else {
      dp[0][0] = 0;
      dp[0][1] = 2;
    }
    for(int i=1; N>=1ll<<i; ++i) {
      for(int j=0; j<=2; ++j) {
	int bit = (N>>i) & 1;
	for(int k=0; k<2; ++k) {
	  if(((k+j)&1) == bit) {
	    int carry = k+j >= 2 ? 1 : 0;
	    dp[i][carry] = max(dp[i][carry], dp[i-1][k]+j);
	  }
	}
      }
      // printf("%d %d\n", dp[i][0], dp[i][1]);
    }
    int b = 0;
    while(N>=1ll<<b) b++;
    printf("Case #%d: %d\n", CN, dp[b-1][0]);
  }
  return 0;
}
