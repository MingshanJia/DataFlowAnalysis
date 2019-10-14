#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define valid(i, j) ((i) >= 0 && (i) < n && (j) >= 0 && (j) < n)

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

bool visited[1010][1010];
int t, n, ar[1010][1010], val[1010][1010];

void dfs(int i, int j){
    visited[i][j] = true;

    int d, k, l;
    for (d = 0; d < 4; d++){
        k = i + dx[d], l = j + dy[d];
        if (valid(k, l)){
            if (ar[k][l] == (ar[i][j] + 1)){
                if (!visited[k][l]){
                    val[k][l] = 1;
                    dfs(k, l);
                }
                val[i][j] = val[k][l] + 1;
            }
        }
    }
}

int main(){
    int T = 0, i, j, k;

    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                scanf("%d", &ar[i][j]);
            }
        }

        clr(visited), clr(val);
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                if (!visited[i][j]){
                    val[i][j] = 1;
                    dfs(i, j);
                }
            }
        }

        int res = -1, idx = -1;
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                int x = ar[i][j];
                int r = val[i][j];
                if ((r > res) || (r == res && x < idx)){
                    res = r;
                    idx = x;
                }
            }
        }

        printf("Case #%d: %d %d\n", ++T, idx, res);
    }
    return 0;
}

