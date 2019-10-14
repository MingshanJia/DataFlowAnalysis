#include <cstdio>
#include <algorithm>

using namespace std;

struct Key
{
    long long a[3], b[3];
};

long long point[3][3];

long long solve (Key key, long long v)
{
    bool visit = false;
    long long result;
    for (int i = 0; i < 3; ++i)
    {
        if (key.a[i] == 0) continue;
        for (int j = 0; j < 3; ++j)
        {
            if (key.b[j] == 0) continue;
            long long m = min (key.a[i], key.b[j]);
            key.a[i] -= m; key.b[j] -= m;
            long long vv = solve (key, v + point[i][j] * m);
            if (!visit || result < vv)
            {
                result = vv;
            }
            key.a[i] += m; key.b[j] += m;
            visit = true;
        }
    }

    return visit ? result : v;
}

int main ()
{
    int nCase;
    scanf ("%d", &nCase);

    for (int iCase = 0; iCase < nCase; ++iCase)
    {
        long long n, a, b, c, d, e, f;
        scanf ("%lld %lld %lld %lld %lld %lld %lld", &n, &a, &b, &c, &d, &e, &f);
        Key key;
        key.a[0] = a;
        key.a[1] = b;
        key.a[2] = c;
        key.b[0] = d;
        key.b[1] = e;
        key.b[2] = f;

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                scanf ("%lld", &point[i][j]);
                // printf ("%lld ", point[i][j]);
            }
            // printf ("\n");
        }

        // printf ("%lld %lld %lld %lld %lld %lld\n", key.a[0],
        //         key.a[1],
        //         key.a[2],
        //         key.b[0],
        //         key.b[1],
        //         key.b[2]);
        printf ("Case #%d: %lld\n", iCase + 1, solve (key, 0));
    }
    
    return 0;
}
