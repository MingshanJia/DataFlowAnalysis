#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
const int N = 303, base = 541, mod = 1e9 + 7;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
string s;

int dp[N][N][N], B[N], H[N], dp2[N];
inline int getHash(int i, int j){
	return sub(H[j], mul(H[i - 1], B[j - i + 1]));
}
const int INF = 1e9;
int main(){
	B[0] = 1;
	for(int i = 1;  i < N; i++) B[i] = mul(B[i - 1], base);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		cin >> s;
		int n = s.length();
		s = " " + s;
		for(int i = 1; i <= n; i++) H[i] = add(mul(H[i - 1], base), s[i] - 'a' + 1);
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++)
				for(int k = 0; k <= n; k++)
					dp[i][j][k] = INF;
			dp2[i] = INF;
		}
		dp[1][0][0] = 1;
		dp[1][1][1] = 2;
		dp2[1] = 1;
		for(int i = 2; i <= n; i++){
			dp2[i] = dp[i][0][0] = dp[i - 1][0][0] + 1;
			for(int j = 1; j < i; j++)
				for(int k = j; k < i; k++){
					dp[i][j][k] = dp[i - 1][j][k] + 1;
					// if(i == )
					if(getHash(j, k) == getHash(i - k + j, i) && i - k + j > k)
						dp[i][j][k] = min(dp[i][j][k], dp[i - k + j - 1][j][k] + 1);
					dp2[i] = min(dp2[i], dp[i][j][k]);
				}
			for(int j = 1; j <= i; j++)
				for(int k = j; k <= i; k++){
					dp[i][j][k] = min(dp[i][j][k], dp2[i] + 1);
				}	
		}
		cout << "Case #" << tt << ": " << dp2[n] << endl;
	}
}