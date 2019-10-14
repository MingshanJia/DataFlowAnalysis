#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long llong;

const int N = 1000500;
llong A[N];

llong S[N];

void solve(int cs)
{
    int n;
    llong p, q, r, s;
    scanf("%d", &n);
    scanf("%lld %lld %lld %lld", &p, &q, &r, &s);
    for (int i = 0; i < n; i++)
        A[i] = ((i * 1LL * p + q) % r + s);
    for (int i = 0; i < n; i++)
        S[i + 1] = S[i] + A[i];
    llong ss = S[n];
    llong mn = 1e18;
    for (int a = 0; a < n; a++)
    {
        llong u = S[a];
        int l = a, r = n;
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            llong v = S[m] - S[a], w = S[n] - S[m];
            if (v <= w)
                l = m;
            else
                r = m;
        }
        llong v1 = S[l] - S[a], w1 = S[n] - S[l];
        llong v2 = S[r] - S[a], w2 = S[n] - S[r];
        mn = min(mn, max(u, max(v1, w1)));
        mn = min(mn, max(u, max(v2, w2)));
    }

    printf("Case #%d: %.10lf\n", cs, 1 - mn * 1.0 / ss);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i + 1), fflush(stdout);
}
