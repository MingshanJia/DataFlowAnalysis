#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;


int n, k;
int px[15], py[15];
int val[1<<15];

#define INF 1000000

void init()
{
	int i, j;
	
	int a, b, c, d;
	for (i=1; i<(1<<n); i++)
	{
		a = b = INF;
		c = d = -INF;
		for (j=0; j<n; j++) if (i & (1<<j))
		{
			a <?= px[j]; b <?= py[j];
			c >?= px[j]; d >?= py[j];
		}		
		val[i] = max(c-a,d-b);
	}
}

int dp[15][1<<15];
int doit(int lv, int mask)
{
	if (lv == k-1) return val[mask];
	int& res = dp[lv][mask];
	if (res != -1) return res;
	
	res = val[mask];	
	int i;
	for (i=mask; i>0; i=(i-1)&mask)
	{
		res <?= val[i] >? doit(lv+1, mask^i);
	}
	return res;
}

int tc, ntc;
int main()
{
	scanf("%d",&ntc);
	int i;
	int res;
	for (tc=1; tc<=ntc; tc++)
	{
		scanf("%d %d",&n,&k);
		for (i=0; i<n; i++) scanf("%d %d",&px[i],&py[i]);
		
		init();
		memset(dp, -1, sizeof(dp));
		
		
		res = doit( 0, (1<<n)-1 );
		printf("Case #%d: %d\n",tc,res);
	}
}