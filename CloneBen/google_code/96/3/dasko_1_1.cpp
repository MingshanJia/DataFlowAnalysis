#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(AA,BB) for(AA=0; AA<BB; ++AA)
#define FOR(AA,BB,CC) for(AA=BB; AA<CC; ++AA)
#define FC(AA,BB) for(typeof(AA.begin()) BB=AA.begin(); BB!=AA.end(); ++BB)

using namespace std;

int c[110][110], dx[]={-1,0,0,1}, dy[]={0,-1,1,0};
int col[110][110], cur, n, m;

int rec(int a, int b) {
	if(col[a][b]!=-1)
		return col[a][b];
	int k, x, y, d, e, mn=c[a][b];
	REP(k,4) {
		x=a+dx[k]; y=b+dy[k];
		if(x>=0 && x<n && y>=0 && y<m && c[x][y]<mn) {
			d=x; e=y;
			mn=min(c[x][y], mn);
		}
	}
	if(mn==c[a][b])
		col[a][b]=++cur;
	else
		col[a][b]=rec(d,e);
	return col[a][b];
}

int main(void) {
	int T, t, i, j, k;
	scanf("%d", &T);
	REP(t,T) {
		scanf("%d%d", &n, &m);
		REP(i,n) {
			REP(j,m)
				scanf("%d", &c[i][j]);
		}
		memset(col, -1, sizeof col); cur='a'-1;
		printf("Case #%d:\n", t+1);
		REP(i,n) {
			REP(j,m)
				printf("%c ", rec(i,j));
			puts("");
		}
	}
	return 0;
}
	
