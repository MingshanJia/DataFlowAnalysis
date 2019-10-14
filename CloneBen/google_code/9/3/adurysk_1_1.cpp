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

#define N 405

LD dp[N][N][N];

inline void solve(){
	int n, m, i, j, al, b, l, k;
	LD x;
	sd(b); sd(al); sd(n);
	for(l = 1; l <= al; l++){
		for(i = 1; i <= l; i++){
			for(j = 1; j <= l - i + 1; j++){
				dp[l][i][j] = 0;
			}
		}
	}
	dp[1][1][1] = b * 3;
	for(l = 1; l <= al; l++){
		for(i = 1; i <= l; i++){
			for(j = 1; j <= l - i + 1; j++){
				if(dp[l][i][j] >= 1){
					x = dp[l][i][j] - 1;
					x /= 3;
					dp[l + 1][i][j] += x;
					dp[l + 1][i + 1][j] += x;
					dp[l + 1][i][j + 1] += x;
					dp[l][i][j] = 1;
				}
			}
		}
	}
	for(k = 1; k <= al; k++){
		for(i = k, j = 1; i >= 1; i--, j++){
			n--;
			if(n == 0){
				break;
			}
		}
		if(i >= 1){
			break;
		}
	}
	dp[al][i][j] *= 250;
	cout<<dp[al][i][j]<<endl;
}

int main(){
	cin.fixed;
	cout<<setprecision(20);
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
