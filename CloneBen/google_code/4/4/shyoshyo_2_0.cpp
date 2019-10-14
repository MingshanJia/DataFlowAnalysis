#include<cstdio>
#include<cstdlib>
#include<cstring>

int statistics_v[1005][30];
int statistics_s[4005][30];
int n, m;

int f[4005];

void work(int case_i)
{
        scanf("%d %d",&n, &m);

        memset(statistics_v, 0, sizeof statistics_v);

        for(int i = 1; i <= n; i++)
        {
                char s[4005];
                int len;

                scanf("%s", s + 1);
                len = strlen(s + 1);
                
                for(int j = 1; j <= len; j++)
                {
                        statistics_v[i][s[j] - 'a' + 1] ++;
                        statistics_v[i][0] += 1;
                }
        }
        

        printf("Case #%d: ", case_i);

        for(int i = 1; i <= m; i++)
        {
                char s[4005];
                
                scanf("%s", s + 1);
                int len = strlen(s + 1);
                
                memset(statistics_s, 0, sizeof statistics_s);

                for(int j = 1; j <= len; j++)
                        statistics_s[j][s[j] - 'a' + 1]++;

                for(int j = 1; j <= len; j++)
                        for(int k = 1; k <= 26; k++)
                                statistics_s[j][k] += statistics_s[j - 1][k];

                memset(f, 0 ,sizeof f);
                f[0] = 1;
                for(int j = 0; j < len; j++)
                        for(int p = 1; p <= n; p++)
                        {
                                int k = j + statistics_v[p][0];

                                if(k > len) continue;

                                bool same = true;
                                for(int r = 1; r <= 26; r++)
                                        if(statistics_s[k][r] - statistics_s[j][r] != statistics_v[p][r])
                                                same = false;

                                if(!same) continue;

                                f[k] += f[j];
                                f[k] %= 1000000007;
                        }

                printf("%d ", f[len]);
        }
        puts("");
}

int main()
{
        int case_n;

        scanf("%d", &case_n);

        for(int i = 1; i <= case_n; i++)
                work(i);
}
