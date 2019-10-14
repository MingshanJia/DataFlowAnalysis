//#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;

#define boost ios::sync_with_stdio(0); cin.tie(0)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

const int N = 1e6 + 5;
const int X = 100000;
const ll INF = 1e18;

/***************************************************************************/

int dx[] = { 0, 0, 1,-1};
int dy[] = { 1,-1, 0, 0};

ll V[105][105];
ll dist[105][105];

int main() {

	boost;
	int T; cin>>T;
	for(int test=1; test<=T; test++) {
		int n, m; cin>>n>>m;
		ll e; cin>>e;
		int si, sj, ti, tj; cin>>si>>sj>>ti>>tj;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cin>>V[i][j];
				dist[i][j] = INF;
			}
		}
		queue<pair<pii, ll> > Q;
		dist[si][sj] = 0;
		Q.push(mp(mp(si, sj), dist[si][sj]));

		while(!Q.empty()) {
			auto it = Q.front(); Q.pop();
			int vx = it.fi.fi, vy = it.fi.se;
			ll vdis = it.se;

			//debug3(vx, vy, vdis);

			for(int i=0; i<4; i++) {
				int x = vx + dx[i], y = vy + dy[i];
				if(x < 1 or x > n or y < 1 or y > m or V[x][y] == -X) {
					continue;
				}
				if(vdis - V[x][y] < dist[x][y]) {
					dist[x][y] = vdis - V[x][y];
					Q.push(mp(mp(x, y), dist[x][y]));
				}
			}
		}

		cout<<"Case #"<<test<<": ";

		if(dist[ti][tj] > e) cout<<"-1\n";
		else cout<<e - dist[ti][tj]<<"\n";
	}
	
	return 0;
}