#include <cstdio>
#include <cstdlib>

int T, C, V, L;
long long dp[512][2];
int P = 1000000007;

int main() {

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d%d%d", &C, &V, &L);

        dp[1][0] = V;
        dp[1][1] = 0;

        for (int i = 2; i <= L; i++) {
            dp[i][0] = ((dp[i-1][0] + dp[i-1][1]) * V) % P;
            dp[i][1] = (dp[i-1][0] * C) % P;
        }

        printf("Case #%d: %lld\n", t, (dp[L][0] + dp[L][1]) % P);
    }

    return 0;
}
