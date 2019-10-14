#include <cstdio>
#include <algorithm>
using namespace std;

int dancers, K, turns;
int floor[15];

int main() {

    int cases;
    scanf("%d", &cases);
    for (int T=1; T<=cases; ++T) {
        scanf("%d %d %d", &dancers, &K, &turns);

        printf("Case #%d: ", T);

        for (int i=0; i<dancers; ++i)
            floor[i] = i+1;

        for (int i=1; i<=turns; ++i) {
            for (int j=0; j<dancers; j+= 2) {
                if (i % 2)
                    swap(floor[j], floor[(j+1) % dancers]);
                else
                    swap(floor[j], floor[(j-1+dancers) % dancers]);
            }
        }

        for (int i=0; i<dancers; ++i) {
            if (floor[i] == K)
                printf("%d %d\n", floor[(i+1) % dancers], floor[(i-1+dancers) % dancers]);
        }
    }

    return 0;

}
