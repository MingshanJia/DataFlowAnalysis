#include <bits/stdc++.h>

using namespace std;

#define CLR(a, b) memset(a, b, sizeof(a))

const int maxn = 100100;
const int MOD = 1000000007;

vector<pair<int, long long> > G[maxn];

bool dp[maxn][2];

int odd, even, all;
int cnt[maxn];

void dfs(int u, int type, int sta) {
    if(dp[u][type]) return ;
    dp[u][type] = true;
    cnt[u] ++;
    if(cnt[u] == 2) all ++;
    if(type) even ++;
    else odd ++;
    for(int i = 0; i < G[u].size(); i ++) {
        int v = G[u][i].first; long long c = G[u][i].second;
        if(c & sta) {
            dfs(v, type ^ 1, sta);
        } else {
            dfs(v, type, sta);
        }
    }
}

int main() {
//    printf("%I64d\n", 1ll << 60);
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF) {
        for(int i = 1; i <= n; i ++) {
            G[i].clear();
        }
        for(int i = 0; i < m; i ++) {
            int u, v; long long c;
            scanf("%d%d%I64d", &u, &v, &c);
            G[u].push_back(make_pair(v, c));
            G[v].push_back(make_pair(u, c));
        }
        int ans = 0;
        for(int i = 0; i < 60; i ++) {
            CLR(dp, 0);
            CLR(cnt, 0);
            for(int j = 1; j <= n; j ++) {
                if(dp[j][0] || dp[j][1]) continue;
                all = odd = even = 0;
                dfs(j, 0, (1ll << i));
                int tmp = (1ll * odd * (even - all) + 1ll * all * (odd - all) + 1ll * (all - 1) * all / 2) % MOD;
                ans += 1ll * (1ll << i) % MOD * tmp % MOD;
                if(odd && even)printf("%d -- %d %d %d\n", i, odd, even, all);
                ans %= MOD;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
