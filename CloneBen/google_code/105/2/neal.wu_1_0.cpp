#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 12, MAXM = 105;

int C, N, M, best;
bool like [MAXM][2 * MAXN], ans [MAXN];

int main ()
{
    scanf ("%d", &C);

    for (int c = 0; c < C; c++)
    {
        memset (like, false, sizeof (like));
        scanf ("%d %d", &N, &M);

        for (int i = 0, t; i < M; i++)
        {
            scanf ("%d", &t);

            for (int j = 0, x, y; j < t; j++)
            {
                scanf ("%d %d", &x, &y); x--;
                like [i][2 * x + y] = true;
            }
        }

        best = MAXN;

        for (int m = 0; m < 1 << N; m++)
            if (__builtin_popcount (m) < best)
            {
                bool cover = true;

                for (int i = 0; i < M && cover; i++)
                {
                    bool good = false;

                    for (int j = 0; j < N && !good; j++)
                        if (like [i][2 * j + (bool) (m & 1 << j)])
                            good = true;

                    if (!good)
                        cover = false;
                }

                if (cover)
                {
                    best = __builtin_popcount (m);

                    for (int i = 0; i < N; i++)
                        ans [i] = m & 1 << i;
                }
            }

        if (best < MAXN)
        {
            printf ("Case #%d: ", c + 1);

            for (int i = 0; i < N; i++)
                printf ("%c%c", ans [i] ? '1' : '0', i < N - 1 ? ' ' : '\n');
        }
        else
            printf ("Case #%d: IMPOSSIBLE\n", c + 1);
    }

    return 0;
}
