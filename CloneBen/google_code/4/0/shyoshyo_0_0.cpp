#include<cstdio>

int n, m;

double f[2005][2005];

void work(int case_i)
{
        scanf("%d %d", &n, &m);

        f[0][0] = 1;

        for(int i = 0; i <= n; i++)
                for(int j = 0; j <= m; j++)
                {
                        if(i == 0 && j == 0) continue;

                        f[i][j] = 0;
                        if(i <= j) continue;

                        if(i > 0)
                                f[i][j] = f[i-1][j] * (double)(n - i + 1) / (double)(n + m - i - j + 1);
                        if(j > 0)
                                f[i][j] += f[i][j-1] * (double)(m - j + 1) / (double)(n + m - i - j + 1);
                }

        printf("Case #%d: %lf\n", case_i + 1, f[n][m]);
}

int main()
{
        int case_n;
        scanf("%d", &case_n);
        for(int i = 0; i < case_n; i++)
                work(i);

}
