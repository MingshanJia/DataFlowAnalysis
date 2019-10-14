#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static int deck[5001];

static inline void adv(int &p, int K)
{
    if (++p == K)
        p = 0;
}

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int K, n;
        cin >> K >> n;
        vector<int> D(n);
        for (int i = 0; i < n; i++)
        {
            cin >> D[i];
            D[i]--;
        }

        memset(deck, -1, sizeof(deck));
        int p = 0;
        for (int i = 0; i < K; i++)
        {
            while (deck[p] >= 0) adv(p, K);
            for (int j = 0; j < i; j++)
            {
                adv(p, K);
                while (deck[p] >= 0) adv(p, K);
            }
            deck[p] = i + 1;
        }

        cout << "Case #" << cas + 1 << ":";
        for (int i = 0; i < n; i++)
            cout << " " << deck[D[i]];
        cout << "\n";
    }
    return 0;
}
