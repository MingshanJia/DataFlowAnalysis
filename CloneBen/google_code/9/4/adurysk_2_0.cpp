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

bool pos[N][N];
int dp[N];
int a[N];
bool flag;

inline void solve(){
	int n, k, p, i, j;
	sd(n); sd(p);
	for(i = 1; i <= n; i++){
		sd(a[i]);
	}
	memset(pos, 0, sizeof pos);
	for(i = n - 2; i >= 1; i--){
		for(j = i + 2; j <= n; j++){
			for(k = i + 1; k < j; k++){
				if((a[k] == a[i] + p) && (a[j] - a[i] == p + p)){
					if(k == i + 1 || pos[i + 1][k - 1] == true){
						if(k == j - 1 || pos[k + 1][j - 1] == true){
							pos[i][j] = true;
							break;
						}
					}
				}
				if(pos[i][k] == true && pos[k + 1][j] == true){
					pos[i][j] = true;
					break;
				}
			}
		}
	}
	dp[n + 1] = 0;
	dp[n] = 1;
	dp[n - 1] = 2;
	for(i = n - 2; i >= 1; i--){
		dp[i] = 1 + dp[i + 1];
		for(j = i + 2; j <= n; j++){
			if(pos[i][j] == true){
				//cout<<i<<" "<<j<<" "<<1<<endl;
				dp[i] = min(dp[i], dp[j + 1]);
			}
		}
		//cout<<i<<" "<<dp[i]<<endl;
	}
	cout<<dp[1]<<endl;
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
