#include <bits/stdtr1c++.h>

#define MAX 1000010
#define inf (1 << 27)
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

typedef pair<int, int> Pair;
typedef pair<Pair, Pair> dPair;

set <dPair> S;
vector <Pair> v[105][105];
vector <int> tunnel_time[105][105];
int t, n, m, wait[105], station[105], time_taken[105][105], dis[2][105][105];

int dijkstra(int si, int sj, int di, int dj){
    S.clear();
    int paid;
    int i, j, k, l, x, cost, flag, c, d;

    for (i = 0; i < 105; i++){
        for (j = 0; j < 105; j++){
            dis[0][i][j] = inf;
            dis[1][i][j] = inf;
        }
    }

    dis[0][si][sj] = 0;
    S.insert(dPair(Pair(0, 0), Pair(si, sj)));

    while (!S.empty()){
        dPair cur = *(S.begin());
        S.erase(cur);

        paid = (cur.first).second;
        i = (cur.second).first;
        j = (cur.second).second;
        if (i == di && j == dj) return dis[paid][i][j];

        if ((j + 1) < station[i]){
            flag = 1, c = i, d = j + 1;
            cost = time_taken[i][j];
            if (!paid) cost += wait[i];

            if (dis[flag][c][d] > dis[paid][i][j] + cost){
                dis[flag][c][d] = dis[paid][i][j] + cost;
                S.insert(dPair(Pair(dis[flag][c][d], flag), Pair(c, d)));
            }
        }

        if ((j - 1) >= 0){
            flag = 1, c = i, d = j - 1;
            cost = time_taken[i][j - 1];
            if (!paid) cost += wait[i];

            if (dis[flag][c][d] > dis[paid][i][j] + cost){
                dis[flag][c][d] = dis[paid][i][j] + cost;
                S.insert(dPair(Pair(dis[flag][c][d], flag), Pair(c, d)));
            }
        }

        int len = v[i][j].size();
        for (l = 0; l < len; l++){
            c = v[i][j][l].first, d = v[i][j][l].second, flag = 0;
            cost = tunnel_time[i][j][l];

            if (dis[flag][c][d] > dis[paid][i][j] + cost){
                dis[flag][c][d] = dis[paid][i][j] + cost;
                S.insert(dPair(Pair(dis[flag][c][d], flag), Pair(c, d)));
            }
        }
    }

    return -1;
}

int main(){
    read();
    write();
    int T = 0, i, j, q, a, b, c, d, e;

    scanf("%d", &t);
    while (t--){
        clr(v), clr(tunnel_time);

        scanf("%d", &n);
        for (i = 0; i < n; i++){
            scanf("%d %d", &station[i], &wait[i]);
            for (j = 0; j < station[i] - 1; j++) scanf("%d", &time_taken[i][j]);
        }

        scanf("%d", &m);
        while (m--){
            scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
            a--, b--, c--, d--;
            v[a][b].push_back(Pair(c, d));
            v[c][d].push_back(Pair(a, b));
            tunnel_time[a][b].push_back(e);
            tunnel_time[c][d].push_back(e);
        }
        printf("Case #%d:\n", ++T);

        scanf("%d", &q);
        while (q--){
            scanf("%d %d %d %d", &a, &b, &c, &d);
            a--, b--, c--, d--;
            int res = dijkstra(a, b, c, d);
            printf("%d\n", res);
        }
    }
    return 0;
}
