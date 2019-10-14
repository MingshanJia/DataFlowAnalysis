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
#include <map>

using namespace std;


int n, m, a[200][211], ans;

void work() {
    scanf("%d%d", &n, &m);
    if (n > m) swap(n, m);
    if (n < 3) {
        if (n == 1) {
            printf("%d\n", m/3*2 + m%3);
        } else {
            printf("%d\n", m/3*4 + m%3*2);
        }
        return;
    }
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ans += a[i][j];
        }
    }
    printf("%d\n", ans);
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out", "w", stdout);
    for (int i = 1; i <= 110; ++i) {
        if (i%3 == 1) {
            for (int j = 1; j <= 110; j += 3) {
                a[i][j] = a[i][j+1] = 1;
            }
        } else if (i%3 == 2) {
            for (int j = 1; j <= 110; j += 3) {
                a[i][j] = a[i][j+2] = 1;
            }
        } else {
            for (int j = 1; j <= 110; j+= 3) {
                a[i][j+1] = a[i][j+2] = 1;
            }
        }
    }
    int TC;
    scanf("%d", &TC);
    for (int i  = 1; i <= TC; ++i) {
        printf("Case #%d: ", i);
        work();
    }
    return 0;
}