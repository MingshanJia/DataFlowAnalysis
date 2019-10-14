#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int mod = 10007;
int a[1000][1000];

int n, m, k, x[20], y[20], tot;

int dp(int x,int y) {
	int &ret = a[x][y];
	if (ret >= 0) return ret;
	if (x >= n || y >= m) return 0;
	return ret = (dp(x+2,y+1)+dp(x+1,y+2)) % mod;
}

int main() {
	freopen("D-small-attempt1.in","r",stdin);
	freopen("D_3.out","w",stdout);
	int testcases;
	scanf("%d", &testcases);
	int z, i, j;
	for (z = 0; z < testcases; z++) {
		printf("Case #%d: ", z+1);
		scanf("%d%d%d",&n,&m,&k);
		memset(a,0xff,sizeof(a));
		for (i = 0; i < k; i++) {
			scanf("%d%d",&x[i],&y[i]);
			x[i]--;
			y[i]--;
			a[x[i]][y[i]] = 0;
		}
		a[n-1][m-1] = 1;
		printf("%d\n",dp(0,0));
	}
	return 0;
}
