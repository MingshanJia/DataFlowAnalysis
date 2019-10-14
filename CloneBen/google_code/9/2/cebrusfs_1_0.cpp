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

#define MAX 405

long double dp[MAX][MAX][MAX];

pair<int, int> get(int n)
{
    int i = 0;
    int off = 1;

    while (n >= off)
        n -= off, ++i, off++;

    return make_pair(i, n);
}

int main()
{
    int z;
    scanf("%d", &z);

    for (int zi = 1; zi <= z; ++zi)
    {
        int B, L, N;
        scanf("%d %d %d", &B, &L, &N);

        dp[1][0][0] = B * 750;
        for (int k = 1; k <= L; ++k)
        {
            for (int i = 0; i <= k; ++i)
                for (int j = 0; j <= i; ++j)
                    dp[k+1][i][j] = 0;

            for (int i = 0; i < k; ++i)
            {
                for (int j = 0; j <= i; ++j)
                {
                    double val = max(0.0L, dp[k][i][j] - 250.0);
                    dp[k][i][j] -= val;

                    val /= 3;
                                             
                    dp[k + 1][i][j] += val;
                    dp[k + 1][i+1][j] += val;
                    dp[k + 1][i+1][j+1] += val;
                }
            }
        }

        auto p = get(N - 1);
        //printf("%d %d\n", p.first, p.second);

        printf("Case #%d: %.7Lf\n", zi, dp[L][p.first][p.second]);
    }
}

