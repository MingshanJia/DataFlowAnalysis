#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <cstdint>
#include <vector>
#include <iomanip>
using namespace std;

void solve(int n, int N, int M) {
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    for (int i = 0; i <= M; i++)
        dp[i][0] = 1;
    for (int j = 0; j <= N; j++)
        dp[0][j] = 1;
    for (int i = 1; i <= M; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (j - 1 > i)
                dp[i][j] = dp[i][j-1];
            if (j > i - 1)
                dp[i][j] += dp[i-1][j];
        }
    }

    int A = dp[M][N];
    // cout << dp[M][N] << endl;

    for (int i = 0; i <= M; i++)
        dp[i][0] = 1;
    for (int j = 0; j <= N; j++)
        dp[0][j] = 1;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }
    int B = dp[M][N];
    cout << "Case #" << n << ": ";
    cout.precision(7);
    // cout << dp[M][N] << endl;
    cout << fixed << A / (double) B << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int N, M;
        cin >> N >> M;
        solve(i, N, M);
    }
}
