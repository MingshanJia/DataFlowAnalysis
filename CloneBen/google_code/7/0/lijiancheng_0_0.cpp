#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
#define N 1005
int a[N][N];
int ans, anss;
int n;

int get(int i, int j)
{
    for (int k = 0; k < 4; ++k)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 0 && x < n && y >= 0 && y < n && a[x][y] == a[i][j] + 1)
            return get(x, y) + 1;
    }
    return 1;
}

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &a[i][j]);
    ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            int s = get(i, j);
            if (s > ans)
            {
                ans = s;
                anss = a[i][j];
            }
            else if (s == ans && a[i][j] < anss)
            {
                anss = a[i][j];
            }
        }
    printf("%d %d\n", anss, ans);
}

int main()
{
    int t;
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &t);
    for (int tt = 1; tt <= t; ++tt)
    {
        printf("Case #%d: ", tt);
        solve();
    }
    return 0;
}