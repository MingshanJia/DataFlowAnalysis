#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++) {
        int n, m;
        scanf("%d%d", &n, &m);
        int ans[3] = {0, 0, 0};
        for (int i = 2; i <= n + m; i++) {
            int num = 0;
            int x = 1, y = i - 1;
            if (y > m) { y = m; x = i - m; }
            int a = i - 1, b = 1;
            if (a > n) { a = n; b = i - n; }
            num = a - x + 1;
            ans[i % 3] += num;
        }
        if ((n <= 2) && (m <= 2)) { ans[0] = 0; }
        else if (n <= 2) {
            ans[0] = m / 3 * n;
        } else if (m <= 2) {
            ans[0] = n / 3 * m;
        }
        printf("Case #%d: %d\n", t, n * m - min(ans[0], min(ans[1], ans[2])));;
    }
    return 0;
}
