#include <cstdio>
#include <cstring>
using namespace std;

int N;
int items[205];
bool check[205];

int main() {

    int cases;
    scanf("%d", &cases);
    for (int T=1; T<=cases; ++T) {

        scanf("%d", &N);
        for (int i=0; i<2*N; ++i)
            scanf("%d", &items[i]);

        printf("Case #%d: ", T);
        memset(check, false, sizeof(check));
        for (int i=0; i<2*N; ++i) {
            if (check[i]) continue;
            if (items[i] % 3) continue;
            for (int j=0; j<2*N; ++j) {
                if (check[j]) continue;
                if (i == j) continue;

                if (items[j] % 4) continue;
                if (items[i] / 3 * 4 == items[j]) {
                    printf("%d ", items[i]);
                    check[i] = check[j] = true;
                    break;
                }
            }
        }
        printf("\n");

    }

    return 0;

}
