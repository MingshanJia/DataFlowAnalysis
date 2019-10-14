#include <stdio.h>
#define maxn 2000

int data[maxn][maxn], dp[maxn];
int malt[maxn];
int cp[maxn];
int n, m;

int main () {
    int t, i, j, k, a, b, f, ct;
    
    ct = 0;
    for (scanf("%d", &t); t > 0; t --) {
        scanf("%d%d", &n, &m);
        
        for (i = 0; i < m; i ++) {
            scanf("%d", &k);

            malt[i] = -1;
            dp[i] = 0;
            for (j = 0; j < k; j ++) {
                scanf("%d%d", &a, &b);
                a --;
                if (b) 
                    malt[i] = a;
                else
                    data[i][dp[i] ++] = a;
                }
            }
        
        for (i = 0; i < n; i ++)
            cp[i] = 0;
        
        f = 0;
        while (f == 0) {
            f = 1;
            for (i = 0; i < m; i ++)
                if (malt[i] == -1 || cp[malt[i]] == 0) {
                    int cn = dp[i];
                    for (j = 0; j < dp[i]; j ++)
                        if (cp[data[i][j]] == 1)
                            cn --;
                    if (cn == 0) {
                        if (malt[i] != -1) {
                            f = 0;
                            cp[malt[i]] = 1;
                            }
                        else {
                            f = -1;
                            break;
                            }
                        }
                    }
            }
        
        if (f == 1) {
            printf("Case #%d:", ++ ct);
            for (i = 0; i < n; i ++)
                printf(" %d", cp[i]);
            printf("\n");
            }
        else
            printf("Case #%d: IMPOSSIBLE\n", ++ ct);
        }
    
    return 0;    
    }
