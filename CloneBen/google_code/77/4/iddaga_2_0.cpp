#include <stdio.h>
#include <memory.h>
#define MN 128
#define MOD 1000003
int n, m, r;
char d[MN][MN];
int deg[MN][MN];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t, T, x, i, j, k, ii, jj;

	scanf("%d",&T);
	for (t = 1; t <= T; t++) {
		printf("Case #%d: ",t);
		scanf("%d%d",&n,&m);
		for (i = 0; i < n; i++)
			scanf("%s",d[i]);		
		r = 0;
		for (x = 0; x < 1<<(n*m); x++) {
			memset(deg,0,sizeof(deg));
			for (i = 0; i < n; i++) {
				for (j = 0; j < m; j++) {
					if (x&(1<<(i*m+j))) {
						if (d[i][j] == '-') {
							ii = i; jj = j-1;
							if (jj < 0) jj += m;
						}
						else if (d[i][j] == '|') {
							ii = i-1; jj = j;
							if (ii < 0) ii += n;
						}
						else if (d[i][j] == '/') {
							ii = i-1; jj = j+1;
							if (ii < 0) ii += n;
							if (jj >= m) jj -= m;
						}
						else {
							ii = i-1; jj = j-1;
							if (ii < 0) ii += n;
							if (jj < 0) jj += m;
						}
					}
					else {
						if (d[i][j] == '-') {
							ii = i; jj = j+1;
							if (jj >= m) jj -= m;
						}
						else if (d[i][j] == '|') {
							ii = i+1; jj = j;
							if (ii >= n) ii -= n;
						}
						else if (d[i][j] == '/') {
							ii = i+1; jj = j-1;
							if (ii >= n) ii -= n;
							if (jj < 0) jj += m;
						}
						else {
							ii = i+1; jj = j+1;
							if (ii >= n) ii -= n;
							if (jj >= m) jj -= m;
						}
					}
					deg[ii][jj]++;
				}
			}
			for (i = 0; i < n; i++) {
				for (j = 0; j < m; j++) {
					if (deg[i][j] != 1) break;
				}
				if (j < m) break;
			}
			if (i >= n) {
				r++;
				if (r >= MOD) r -= MOD;
			}
		}
		printf("%d\n",r);
	}
	return 0;
}