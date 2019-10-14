#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int T, n, q, x;
int a[MAXN], b[MAXN];

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d%d", a + i, b + i);
        scanf("%d", &q);
        printf("Case #%d:", t);
        for(int i = 0; i < q; ++i) {
            scanf("%d", &x);
            int cnt = 0;
            for(int j = 0; j < n; ++j)
                if (a[j] <= x && x <= b[j])
                    ++cnt;
            printf(" %d", cnt);
        }
        printf("\n");
    }
    return 0;
}