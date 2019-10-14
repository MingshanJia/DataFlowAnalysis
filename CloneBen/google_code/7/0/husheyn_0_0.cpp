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
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {-1, 1, 0, 0};

int T, n;
int a[MAXN][MAXN];
int d[MAXN][MAXN];

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &a[i][j]);
        memset(d, 0, sizeof(d));
        bool flag = true;
        while (flag) {
            flag = false;
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    for(int k = 0; k < 4; ++k) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (0 <= x && x < n && 0 <= y && y < n && a[x][y] == a[i][j] + 1 && d[x][y] + 1 > d[i][j]) {
                            flag = true;
                            d[i][j] = d[x][y] + 1;
                        }
                    }
        }
        int x = -1, y = -1;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if (x == -1 || d[x][y] < d[i][j] || (d[x][y] == d[i][j] && a[x][y] > a[i][j])) {
                    x = i; y = j;
                }
        printf("Case #%d: %d %d\n", t, a[x][y], d[x][y] + 1);
    }
    return 0;
}