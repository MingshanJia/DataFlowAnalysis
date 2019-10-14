#include <bits/stdtr1c++.h>

#define MAX 1000010
#define inf (1 << 25)
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

typedef pair<int, int> Pair;

set <Pair> S;
int t, dest, digit[10], dis[MAX];

void dfs(int x, int y, int cost){
    int i, r, z;
    for (i = 0; i < 10; i++){
        if (!y && !i) continue;

        if (digit[i]){
            z = (y * 10) + i;
            if (x) r = x * z;
            else r = z;

            if (r <= dest){
                if (dis[r] > dis[x] + cost){
                    dis[r] = dis[x] + cost;
                    S.insert(Pair(dis[i], r));
                }
                dfs(x, z, cost + 1);
            }
        }
    }
}

int dijkstra(){
    S.clear();
    int i, j, k;
    for (i = 0; i < MAX; i++) dis[i] = inf;

    dis[0] = 0;
    S.insert(Pair(dis[0], 0));
    while (!S.empty()){
        Pair temp = *(S.begin());
        S.erase(temp);

        int cur = temp.second;
        if (cur == dest) return dis[cur];

        dfs(cur, 0, 2);
    }
    return -1;
}

int main(){
    read();
    write();
    int T = 0, i, j;

    scanf("%d", &t);
    while (t--){
        for (i = 0; i < 10; i++) scanf("%d", &digit[i]);
        scanf("%d", &dest);

        int res = dijkstra();
        if (res == -1) printf("Case #%d: Impossible\n", ++T);
        else printf("Case #%d: %d\n", ++T, res);
    }
    return 0;
}
