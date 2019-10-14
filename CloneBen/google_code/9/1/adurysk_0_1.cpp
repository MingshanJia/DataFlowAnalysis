	#include<bits/stdc++.h>

using namespace std;

#define LL long long int
#define sd(x) scanf("%d", &x)
#define MP make_pair
#define PB push_back
#define vi vector<int>
#define F first
#define S second
#define INF 2000000000
#define MOD 1000000007
#define D double
#define LD long double

#define N 200

LL dp[N][N];

inline void solve(){
	int n, m, i, j;
	sd(m); sd(n);
	memset(dp, 0, sizeof dp);
	dp[1][1] = m;
	for(i = 1; i < n; i++){
		for(j = 1; j <= i && j <= m; j++){
			(dp[i + 1][j] += j * dp[i][j]) %= MOD;
			(dp[i + 1][j + 1] += (m - j) * dp[i][j]) %= MOD;
		}
	}
	cout<<dp[n][m]<<endl;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, i;
	sd(t);
	for(i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		solve();
	}
    return 0;
}
