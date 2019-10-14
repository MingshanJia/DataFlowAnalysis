#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;

ll pow2[100005];
ll fact[200005];
ll inv[200005];

ll powMod(ll x, ll y) {
    if (y == 0) return 1;

    ll ret = powMod(x, y/2);
    ret = (ret*ret)%MOD;
    if (y%2) ret = (ret*x)%MOD;
    return ret;
}

ll comb(int a, int b) {
    if (b > a) return 0;

    ll ret = (fact[a] * inv[b])%MOD;
    ret = (ret * inv[a-b])%MOD;

    return ret;
}

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);

    ll ans = fact[2*n];
    for (int i = 1; i <= m; i++) {
        ll tmp = (fact[2*n - i] * comb(m, i))%MOD;
        tmp = (tmp * pow2[i])%MOD;
        if (i%2) {
            ans = (ans - tmp + MOD)%MOD;
        } else {
            ans = (ans + tmp)%MOD;
        }
    }
    printf("%lld\n", ans);
}

void precomp() {
    pow2[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        pow2[i] = (pow2[i-1]<<1)%MOD;
    }

    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        fact[i] = (fact[i-1]*i)%MOD;
        inv[i] = powMod(fact[i], MOD-2);
    }
}

int main() {
    precomp();

    int qt;
    scanf("%d", &qt);

    for (int q = 0; q < qt; q++) {
        printf("Case #%d: ", q+1);
        solve();
    }
}