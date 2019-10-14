#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 15, MOD = 9901;

int T, N, K, perm [MAXN];
bool ok [MAXN][MAXN];

int main ()
{
    scanf ("%d", &T);

    for (int t = 1; t <= T; t++)
    {
        scanf ("%d %d", &N, &K);
        memset (ok, true, sizeof (ok));

        for (int i = 0, x, y; i < K; i++)
        {
            scanf ("%d %d", &x, &y); x--; y--;
            ok [x][y] = ok [y][x] = false;
        }

        for (int i = 0; i < N; i++)
            perm [i] = i;

        int total = 0;

        do
        {
            bool good = true;

            for (int i = 0; i < N && good; i++)
                if (!ok [perm [i]][perm [(i + 1) % N]])
                    good = false;

            if (good)
                total++;
        }
        while (next_permutation (perm + 1, perm + N));

        total = total / 2 % MOD;
        printf ("Case #%d: %d\n", t, total);
    }

    return 0;
}
