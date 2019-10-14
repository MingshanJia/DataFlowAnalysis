#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int n, m, e;
int sr, sc, tr, tc;
int v[N][N];

void read() {
  scanf("%d %d %d %d %d %d %d", &n, &m, &e, &sr, &sc, &tr, &tc);
  --sr, --sc, --tr, --tc;
  for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d", &v[i][j]);
}

bool vis[N][N];
int dist[N][N];

int solve() {
  read();
  
  for (int i=0; i<n; i++) for (int j=0; j<m; j++) vis[i][j] = false;
  
  priority_queue<pair<int, pair<int, int>>> pq;
  pq.push({0, {sr, sc}});
  
  int dx[4] = {0, -1, 0, 1}; int dy[4] = {1, 0, -1, 0};
  while (pq.size()) {
    int d = -pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;
    pq.pop();
    
    if (vis[x][y]) continue;
    vis[x][y] = true;
    dist[x][y] = d;
    
    for (int i=0; i<4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (vis[nx][ny]) continue;
      if (v[nx][ny] == -100000) continue;
      
      pq.push({-d + v[nx][ny], {nx, ny}});
    }
  }
  
  if (!vis[tr][tc]) return 0 * printf("-1\n");
  if (dist[tr][tc] > e) return 0 * printf("-1\n");
  
  printf("%d\n", e - dist[tr][tc]);
  
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tc=0; tc<t; ++tc) {
    printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}
