#include <bits/stdc++.h>
typedef long long ll;
int vis[111], len[111];
char s[111][111];

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; ++kase) {
        int N, P;
        scanf("%d %d", &N, &P);
        for(int i = 1; i <= P; ++i) {
            vis[i] = 0;
            scanf("%s", s[i]);
            len[i] = strlen(s[i]);
        }
        for(int i = 1; i <= P; ++i) {
            if(vis[i]) continue;
            for(int j = 1; j <= P; ++j) {
                if(vis[j] || j == i || len[j] < len[i]) continue;
                int same = 1;
                for(int k = 0; k < len[i]; ++k)
                    if(s[i][k] != s[j][k]) same = 0;
                if(same) vis[j] = 1;
            }
        }
        ll ans = 1ll << N;
        for(int i = 1; i <= P; ++i) {
            if(vis[i]) continue;
            ans -= 1ll << (N - len[i]);
        }
        printf("Case #%d: %lld\n", kase, ans);
    }
    return 0;
}