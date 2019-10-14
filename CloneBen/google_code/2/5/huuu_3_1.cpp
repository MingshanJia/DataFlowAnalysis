#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


void solve(int time){
    int n;
    cin >> n;
    int dp[10001];
    vector<int> sq;
    for(int i = 1;i*i <= n;i++){
        sq.push_back(i*i);
    }
    dp[0] = 0;
    for(int i = 1;i <= n;i++){
        dp[i] = i;
        for(int j = 0;j < sq.size();j++){
            if(sq[j] > i) break;
            dp[i] = min(dp[i],dp[i-sq[j]]+1);
        }
    }
    cout << "Case #" << time << ": ";
    cout << dp[n] << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++){
        solve(i);
    }
}

