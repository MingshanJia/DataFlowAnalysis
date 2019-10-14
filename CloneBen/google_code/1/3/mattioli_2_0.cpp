#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MAX = 100 + 5;
const int INF = (int) 2e9;
const vector<ii> dir {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int mat[MAX][MAX], bad_id[MAX][MAX];
bool visited[MAX][MAX];
bool has_path[1 << 15];
int max_energy[1 << 15], price[1 << 15], memo[1 << 15];
int n, m, e, sr, sc, tr, tc;
vector<ii> bads;

bool passable(int x, int y, int mask) {
    if(bad_id[x][y] != -1 && !(mask & (1 << bad_id[x][y]))) {
        return false;
    }
    return 1 <= x && x <= n && 1 <= y && y <= m && mat[x][y] != -100000;
}

void bfs(int mask) {
    memset(visited, false, sizeof visited);
    queue<ii> q;
    q.emplace(sr, sc);
    visited[sr][sc] = true;
    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        if(x == tr && y == tc) {
            has_path[mask] = true;
        }
        if(mat[x][y] > 0) {
            max_energy[mask] += mat[x][y];
        }
        for(auto &each : dir) {
            int nx = x + each.first;
            int ny = y + each.second;
            if(passable(nx, ny, mask) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }
}

int roll(int mask) {
    int cur_energy = e - price[mask] + max_energy[mask];
    if(mask == (int) bads.size()) {
        return has_path[mask] ? cur_energy : -INF;
    }
    int &ans = memo[mask];
    if(~ans) {
        return ans;
    }
    ans = has_path[mask] ? cur_energy : -INF;
    fori(i, 0, bads.size()) {
        if(!(mask & (1 << i))) {
            ii p = bads[i];
            int ne = abs(mat[p.first][p.second]);
            if(ne > cur_energy) {
                continue;
            }
            ans = max(ans, roll(mask | (1 << i)));
        }
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    int kase = 1;
    while(t--) {
        bads.clear();
        memset(bad_id, -1, sizeof bad_id);
        memset(has_path, false, sizeof has_path);
        memset(max_energy, 0, sizeof max_energy);
        memset(price, 0, sizeof price);
        scanf("%d %d %d %d %d %d %d", &n, &m, &e, &sr, &sc, &tr, &tc);
        fori(i, 1, n + 1) {
            fori(j, 1, m + 1) {
                scanf("%d", &mat[i][j]);
                if(mat[i][j] < 0 && mat[i][j] != -100000) {
                    bad_id[i][j] = bads.size();
                    bads.emplace_back(i, j);
                }
            }
        }
        fori(i, 0, 1 << (int) bads.size()) {
            bfs(i);
            fori(j, 0, (int) bads.size()) {
                if(i & (1 << j)) {
                    price[i] += abs(mat[bads[j].first][bads[j].second]);
                }
            }
        }
        memset(memo, -1, sizeof memo);
        int ans = roll(0);
        printf("Case #%d: %d\n", kase++, ans == -INF ? -1 : ans);
        cerr << "Case " << kase - 1 << endl;
    }
    return 0;
}
