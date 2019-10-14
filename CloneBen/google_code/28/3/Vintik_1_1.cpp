#include <iostream>
#include <memory.h>

using namespace std;

int N, K;
int x[50], y[50];

int d[1 << 15];

bool inseg(int x1, int x2, int x)
{
    return x >= x1 && x <= x2;
}

int reduce(int m, int x0, int y0, int l)
{
    int res = 0;

    for (int i=0; i < N; i++)
        if ((m&(1 << i)) && !(inseg(x0, x0+l, x[i]) && inseg(y0, y0+l, y[i])))
            res |= (1 << i);

    return res;
}

int calc(int m, int l)
{
    if (m == 0)
        return 0;

    if (d[m] == -1)
    {
        int& res = d[m];
        res = N;

        int minx = 100000, miny = 0;

        for (int i=0; i < N; i++)
            if ((m&(1 << i)) && make_pair(x[i], y[i]) < make_pair(minx, miny))
            {
                minx = x[i];
                miny = y[i];
            }

        for (int i=0; i < N; i++)
            if (m&(1 << i))
            {
                if (inseg(y[i], y[i]+l, miny))
                    res = min(res, 1+calc(reduce(m, minx, y[i], l), l));
                if (inseg(y[i]-l, y[i], miny))
                    res = min(res, 1+calc(reduce(m, minx, y[i]-l, l), l));
            }
    }

    return d[m];
}

bool can(int l)
{
    memset(d, -1, sizeof(d));

    return calc((1 << N)-1, l) <= K;
}

int solve()
{
    int a = 0;
    int b = 100000;

    while (a < b-1)
    {
        int c = (a+b)/2;

        if (can(c))
            b = c;
        else
            a = c;
    }

    return b;
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    int T;
    cin >> T;

    for (int t=1; t <= T; t++)
    {
        cin >> N >> K;
        for (int i=0; i < N; i++)
            cin >> x[i] >> y[i];

        cout << "Case #" << t << ": " << solve() << endl;
    }

    return 0;
}
