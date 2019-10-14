#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int N, M;
double dp[2010][2010];
double f(int n, int m, int k) {
    if (k < 0)
        return 0;
    if (k == 0 && (n != N || m != M))
        return 0;
    if (k > m)
        return 1;
    if (dp[n][m] >= 0)
        return dp[n][m];
    dp[n][m] = 0;
    dp[n][m] += (double)n / (n + m) * f(n - 1, m, k + 1);
    dp[n][m] += (double)m / (n + m) * f(n, m - 1, k - 1);
    return dp[n][m];
}

int main() {
    
    freopen("/Users/daidaidaiyi/Downloads/A-small-attempt1.in","r",stdin);
    freopen("./out.txt","w",stdout);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> M;
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= M; j++)
                dp[i][j] = -1;
        printf("Case #%d: %.10lf\n", t, f(N, M, 0));
    }
}
