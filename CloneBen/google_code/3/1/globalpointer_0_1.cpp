#include <bits/stdc++.h>

const int maxn = 305;

int T, n, id[maxn][maxn], earliest[maxn * maxn], dp[maxn], best[maxn];
char s[maxn];
std::map<std::string, int> m;

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf(" %s", s);
        n = strlen(s);

        m.clear();
        int next = 1;
        for (int i = 0; i < n; i++) {
            std::string st;
            for (int j = i; j < n; j++) {
                st += s[j];
                if (m[st] == 0) {
                    m[st] = next;
                    earliest[next] = 1e9;
                    next++;
                }
                int k = m[st];
                earliest[k] = std::min(earliest[k], j+1);
                id[i][j-i + 1] = k;
                //printf("id %d %d = %d\n", i, j-i+1, k);
            }
        }

        std::fill(dp, dp+n+3, 1e9);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            dp[i+1] = std::min(dp[i+1], dp[i] + 1);
            for (int l = 1; i+l <= n; l++) {
                if (earliest[id[i][l]] <= i) {
                    std::fill(best+i, best+n+3, 1e9);
                    best[i] = dp[i] + 1;
                    for (int j = i; j < n; j++) {
                        best[j+1] = std::min(best[j+1], best[j] + 1);
                        if (j + l <= n && id[j][l] == id[i][l]) {
                            best[j+l] = std::min(best[j+l], best[j] + 1);
                        }
                    }
                    for (int j = i; j <= n; j++) {
                        dp[j] = std::min(dp[j], best[j]);
                    }
                }
            }
        }

        printf("Case #%d: %d\n", t, dp[n]);
    }
}

