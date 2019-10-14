#include <cstdio>
#include <cstring>

int N, M;
double dp[2001][2001];

double choose_m(int n, int m) {
    int opt_m = M - m;
    int opt_n = N - n;
    return (double) opt_m / (opt_m + opt_n);
}

double choose_n(int n, int m) {
    return 1 - choose_m(n, m);
}

int main() {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d%d", &N, &M);

        for (int n = 0; n <= N; n++) {
            for (int m = 0; m <= M; m++) {
                if (n == 0 && m == 0) {
                    dp[n][m] = 1;
                } else {
                    if (n > m) {
                        dp[n][m] = n > 0 ? dp[n-1][m] * choose_n(n-1, m) : 0;
                        dp[n][m] += m > 0 ? dp[n][m-1] * choose_m(n, m-1) : 0;
                    } else {
                        dp[n][m] = 0;
                    }
                }
                /* printf("%.6f ", dp[n][m]); */
            }
            /* printf("\n"); */
        }
        printf("Case #%d: %.6f\n", t, dp[N][M]);
    }
    return 0;
}
