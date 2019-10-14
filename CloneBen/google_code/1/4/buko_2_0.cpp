#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair <int,int> ii;
typedef pair <int, ii> iii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;

const int N = 105;

int tab[N][N], D[N][N], n, m, i, j, sx, sy, tx, ty, z, q, st;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool isOk(int a, int b) {
	return a >= 0 && a < n && b >= 0 && b < m && tab[a][b] != -100000;
}

void dijkstra () {
          set<iii> Q;
          iii top;
          int d, cost,i, j;
		  ii v, v2;
          for (i=0;i<n;i++) for (j=0;j<m;j++) D[i][j]=INF;
          D[sx][sy] = 0;
          Q.insert(iii(0,ii(sx, sy)));
          while(!Q.empty()) {
               top = *Q.begin();
               Q.erase(Q.begin());
               v = top.second;
               d = top.first;
			   for (i=0;i<4;i++) if (isOk(v.first + dx[i], v.second + dy[i])) {
                   v2 = ii(v.first + dx[i], v.second + dy[i]);
                   cost = -tab[v.first + dx[i]][v.second + dy[i]];
                   if (D[v2.first][v2.second] > D[v.first][v.second] + cost) {
                      if (D[v2.first][v2.second] != INF) Q.erase(Q.find(iii(D[v2.first][v2.second],v2)));
                      D[v2.first][v2.second] = D[v.first][v.second] + cost;
                      Q.insert(iii(D[v2.first][v2.second], v2));
                   }
               }
          }
}

int main() {
scanf("%d", &z);
for (q=1;q<=z;q++) {
	scanf("%d %d %d %d %d %d %d", &n, &m, &st, &sx, &sy, &tx, &ty);
	sx--;
	sy--;
	tx--;
	ty--;
	for (i=0;i<n;i++) for (j=0;j<m;j++) scanf("%d", &tab[i][j]);
	dijkstra();
	/*for (i=0;i<n;i++) {
		for (j=0;j<m;j++) printf("%d ", D[i][j]);
		printf("\n");
	}*/
	if (D[tx][ty] == INF || D[tx][ty] > st) D[tx][ty] = st + 1;
	printf("Case #%d: %d\n", q, st - D[tx][ty]);
}
return 0;
}