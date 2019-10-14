#include <cstdio>
#include <cstring>
const long long int DIVIDER = 1000000007;

long long int cons, vows, length;
long long int D[505];

int main() {

    int cases;
    scanf("%d", &cases);
    for (int T=1; T<=cases; ++T) {
        scanf("%lld %lld %lld", &cons, &vows, &length);

        memset(D, 0, sizeof(D));
        D[0] = 1;
        D[1] = vows;
        for (int i=2; i<=length; ++i) {
            D[i] = (D[i-1] * vows) % DIVIDER + (D[i-2] * cons * vows) % DIVIDER;
            D[i] %= DIVIDER;
        }

        printf("Case #%d: %lld\n", T, D[length]);
    }

    return 0;

}
