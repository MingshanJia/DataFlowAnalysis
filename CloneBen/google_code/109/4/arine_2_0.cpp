#include <cstdio>
#include <cstring>
const int DIVIDER = 1000000007;

int cons, vows, length;
int D[505];

int main() {

    int cases;
    scanf("%d", &cases);
    for (int T=1; T<=cases; ++T) {
        scanf("%d %d %d", &cons, &vows, &length);

        memset(D, 0, sizeof(D));
        D[0] = 1;
        D[1] = vows;
        for (int i=2; i<=length; ++i) {
            D[i] = (D[i-1] * vows) % DIVIDER + (D[i-2] * cons * vows) % DIVIDER;
            D[i] %= DIVIDER;
        }

        printf("Case #%d: %d\n", T, D[length]);
    }

    return 0;

}
