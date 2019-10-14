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

#define MOD 1000000007

#define MAX 105

int dp[MAX][MAX];

long long C(int n, int m)
{
    return dp[n][m];
}

long long pow(int a, int b)
{
    long long ans = 1;
    for (int i = 0; i < b; ++i)
        ans = ans * a % MOD;
    return ans;
}

int main()
{
    int z;
    scanf("%d", &z);

    dp[0][0] = 1;
    for (int i = 1; i < MAX; ++i)
    {
        dp[i][0] = 1;
        for (int j = 1; j < MAX; ++j)
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
    }
    for (int zi = 1; zi <= z; ++zi)
    {
        int n, m;
        scanf("%d %d", &m, &n);

        long long ans = pow(m, n);

        for (int i = 1, j = -1; i <= m; ++i, j *= -1)
        {
            long long val = C(m, i) * pow(m - i, n) * j;
            ans = ans + val % MOD + MOD;
            ans %= MOD;
        }

        printf("Case #%d: %lld\n", zi, ans);
    }
}

