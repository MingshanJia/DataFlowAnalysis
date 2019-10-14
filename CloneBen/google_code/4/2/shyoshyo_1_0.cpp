#include<cstdio>
#include<cstring>
#include<algorithm>

void work(int case_i)
{
        int ans = 0;
        int n, m;

        scanf("%d%d", &n, &m);
        
        if(n > m) std::swap(n, m);

        if(n <= 2)
        {
                for(int i = 1; i <= m; i++)
                        if(i % 3 != 0)
                                ans += n;
        }
        else
        {
                int cnt[5] = {0, 0, 0, 0, 0};
                for(int i = 1; i <= n; i++)
                {
                        cnt[(i + 1) % 3]++;
                        cnt[(i + 2) % 3]++;
                }

                for(int k = 0; k < 3; k++)
                {
                        int sum = 0;
                        for(int i = 1; i <= m; i++)
                                sum += cnt[(i + k) % 3];

                        if(ans < sum) ans = sum;
                }

                for(int k = 0; k < 3; k++)
                {
                        int sum = 0;
                        for(int i = 1; i <= m; i++)
                                sum += cnt[(m + m - i + k) % 3];

                        if(ans < sum) ans = sum;
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
