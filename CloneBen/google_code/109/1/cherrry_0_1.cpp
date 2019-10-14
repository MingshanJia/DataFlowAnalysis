#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

int T, N;
int P[256];

int a[256][256];
int used[256];

int main() {

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        memset(a, 0, sizeof(a));
        memset(used, 0, sizeof(used));

        scanf("%d", &N);
        for (int n = 0; n < 2 * N; n++) {
            scanf("%d", &P[n]);
        }

        for (int i = 0; i < 2 * N; i++) {
            if (P[i] % 3) continue;

            for (int j = i + 1; j < 2 * N; j++) {
                if (P[j] % 4) continue;
                if ((P[i] / 3) == (P[j] / 4)) {
                    a[i][j] = 1;
                }
            }
        }

        printf("Case #%d:", t);
        for (int i = 0; i < 2 * N; i++) {
            if (used[i]) continue;
            for (int j = i + 1; j < 2 * N; j++) {
                if (used[j]) continue;

                if (a[i][j]) {
                    used[j] = 1;
                    printf(" %d", P[i]);
                    break;
                }
            }
        }
        puts("");
    }

    return 0;
}
