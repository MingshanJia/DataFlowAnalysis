#include <stdio.h>
#include <string.h>

int tc, ntc;
int n, k;

bool can[10][10];

#define MOD 19802

bool used[10];
int dfs(int lv, int last)
{
	if (lv == n)
	{
		if (can[last][0]) 
			return 1;
		return 0;
	}
	
	int i;
	int res = 0;
	for (i=0; i<n; i++) if (!used[i] && can[last][i])
	{
		used[i] = true;
		res += dfs(lv+1, i);
		res %= MOD;
		used[i] = false;
	}
	return res;
}

int main()
{
	scanf("%d",&ntc);
	int i;
	int a, b;
	int res;
	for (tc=1; tc<=ntc; tc++)
	{
		scanf("%d %d",&n,&k);
		
		memset(can,1,sizeof(can));
		for (i=0; i<k; i++)
		{
			scanf("%d %d",&a,&b);
			a--; b--;
			can[a][b] = can[b][a] = 0;
		}
		
		memset(used,0,sizeof(used));
		used[0] = true;
		res = dfs( 1, 0 );
		res /= 2;
		
		printf("Case #%d: %d\n",tc, res);
	}
}