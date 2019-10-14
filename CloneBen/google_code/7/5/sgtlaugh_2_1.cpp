#include <bits/stdtr1c++.h>

#define MAX 20010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

int t, n, m, deg[MAX];
vector <int> adj[MAX];
unordered_map <string, int> A;
unordered_map <int, string> B;

void dfs(int i){
    int j, len = adj[i].size();
    for (j = 0; j < len; j++){
        int x = adj[i][j];
        cout << " " << B[i] << "-" << B[x];
        dfs(x);
    }
}

int main(){
    int T = 0, i, j;
    string src, dest;

    cin >> t;
    while (t--){
        cin >> m;
        clr(deg);
        A.clear(), B.clear();
        for (i = 0; i < MAX; i++) adj[i].clear();

        n = 0;
        int root = 0;

        while (m--){
            cin >> src >> dest;
            if (!A[src]){
                A[src] = ++n;
                B[n] = src;
            }
            if (!A[dest]){
                A[dest] = ++n;
                B[n] = dest;
            }

            int a = A[src], b = A[dest];
            adj[a].push_back(b);
            deg[b]++;
        }

        for (i = 1; i <= n; i++){
            if (!deg[i]) root = i;
        }

        printf("Case #%d:", ++T);
        dfs(root);
        puts("");
    }
    return 0;
}
