#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
#include<map>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 300010
#define LL long long
#define RUN
using namespace std;

int n, m, p;
int mp[110][110];
double mat[110][110];
double temp[110][110];
double ans[110][110];

int main(){
#ifdef RUN
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
#endif
	int t;
	int a, b, c;
	scanf("%d", &t);
	for (int ii = 1; ii <= t; ii++){
		scanf("%d%d%d", &n, &m, &p);
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				mp[i][j] = 100000000;
			}
			mp[i][i] = 0;
		}
		for (int i = 1; i <= m; i++){
			scanf("%d%d%d", &a, &b, &c);
			mp[a][b] = mp[b][a] = c;
		}
		for (int k = 1; k <= n; k++){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
					mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
				}
			}
		}
		mem(mat, 0);
		mem(ans, 0);
		for (int i = 1; i <= n; i++){
			int sum = 0;
			for (int j = 1; j <= n; j++){
				if (i == j) continue;
				mat[i][j] = 1.0 / (n - 1);
				sum += mp[i][j];
			}
			mat[i][n + 1] = sum * 1.0 / (n - 1);
		}
		mat[n + 1][n + 1] = 1;
		for (int i = 1; i <= n + 1; i++){
			ans[i][i] = 1;
		}
		while (p){
			if (p & 1){
				mem(temp, 0);
				for (int i = 1; i <= n + 1; i++){
					for (int j = 1; j <= n + 1; j++){
						for (int k = 1; k <= n + 1; k++){
							temp[i][j] += ans[i][k] * mat[k][j];
						}
					}
				}
				for (int i = 1; i <= n + 1; i++){
					for (int j = 1; j <= n + 1; j++){
						ans[i][j] = temp[i][j];
					}
				}
			}
			p >>= 1;
			mem(temp, 0);
			for (int i = 1; i <= n + 1; i++){
				for (int j = 1; j <= n + 1; j++){
					for (int k = 1; k <= n + 1; k++){
						temp[i][j] += mat[i][k] * mat[k][j];
					}
				}
			}
			for (int i = 1; i <= n + 1; i++){
				for (int j = 1; j <= n + 1; j++){
					mat[i][j] = temp[i][j];
				}
			}
		}
		printf("Case #%d: %.10lf\n", ii, ans[1][n + 1]);
	}
	return 0;
}