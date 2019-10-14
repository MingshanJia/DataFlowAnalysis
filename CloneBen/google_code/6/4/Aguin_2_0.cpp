#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 2e5 + 10;
ll fac[maxn], ifac[maxn], po[maxn];

inline ll C(ll n, ll m) {
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    fac[0] = 1;
    for(int i = 1; i < maxn; ++i) fac[i] = fac[i - 1] * i % mod;
    ifac[0] = ifac[1] = 1;
    for(int i = 2; i < maxn; ++i) ifac[i] = ifac[mod % i] * (mod - mod / i) % mod;
    for(int i = 3; i < maxn; ++i) ifac[i] = ifac[i - 1] * ifac[i] % mod;
    po[0] = 1;
    for(int i = 1; i < maxn; ++i) po[i] = po[i - 1] * 2 % mod;
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; ++kase) {
        int N, M;
        scanf("%d %d", &N, &M);
        ll ans = 0;
        for(int i = 0; i <= M; ++i) {
            ll tmp = C(M, i) * fac[N + N - i] % mod * po[i] % mod;
            if(i & 1) ans = (ans + mod - tmp) % mod;
            else ans = (ans + tmp) % mod;
        }
        printf("Case #%d: %lld\n", kase, ans);
    }
    return 0;
}