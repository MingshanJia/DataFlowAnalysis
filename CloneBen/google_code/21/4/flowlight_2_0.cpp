#include <map>
#include <algorithm>
#include <memory>
#include <fstream>
#include <iostream>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
typedef pair<int, int> P;
typedef long long ll;

int dp[100][2];

int main(){
  int T;
  ll N;
  ll N2;
  cin >> T;
  rep(t, T){
    cin >> N;
    N2 = N;
    int cnt = 0;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    if(N2){
      while(N2){
	N2 /= 2LL;
	cnt++;
      }
    }else{
      cnt = 1;
    }
    for(int i = 0; i < cnt; i++){
      ll a = (N & (1LL << i)) ? 1: 0;
      if(a){
	if(dp[i][1] >= 0) dp[i+1][1] = max(dp[i][1] + 2, dp[i+1][1]);
	if(dp[i][0] >= 0) dp[i+1][0] = max(dp[i][0] + 1, dp[i+1][0]);
	if(dp[i][1] >= 0) dp[i+1][0] = max(dp[i][1] , dp[i+1][0]);

      }else{
	if(dp[i][0] >= 0) dp[i+1][1] = max(dp[i][0] + 2, dp[i+1][1]);
	if(dp[i][1] >= 0) dp[i+1][1] = max(dp[i][1] + 1, dp[i+1][1]);
	if(dp[i][0] >= 0) dp[i+1][0] = max(dp[i][0], dp[i+1][0]);
      }
    }
    
    cout << "Case #" << t + 1 << ": " << dp[cnt][0] << endl;
  }
  return 0;
}
