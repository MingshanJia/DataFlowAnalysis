#include <cstdio>
#include <cstdlib>

int T, D, K, N;
int d[16];

void odd() {
    for (int i = 0; i < D; i += 2) {
        int c = d[i];
        d[i] = d[i+1];
        d[i+1] = c;
    }

    /*
    for (int i = 0; i < D; i++) {
        printf(" %d", d[i]);
    }
    puts(" (odd)");
    */
}

void even() {
    for (int i = 0; i < D; i += 2) {
        int x = i == 0 ? D - 1 : i - 1;
        int c = d[i];
        d[i] = d[x];
        d[x] = c;
    }

    /*
    for (int i = 0; i < D; i++) {
        printf(" %d", d[i]);
    }
    puts(" (even)");
    */
}

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d%d%d", &D, &K, &N);

        for (int i = 0; i < D; i++) {
            d[i] = i + 1;
        }

        /*
        for (int i = 0; i < D; i++) {
            printf(" %d", d[i]);
        }
        puts("");
        */

        for (int i = 1; i <= N; i++) {
            if (i & 1) {
                odd();
            } else {
                even();
            }
        }

        /*
        for (int i = 0; i < D; i++) {
            printf(" %d", d[i]);
        }
        puts(" (final)");
        */

        int k = -1;
        for (int i = 0; i < D; i++) {
            if (d[i] == K) k = i;
        }

        printf("Case #%d: %d %d\n", t, d[(k+1)%D], d[(k-1+D)%D]);
    }

    return 0;
}
