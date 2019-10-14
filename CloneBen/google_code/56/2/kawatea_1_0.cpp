#include <cstdio>
#include <algorithm>

using namespace std;

int a[100][2];
int dp[101][501][2];

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int p, q, n, ans = 0, j, k, l, r;
        
        scanf("%d %d %d", &p, &q, &n);
        
        for (j = 0; j < n; j++) scanf("%d %d", &a[j][0], &a[j][1]);
        
        for (j = 0; j <= n; j++) {
            for (k = 0; k <= 500; k++) {
                for (l = 0; l < 2; l++) {
                    dp[j][k][l] = -1;
                }
            }
        }
        
        dp[0][0][0] = 0;
        
        for (j = 0; j < n; j++) {
            for (k = 0; k <= 500; k++) {
                for (l = 0; l < 2; l++) {
                    if (dp[j][k][l] == -1) continue;
                    
                    if ((a[j][0] + p - 1) / p <= k) dp[j + 1][k - (a[j][0] + p - 1) / p][l] = max(dp[j + 1][k - (a[j][0] + p - 1) / p][l], dp[j][k][l] + a[j][1]);
                    
                    if (l == 0) {
                        for (r = 0; r < 10 && r <= k; r++) {
                            int x = a[j][0] - p * r;
                            
                            if (x <= 0) break;
                            if (x % (p + q) == 0 || x % (p + q) > p) continue;
                            
                            dp[j + 1][k - r][1] = max(dp[j + 1][k - r][1], dp[j][k][l] + a[j][1]);
                        }
                        
                        for (r = 0; r < 10; r++) {
                            int x = a[j][0] - q * r;
                            
                            if (x <= 0) break;
                            if (x % (p + q) == 0 || x % (p + q) > p) continue;
                            
                            dp[j + 1][min(500, k + r)][1] = max(dp[j + 1][min(500, k + r)][1], dp[j][k][l] + a[j][1]);
                        }
                        
                        dp[j + 1][min(500, k + (a[j][0] + q - 1) / q)][0] = max(dp[j + 1][min(500, k + (a[j][0] + q - 1) / q)][0], dp[j][k][l]);
                    } else {
                        for (r = 0; r < 10 && r <= k; r++) {
                            int x = a[j][0] - p * r - q;
                            
                            if (x <= 0) break;
                            if (x % (p + q) == 0 || x % (p + q) > p) continue;
                            
                            dp[j + 1][k - r][1] = max(dp[j + 1][k - r][1], dp[j][k][l] + a[j][1]);
                        }
                        
                        for (r = 0; r < 10; r++) {
                            int x = a[j][0] - q * r - q;
                            
                            if (x <= 0) break;
                            if (x % (p + q) == 0 || x % (p + q) > p) continue;
                            
                            dp[j + 1][min(500, k + r)][1] = max(dp[j + 1][min(500, k + r)][1], dp[j][k][l] + a[j][1]);
                        }
                        
                        dp[j + 1][min(500, k + (a[j][0] + q - 1) / q - 1)][0] = max(dp[j + 1][min(500, k + (a[j][0] + q - 1) / q - 1)][0], dp[j][k][l]);
                    }
                }
            }
        }
        
        for (j = 0; j <= 500; j++) {
            for (k = 0; k < 2; k++) {
                ans = max(ans, dp[n][j][k]);
            }
        }
        
        printf("Case #%d: %d\n", i + 1, ans);
    }
    
    return 0;
}
