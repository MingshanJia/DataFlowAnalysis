#include <bits/stdc++.h>

using namespace std;

const int maxn = 510, mod = 1e9 + 7;

long long d[maxn];

int main() {
    int t;
    scanf("%d", &t);
    for (int test = 1; test <= t; ++test) {
        int c, v, l;
        scanf("%d%d%d", &c, &v, &l);
        for (int i = 0; i <= l; ++i) {
            d[i] = 0;
        }
        d[0] = 1;
        for (int i = 1; i <= l; ++i) {
            d[i] = (v *(long long)d[i - 1]) % mod;
            if (i > 1) {
                d[i] += (c*v*(long long)d[i - 2]) % mod;
            }
            d[i] %= mod;
        }
        printf("Case #%d: ", test);
        printf("%d\n", (int)d[l]);
    }    
    return 0;
}