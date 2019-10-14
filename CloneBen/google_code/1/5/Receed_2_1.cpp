#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 101, INF = 100000;
int n, m, it, sx, sy, tx, ty, fl;
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
ll a[N][N], num[N][N], trp[16];
int used[N][N];

ll dfs(int x, int y, int ms) {
    used[x][y] = it;
    if (x == tx && y == ty)
        fl = 1;
    ll ans = max(a[x][y], 0ll);
    for (int i = 0; i < 4; i++) {
        int cx = x + d[i][0], cy = y + d[i][1];
        if (0 <= cx && cx < n && 0 <= cy && cy < m && used[cx][cy] < it && (a[cx][cy] >= 0 || num[cx][cy] >= 0 && (ms & (1 << num[cx][cy]))))
            ans += dfs(cx, cy, ms);
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#else
    //freopen("f.in", "r", stdin); 
    //freopen("f.out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    scanf("%d", &t);
    for (int z = 1; z <= t; z++) {
        int e, tr = 0;
        it = 0;
        scanf("%d%d%d%d%d%d%d", &n, &m, &e, &sx, &sy, &tx, &ty);
        sx--; sy--;
        tx--; ty--;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%lld", &a[i][j]);
                if (a[i][j] < 0 && a[i][j] >  -INF) {
                    trp[tr] = -a[i][j];
                    num[i][j] = tr++;
                }
                else
                    num[i][j] = -1;
                used[i][j] = 0;
            }
        }
        int mx = 1 << tr;
        vector<ll> dp(mx, -1);
        dp[0] = 0;
        ll ans = -1;
        for (int i = 0; i < mx; i++) {
            if (dp[i] < 0)
                continue;
            fl = 0;
            it++;
            dp[i] = e + dfs(sx, sy, i);
            for (int j = 0; j < tr; j++)
                if (i & (1 << j))
                    dp[i] -= trp[j];
            if (fl)
                ans = max(ans, dp[i]);
            for (int j = 0; j < tr; j++) {
                if (!(i & (1 << j)) && dp[i] >= trp[j])
                    dp[i | (1 << j)] = 0;
            }
        }
        printf("Case #%d: %lld\n", z, ans);
    }
}
