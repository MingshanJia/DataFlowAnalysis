#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 15, BOUND = 70000;

int T, N, K, x [MAXN], y [MAXN];
int smask [MAXN][MAXN], dp [1 << MAXN];

inline int mask (int sx, int sy, int len)
{
    int m = 0;

    for (int i = 0; i < N; i++)
        if (sx <= x [i] && x [i] <= sx + len && sy <= y [i] && y [i] <= sy + len)
            m |= 1 << i;

    return m;
}

bool works (int len)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            smask [i][j] = mask (x [i], y [j], len);

    memset (dp, 63, sizeof (dp));
    dp [0] = 0;

    for (int m = 0; m < 1 << N; m++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dp [m | smask [i][j]] = min (dp [m | smask [i][j]], dp [m] + 1);

    return dp [(1 << N) - 1] <= K;
}

int main ()
{
    scanf ("%d", &T);

    for (int t = 1; t <= T; t++)
    {
        scanf ("%d %d", &N, &K);

        for (int i = 0; i < N; i++)
            scanf ("%d %d", x + i, y + i);

        int lo = 0, hi = BOUND, mid;

        while (lo < hi)
        {
            mid = lo + hi >> 1;

            if (works (mid))
                hi = mid;
            else
                lo = mid + 1;
        }

        printf ("Case #%d: %d\n", t, lo);
    }

    return 0;
}
