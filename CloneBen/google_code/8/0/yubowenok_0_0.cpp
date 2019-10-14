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
#define MAXN 305

int N;
int bd[MAXN][MAXN];
char buf[MAXN];
bool v[MAXN][MAXN];
int dir[8][2] = { -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1 };
void dfs(int x, int y){
	if (x < 1 || y < 1 || x > N || y > N || bd[x][y]==-1 || v[x][y]) return;
	v[x][y] = 1;
	if (bd[x][y] > 0) return;
	REP(t, 0, 8){
		int nx = x + dir[t][0], ny = y + dir[t][1];
		dfs(nx, ny);
	}
}
int main(){
	int cs;
	cin >> cs;
	REP(csn, 1, cs + 1){
		printf("Case #%d: ", csn);
		cin >> N;
		FILL(bd, 0);
		REP(i, 1, N + 1) {
			scanf("%s", buf+1);
			REP(j, 1, N+1){
				if (buf[j] == '*') bd[i][j] = -1;
			}
		}
		REP(i, 1, N + 1)REP(j, 1, N + 1){
			if (bd[i][j] == -1) continue;
			REP(t, 0, 8){
				int ni = i + dir[t][0], nj = j + dir[t][1];
				if (bd[ni][nj] == -1) bd[i][j]++;
			}
		}
		FILL(v, 0);
		int ans = 0;
		REP(i, 1, N + 1) REP(j, 1, N + 1){
			if (!v[i][j] && bd[i][j] == 0){
				dfs(i, j);
				ans++;
			}
		}
		REP(i, 1, N + 1) REP(j, 1, N + 1){
			if (!v[i][j] && bd[i][j] > 0) ans++;
		}
		printf("%d\n", ans);
	}
}