#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)

int t, n, counter[5010];

int main(){
    int T = 0, i, j, k, x, y;

    scanf("%d", &t);
    while (t--){
        clr(counter);
        scanf("%d", &n);

        while (n--){
            scanf("%d %d", &x, &y);
            for (i = x; i <= y; i++) counter[i]++;
        }

        scanf("%d", &n);
        printf("Case #%d:", ++T);
        while (n--){
            scanf("%d", &k);
            printf(" %d", counter[k]);
        }
        puts("");
    }
    return 0;
}
