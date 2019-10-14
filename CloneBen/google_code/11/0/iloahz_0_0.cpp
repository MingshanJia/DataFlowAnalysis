#include <set>
#include <cmath>
#include <map>
#include <cassert>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

typedef double db;
const db EPS = 1e-8;

const int MAXN = 55;

int n, m;
int a[MAXN][MAXN];

void init(){
    if (scanf("%d", &n) == EOF) exit(0);
    m = n * n;
    for (int i = 0;i < m;i++){
        for (int j = 0;j < m;j++){
            scanf("%d", &a[i][j]);
        }
    }
}

int t[MAXN];
bool v[MAXN];
bool ck(int a[]){
    for (int i = 0;i <= m;i++) v[i] = false;
    int cnt = 0;
    for (int i = 0;i < m;i++){
        if (a[i] < 1 || a[i] > m) return false;
        if (v[a[i]]) return false;
        v[a[i]] = true;
    }
    return true;
}

bool pd(){
    for (int i = 0;i < m;i++){
        if (!ck(a[i])) return false;
    }
    for (int i = 0;i < m;i++){
        for (int j = 0;j < m;j++){
            t[j] = a[j][i];
        }
        if (!ck(t)) return false;
    }
    int x = 0, y = 0;
    for (int i = 0;i < m;i++){
        int c = 0;
        for (int j = 0;j < n;j++){
            for (int k = 0;k < n;k++){
                t[c++] = a[x + j][y + k];
            }
        }
        if (!ck(t)) return false;
        y += n;
        if (y >= m){
            x += n;
            y = 0;
        }
    }
    return true;
}

void work(){
    printf("%s\n", pd() ? "Yes" : "No");
}

int main(){
#ifdef LATTE
//    freopen("a.in", "r", stdin);
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
#endif
    int T, t = 0;
    scanf("%d", &T);
    while (T--){
        init();
        printf("Case #%d: ", ++t);
        work();
    }
    return 0;
}
