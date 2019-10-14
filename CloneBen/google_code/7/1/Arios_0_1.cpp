#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 1005

const int ix[4] = {0, 1, 0, -1};
const int iy[4] = {1, 0, -1, 0};

int n;
int a[N][N];
int dp[N][N];

int dfs(int x, int y) {
    int & ret = dp[x][y];
    if (-1 != ret) return ret;
    ret = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + ix[i], ny = y + iy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] != a[x][y] + 1)
            continue;
        ret = max(ret, dfs(nx, ny) + 1);
    }
    return ret;
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &a[i][j]);
        memset(dp, -1, sizeof(dp));
        int ans = 0, val;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                int len = dfs(i, j);
                if (len > ans) {
                    ans = len;
                    val = a[i][j];
                } else if (len == ans && a[i][j] < val)
                    val = a[i][j];
            }
        printf("Case #%d: %d %d\n", ++cas, val, ans);
    }
    return 0;
}
