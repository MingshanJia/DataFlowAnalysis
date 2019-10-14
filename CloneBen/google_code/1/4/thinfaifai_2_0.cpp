#include<bits/stdc++.h>
using namespace std;
#define LL long long

struct coor {
	int x,y;
} obs[22],st,tar;

int n,m,e,g[105][105];
int ocnt = 0,ostr[22];
int v[105][105];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

bool ffill(coor at) {
	if (at.x == tar.x && at.y == tar.y) {
		return true;
	}
	bool ans = false;
	v[at.x][at.y] = 1;
	for (int d=0; d<4; d++) {
		coor nat;
		nat.x = at.x+dx[d]; nat.y = at.y+dy[d];
		if (nat.x >= 0 && nat.x < n && nat.y >= 0 && nat.y < m && v[nat.x][nat.y] == 0 && g[nat.x][nat.y] >= 0) {
			ans = ffill(nat);
			if (ans) return ans;
		}
	}
	//printf(" %d,%d = %d\n",at.x,at.y,ans);
	return ans;
}

int main() {
	int tc;
	scanf("%d",&tc);
	for (int t=1; t<=tc; t++) {
        scanf("%d%d%d%d%d%d%d",&n,&m,&e,&st.x,&st.y,&tar.x,&tar.y);
        st.x--; st.y--; tar.x--; tar.y--;
        ocnt = 0;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				scanf("%d",&g[i][j]);
				if (g[i][j] < 0 && g[i][j] != -100000) {
					obs[ocnt].x = i; obs[ocnt].y = j;
					ostr[ocnt] = g[i][j];
					ocnt++;
				}
			}
		}
		LL ret = -1;
		for (int i=0; i<(1<<ocnt); i++) {
			LL used = 0;
			for (int j=0; j<ocnt; j++) {
				if (i & (1<<j)) {
					used += g[obs[j].x][obs[j].y];
				}
			}
			if (e+used <= ret) continue;

			//printf("try %d = %lld\n",i,used);

			for (int j=0; j<ocnt; j++) {
				if (i & (1<<j)) {
					g[obs[j].x][obs[j].y] = 0;
				}
			}

			memset(v,0,sizeof(v));
			bool reach = ffill(st);
			if (reach) {
				ret = e+used;
			}

			for (int j=0; j<ocnt; j++) {
				if (i & (1<<j)) {
					g[obs[j].x][obs[j].y] = ostr[j];
				}
			}
		}
        printf("Case #%d: %lld\n",t,ret); fflush(stdout);
	}
	return 0;
}
