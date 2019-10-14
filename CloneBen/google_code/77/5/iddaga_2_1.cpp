#include <stdio.h>
#include <memory.h>
#define MN 128
#define MOD 1000003
int n, m, r;
char d[MN][MN];
int put[MN][MN], get[MN][MN];
bool check(char c, int ii, int jj)
{
	if (c == '-') {
		return (ii == 0) && (jj == -1 || jj == 1);
	}
	else if (c == '|') {
		return (ii == -1 || ii == 1) && (jj == 0);
	}
	else if (c == '/') {
		return (ii == -1 && jj == 1) || (ii == 1 && jj == -1);
	}
	else {
		return (ii == -1 && jj == -1) || (ii == 1 && jj == 1);
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t, T, i, j, k, ii, jj, x, y;

	scanf("%d",&T);
	for (t = 1; t <= T; t++) {
		printf("Case #%d: ",t);
		scanf("%d%d",&n,&m);
		for (i = 0; i < n; i++)
			scanf("%s",d[i]);
		memset(put,0,sizeof(put));
		memset(get,0,sizeof(get));
		r = 1;
		for (;;) {
			for (i = 0; i < n; i++) {
				for (j = 0; j < m; j++) {
					if (!get[i][j]) {
						k = 0;
						for (ii = -1; ii <= 1; ii++) {
							for (jj = -1; jj <= 1; jj++) {
								x = i+ii;
								if (x < 0) x += n;
								if (x >= n) x -= n;
								y = j+jj;
								if (y < 0) y += m;
								if (y >= m) y -= m;
								if (!put[x][y] && check(d[x][y],ii,jj)) {
									k++;
								}
							}
						}
						if (k == 0) {
							break;
						}
						if (k == 1) {
							for (ii = -1; ii <= 1; ii++) {
								for (jj = -1; jj <= 1; jj++) {
									x = i+ii;
									if (x < 0) x += n;
									if (x >= n) x -= n;
									y = j+jj;
									if (y < 0) y += m;
									if (y >= m) y -= m;
									if (!put[x][y] && check(d[x][y],ii,jj)) {
										get[i][j] = 1;
										put[x][y] = 1;
									}
								}
							}
							break;
						}
					}
				}
				if (j < m) break;
			}
			if (i < n) {
				if (k == 0) {
					r = 0;
					break;
				}
			}
			else {
				for (i = 0; i < n; i++) {
					for (j = 0; j < m; j++) {
						if (!get[i][j]) break;
					}
					if (j < m) break;
				}
				if (i >= n) break;
				r *= 2;
				if (r >= MOD) r -= MOD;
				for (i = 0; i < n; i++) {
					for (j = 0; j < m; j++) {
						if (!get[i][j]) {
							for (ii = -1; ii <= 1; ii++) {
								for (jj = -1; jj <= 1; jj++) {
									x = i+ii;
									if (x < 0) x += n;
									if (x >= n) x -= n;
									y = j+jj;
									if (y < 0) y += m;
									if (y >= m) y -= m;
									if (!put[x][y] && check(d[x][y],ii,jj)) {
										put[x][y] = 1;
										get[i][j] = 1;
										break;
									}
								}
								if (jj <= 1) break;
							}
							break;
						}
					}
					if (j < m) break;
				}
			}
/*			if (i < n) {
				if (k == 0) {
					r = 0;
					break;
				}
			}
			else {
				for (i = 0; i < n; i++) {
					for (j = 0; j < m; j++) {
						if (!put[i][j]) {
							k = 0;
							if (d[i][j] == '-') {
								x = i; y = j-1;
								if (y < 0) y += m;
								if (!get[x][y]) k++;
								x = i; y = j+1;
								if (y >= m) y -= m;
								if (!get[x][y]) k++;
							}
							else if (d[i][j] == '|') {
								x = i-1; y = j;
								if (x < 0) x += n;
								if (!get[x][y]) k++;
								x = i+1; y = j;
								if (x >= n) x -= n;
								if (!get[x][y]) k++;
							}
							else if (d[i][j] == '/') {
								x = i-1; y = j+1;
								if (x < 0) x += n;
								if (y >= m) y -= m;
								if (!get[x][y]) k++;
								x = i+1; y = j-1;
								if (x >= n) x -= n;
								if (y < 0) y += m;
								if (!get[x][y]) k++;
							}
							else {
								x = i-1; y = j-1;
								if (x < 0) x += n;
								if (y < 0) y += m;
								if (!get[x][y]) k++;
								x = i+1; y = j+1;
								if (x >= n) x -= n;
								if (y >= m) y -= m;
								if (!get[x][y]) k++;
							}
							if (k == 0) break;
							if (k == 1) {
								put[i][j] = 1;
								if (d[i][j] == '-') {
									x = i; y = j-1;
									if (y < 0) y += m;
									if (!get[x][y]) get[x][y] = 1;
									x = i; y = j+1;
									if (y >= m) y -= m;
									if (!get[x][y]) get[x][y] = 1;
								}
								else if (d[i][j] == '|') {
									x = i-1; y = j;
									if (x < 0) x += n;
									if (!get[x][y]) get[x][y] = 1;
									x = i+1; y = j;
									if (x >= n) x -= n;
									if (!get[x][y]) get[x][y] = 1;
								}
								else if (d[i][j] == '/') {
									x = i-1; y = j+1;
									if (x < 0) x += n;
									if (y >= m) y -= m;
									if (!get[x][y]) get[x][y] = 1;
									x = i+1; y = j-1;
									if (x >= n) x -= n;
									if (y < 0) y += m;
									if (!get[x][y]) get[x][y] = 1;
								}
								else {
									x = i-1; y = j-1;
									if (x < 0) x += n;
									if (y < 0) y += m;
									if (!get[x][y]) get[x][y] = 1;
									x = i+1; y = j+1;
									if (x >= n) x -= n;
									if (y >= m) y -= m;
									if (!get[x][y]) get[x][y] = 1;
								}
								break;
							}
						}
					}
					if (j < m) break;
				}
				if (i < n) {
					if (k == 0) {
						r = 0;
						break;
					}
				}
				else {
					for (i = 0; i < n; i++) {
					}
				}
			}*/
		}
		printf("%d\n",r);
	}
	return 0;
}