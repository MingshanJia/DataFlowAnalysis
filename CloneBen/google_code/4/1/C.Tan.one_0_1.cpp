#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const string file = "A-large";

double dp[2001][2001]{};

int main(){
    ios::sync_with_stdio(false);
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
	int tests;
	cin >> tests;
    for (int test = 0; test < tests; ++ test){
        int n, m;
        cin >> n >> m;
        dp[1][0] = (double)n / (n + m);
        for (int i = 2; i <= n; ++i)
            dp[i][0] = dp[i - 1][0] * (double)(n - i + 1) / (n + m - i + 1);
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i][j] = dp[i - 1][j] * (double)(n - i + 1) / (n + m - i - j + 1) + dp[i][j - 1] * (double)(m - j + 1) / (n + m - i - j + 1);
            }
        }
        cout << "Case #" << test + 1 << ": " << dp[n][m] << endl;
	}
}
