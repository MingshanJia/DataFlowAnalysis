#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

typedef long long llint;

using namespace std;

int n;
llint a[7002];
llint cnt[200002];

int main()
{
    int T;
    llint ans;

    freopen("A-large.in", "r", stdin);
    freopen("A-large-output.txt", "w", stdout);

    scanf("%d", &T);

    for(int test_case=1;test_case<=T;test_case++)
    {
        scanf("%d", &n);
        for(int i=1;i<=n;i++)
            scanf("%lld", &a[i]);

        for(int i=0;i<=200000;i++)
            cnt[i] = 0;
        for(int i=1;i<=n;i++)
            cnt[a[i]]++;

        ans = 0;
        ans += cnt[1]*(cnt[1]-1)*(cnt[1]-2)/6;        // 1 * 1 = 1 
        ans += cnt[0]*(cnt[0]-1)*(cnt[0]-2)/6;        // 0 * 0 = 0
        for(int i=2;i<=200000;i++)                    // a * 1 = a
            ans += cnt[1]*cnt[i]*(cnt[i]-1)/2;
        ans += cnt[0]*(cnt[0]-1)/2*(n-cnt[0]);        // a * 0 = 0, 1 * 0 = 0
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[i]<=1 || a[j]<=1)  continue;
                if(a[i]*a[j]>200000)    continue;
                ans += cnt[a[i]*a[j]];
            }
        }

        printf("Case #%d: %lld\n", test_case, ans);
    }

    return 0;
}