#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 505
int a[N], b[N];
int n, q;

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &a[i], &b[i]);
    scanf("%d", &q);
    while (q--)
    {
        int x;
        scanf("%d", &x);
        int s = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] <= x && x <= b[i])
                ++s;
        }
        printf(" %d", s);
    }
    puts("");
}

int main()
{
    int t;
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &t);
    for (int tt = 1; tt <= t; ++tt)
    {
        printf("Case #%d:", tt);
        solve();
    }
    return 0;
}