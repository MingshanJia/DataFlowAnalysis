#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int N;
int bl[500][500];

int solve()
{
    int res = 0;
    int p[20];

    for (int i=0; i < N; i++)
        p[i] = i;

    do
    {
        bool good = true;
        for (int i=0; i < N && good; i++)
            good = good && !bl[p[i]][p[(i+1)%N]];

        if (good) res++;

    } while (next_permutation(p, p+N));

    res /= N;
    if (N > 2)
        res /= 2;
    return res%9901;
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);

    int T;
    cin >> T;
    for (int t=1; t <= T; t++)
    {
        int K;
        cin >> N >> K;
        memset(bl, 0, sizeof(bl));

        for (int i=0; i < K; i++)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;
            bl[a][b] = bl[b][a] = 1;
        }

        cout << "Case #" << t << ": " << solve() << endl;
    }
}
