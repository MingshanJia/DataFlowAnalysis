#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;


double f[2111][2111];
int n, m;

void work() {
    scanf("%d%d", &n, &m);
    memset(f, 0, sizeof(f));
    f[1][0] = 1.0*n/(n+m);

    for (int i = 2; i <= n; ++i) {
        f[i][0] = 1.0*(n-(i-1))/(n+m-(i-1)) * f[i-1][0];
        //printf("%lf ", f[i][0]);
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i - 1 > j) {
                f[i][j] += 1.0*(n-(i-1))/(n+m-(i-1+j)) * f[i-1][j];
            }
            f[i][j] += 1.0*(m-(j-1))/(n+m-(i-1+j)) * f[i][j-1];
        }
    }
    printf("%.6lf\n", f[n][m]);
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int TC;
    scanf("%d", &TC);
    for (int i  = 1; i <= TC; ++i) {
        printf("Case #%d: ", i);
        work();
    }
    return 0;
}