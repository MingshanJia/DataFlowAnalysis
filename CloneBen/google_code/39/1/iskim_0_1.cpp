#include <bits/stdc++.h>
using namespace std;

int cnt[4];

int main()
{
    int T;
    scanf("%d",&T);
    for (int TT = 1; TT <= T; TT++)
    {
        memset(cnt, 0, sizeof(cnt));
        printf("Case #%d: ", TT);
        int n, p;
        scanf("%d%d",&n,&p);
        for (int i = 0; i < n; i++)
        {
            int t;
            scanf("%d", &t);
            cnt[t % p]++;
        }

        if (p == 2)
        {
            printf("%d\n", cnt[0] + (cnt[1] + 1) / 2);
        }
        else if (p == 3)
        {
            printf("%d\n", cnt[0] + min(cnt[1], cnt[2]) + (max(cnt[1], cnt[2]) - min(cnt[1], cnt[2]) + 2) / 3);
        }
        else
        {
            int ans1 = cnt[0];
            int ans2 = cnt[2] / 2; cnt[2] %= 2;
            int ans3 = min(cnt[1], cnt[3]); cnt[1] -= ans3; cnt[3] -= ans3;

            int rem1 = cnt[2], rem2 = max(cnt[1], cnt[3]);
            if (rem1 == 0) printf("%d\n", ans1 + ans2 + ans3 + (rem2 + 3) / 4);
            else
            {
                if (rem2 >= 2) printf("%d\n", ans1 + ans2 + ans3 + 1 + (rem2 - 2 + 3) / 4);
                else printf("%d\n", ans1 + ans2 + ans3 + 1);
            }
        }
    }
}
