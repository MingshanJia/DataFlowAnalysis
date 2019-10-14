#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 1005
#define MAXM 220005

int N,M,Q;
int sz[MAXN], W[MAXN];
int adj[MAXN][MAXN], dst[MAXN][MAXN][2];
int L, lid[MAXM], loff[MAXM], lw[MAXM], lnxt[MAXM];
void il(int a, int i, int b, int j, int w){
	lnxt[L] = adj[a][i];
	lid[L] = b;
	loff[L] = j;
	lw[L] = w;
	adj[a][i] = L++;
}
struct dij{
	int x, i, r, d;
	dij(int _x, int _i, int _r, int _d){ x = _x; i = _i; r = _r;  d = _d; }
	bool operator < (const dij &ano) const{
		return d > ano.d;
	}
};

int main(){
	int cs;
	cin >> cs;
	REP(csn, 1, cs + 1){
		printf("Case #%d:\n", csn);
		cin >> N;
		L = 0; FILL(adj, -1);
		REP(i, 0, N){
			scanf("%d%d", sz + i, W + i);
			REP(j, 0, sz[i]-1){
				int w;
				scanf("%d", &w);
				il(i, j, i, j + 1, w);
				il(i, j + 1, i, j, w);
			}
		}
		cin >> M;
		REP(mi, 0, M){
			int a, i, b, j, w;
			scanf("%d%d%d%d%d", &a, &i, &b, &j, &w);
			a--; i--; b--; j--;
			il(a, i, b, j, w);
			il(b, j, a, i, w);
		}
		cin >> Q;
		REP(qi, 0, Q){
			int sx, sy, ex, ey;
			scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
			sx--; sy--; ex--; ey--;
			priority_queue<dij> pq;
			REP(i, 0, N) REP(j, 0, sz[i]) REP(r,0,2) dst[i][j][r] = INF;
			dst[sx][sy][0] = 0;
			pq.push(dij(sx, sy, 0, 0));
			while (!pq.empty()){
				dij now = pq.top(); pq.pop();
				int x = now.x, i = now.i, r = now.r,  d = now.d;
				if (d > dst[x][i][r]) continue;
				int t = adj[x][i];
				while (t != -1){
					int y = lid[t], j = loff[t];
					int nd = d + lw[t], nr = r;
					if (y == x){
						if (r == 0) {
							nd += W[x];
							nr = 1;
						}
					} else if (y != x) {
						nr = 0;
					}
					if (nd < dst[y][j][nr]){
						dst[y][j][nr] = nd;
						pq.push(dij(y, j, nr, nd));
					}
					t = lnxt[t];
				}
			}
			int ans = min(dst[ex][ey][0], dst[ex][ey][1]);
			if (ans == INF) ans = -1;
			printf("%d\n", ans);
		}
	}
}