#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int S[N];
int dp[N];
int main(){
	int t = 1;
	cin >> t;
	dp[0] = 0;
	for(int i = 1; i < N; i++){
		dp[i] = i;
		for(int j = 1; j * j <= i; j++){
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	for(int tt = 1; tt <= t; tt++){
		// cerr << tt << endl;
		int n; 
		cin >> n;
		cout << "Case #" << tt << ": " << dp[n] << endl;
	}
}