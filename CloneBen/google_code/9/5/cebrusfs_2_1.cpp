// macros {{{
#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define BIT(n) ((1LL) << (long long)(n))

#define MT make_tuple

#define MP make_pair

#define PB push_back
#define PF push_front

#define PPB pop_back
#define PPF pop_front

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> PII;
typedef tuple<int, int> TII;
typedef vector<int> VI;

#define runtime() ((double)clock() / CLOCKS_PER_SEC)

const double eps = 1e-7;
// }}}

#define MAX 105

int ary[MAX];
int dp[MAX];


int dp2[MAX][MAX];

int K;
bool check(int l, int r)
{
    if (l > r)
        return true;

    if (r - l + 1 <= 2)
        return false;

    if (dp2[l][r] != -1)
        return dp2[l][r];

    dp2[l][r] = true;

    for (int i = l; i < r; ++i)
        if (check(l, i) and check(i+1, r))
            return true;

    for (int i = l + 1; i < r; ++i)
        if (ary[l] + K == ary[i] and ary[i] + K == ary[r])
            if (check(l + 1, i - 1) and check(i+1, r - 1))
                return true;

    return dp2[l][r] = false;
}

int main()
{
    int z;
    scanf("%d", &z);

    for (int zi = 1; zi <= z; ++zi)
    {
        int n;
        scanf("%d %d", &n, &K);


        for (int i = 1; i <= n; ++i)
            scanf("%d", &ary[i]);

        memset(dp2, -1, sizeof(dp2));

        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = MAX;
            for (int j = i; j >= 1; --j)
                if (check(j, i))
                {
                    for (int k = j - 1; k >= 0; --k)
                        dp[i] = min(dp[k] + j - 1 - k, dp[i]);
                }
        }

        int ans = n;
        for (int i = 1; i <= n; ++i)
            ans = min(ans, dp[i] + n - i);
        printf("Case #%d: %d\n", zi, ans);
    }
}

