#include <cstdio>
#include <cstring>

int vocab_len[400];
int tally[400][26];
int cum[4001][26];
int dp[4001];

#define debug false && printf
#define MOD 1000000007

int main() {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int V; int S; scanf("%d%d", &V, &S);

        memset(tally, 0, sizeof tally);
        memset(cum, 0, sizeof cum);
        for (int i = 0; i < V; i++) {
            char str[21];
            scanf(" %s", str);
            vocab_len[i] = strlen(str);
            for (int j = 0; j < vocab_len[i]; j++) {
                tally[i][str[j]-'a'] += 1;
            }
        }

        printf("Case #%d:", t);
        for (int i = 0; i < S; i++) {
            char str[4001];
            scanf(" %s", str);
            int len = strlen(str);
            for (int j = 1; j <= len; j++) {
                memcpy(cum[j], cum[j-1], sizeof(int) * 26);
                cum[j][str[j-1]-'a'] += 1;
            }

            dp[0] = 1;
            for (int j = 1; j <= len; j++) {
                dp[j] = 0;
                for (int v = 0; v < V; v++) {
                    int start = j - vocab_len[v];
                    if (start < 0)
                        continue;
                    int diff[26];
                    for (int k = 0; k < 26; k++)
                        diff[k] = cum[j][k] - cum[start][k];
                    if (memcmp(diff, tally[v], sizeof(int) * 26) == 0) {
                        debug("use vocab[%d]\n", v);
                        dp[j] = (dp[j] + dp[start]) % MOD;
                    }
                }
                debug("dp[%d]: %d\n", j, dp[j]);
            }
            printf(" %d", dp[len]);
        }
        printf("\n");
    }
    return 0;
}
