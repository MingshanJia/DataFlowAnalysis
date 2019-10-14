#include <bits/stdtr1c++.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define dbg(x) cout << #x << " = " << x << endl
#define valid(i, j) ((i) >= 0 && (i) < n && (j) >= 0 && (j) < n)

using namespace std;

const int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
const int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};

char str[1010][1010];
bool visited[1010][1010];
int t, n, mines[1010][1010];

void dfs(int i, int j){
    int d, k, l;
    for (d = 0; d < 8; d++){
        k = i + dx[d], l = j + dy[d];
        if (valid(k, l) && !visited[k][l]){
            visited[k][l] = true;
            if (mines[k][l] == 0) dfs(k, l);
        }
    }
}

int main(){
    read();
    write();
    int T = 0, d, i, j, k, l;

    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        for (i = 0; i < n; i++) scanf("%s", str[i]);

        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                int x = 0;
                for (d = 0; d < 8; d++){
                    k = i + dx[d], l = j + dy[d];
                    if (valid(k, l) && str[k][l] == '*') x++;
                }
                mines[i][j] = x;
                if (str[i][j] == '*') mines[i][j] = -1;
            }
        }

        clr(visited);
        int counter = 0;
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                if (mines[i][j] == 0 && !visited[i][j]){
                    visited[i][j] = true;
                    dfs(i, j);
                    counter++;
                }
            }
        }

        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                if (mines[i][j] > 0 && !visited[i][j]) counter++;
            }
        }

        printf("Case #%d: %d\n", ++T, counter);
    }
    return 0;
}
