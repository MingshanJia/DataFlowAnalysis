#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
typedef pair<int, int> P;

#define ft first
#define sd second

int mat[1055][1055];

queue<P> que;

int id[1055][1055];
bool used[1055][1055];

void solve() {
	int n, m, e;
	P s, t;
	cin >> n >> m >> e >> s.ft >> s.sd >> t.ft >> t.sd;
	
	s.ft--, s.sd--;
	t.ft--, t.sd--;
	
	int trapSize = 0;
	
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		scanf("%d", &mat[i][j]);
		id[i][j] = -1;
		
		if (mat[i][j] < 0 && mat[i][j] > -100000) {
			id[i][j] = trapSize++;
		}
	}
	
	long long res = -1;
	
	for (int mask = 0; mask < (1 << trapSize); mask++) {
		long long tot = e;
		
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			used[i][j] = false;
		}
		
		que.push(s);
		used[s.ft][s.sd] = false;
		
		while (!que.empty()) {
			P p = que.front(); que.pop();
			
			for (int i = 0; i < 4; i++) {
				int nx = p.ft + dx[i];
				int ny = p.sd + dy[i];
				
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (mat[nx][ny] == -100000) continue;
					if (mat[nx][ny] < 0 && !(mask & (1 << id[nx][ny]))) {
						continue;
					}
					if (used[nx][ny]) continue;
					
					used[nx][ny] = true;
					tot += mat[nx][ny];
					que.push(P(nx, ny));
				}
			}
		}
		
		if (!used[t.ft][t.sd]) continue;
		res = max(res, tot);
	}
	
	printf("%lld\n", res);
}
int main() {
	int _t;
	cin >> _t;
	
	for (int _ = 0; _ < _t; _++) {
		printf("Case #%d: ", _ + 1);
		solve();
		cerr << "Finish solving " << (_ + 1) << " / " << _t << " cases\n";
	}
}
