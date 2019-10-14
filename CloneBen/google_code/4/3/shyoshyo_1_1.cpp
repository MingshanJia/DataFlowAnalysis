#include<cstdio>
#include<cstring>

int n, m;

int f[105][1024][1024];

int work(int case_i)
{
        scanf("%d %d", &n, &m);

        memset(f, 0, sizeof f);

        const int M = (1 << m) - 1;

        for(int i = 1; i <= n; i++)
        {
                for(int j = 0; j <= M; j++)
                {
                        if((j & (j << 1) & (j << 2))) continue;

                        for(int k = 0; k <= M; k++)
                        {
                                if(k & (k << 1) & (k << 2)) continue;
                                for(int p = 0; p <= M; p++)
                                {
                                        if(p & (p << 1) & (p << 2)) continue;

                                        if(j & k & p) continue;

                                        int pop_count = __builtin_popcount(p);

                                        if(f[i][p][k] < f[i - 1][k][j] + pop_count) 
                                                f[i][p][k] = f[i - 1][k][j] + pop_count;     
                                }
                        }
                }
        }


        int ans = 0;
        for(int j = 0; j <= M; j++)
        {
                for(int k = 0; k <= M; k++)
                {
                        if(ans < f[n][j][k])
                                ans = f[n][j][k];
                }
        }

        printf("Case #%d: %d\n", case_i, ans);
}

int main()
{
        int case_n;
        scanf("%d", &case_n);
        for(int i = 1; i <= case_n; i++)
                work(i);
}
