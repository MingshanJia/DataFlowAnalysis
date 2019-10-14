#include <stdio.h>
#include <climits>
#include <algorithm>

long long 답 = 0;

long long flow[8][8];
long long cost[8][8];

bool findShortest()
{
	long long dp[8];
	int from[8];
	dp[0] = 0;
	from[0] = -1;
	for(int i = 1; i < 8; i++)
	{
		dp[i] = LLONG_MAX;
	}
	int upd = 0;
	for(int i = 0;i < 8; i ++)
	{
		upd = 0;
		for(int j = 0; j < 8; j ++) 
		{
			for(int k = 0; k < 8; k ++)
			{
				if(flow[j][k] <= 0) continue;
				if(dp[j] == LLONG_MAX) continue;
				if(dp[k] > dp[j] + cost[j][k])
				{
					dp[k] = dp[j] + cost[j][k];
					from[k] = j;
					upd = 1;
				}
			}
		}
		if(upd == 0) break;
	}
	if(upd) return false;
	if(dp[7] == LLONG_MAX) return false;

	int p = 7, lp;
	long long minflow = LLONG_MAX;
	while(p != 0)
	{
		lp = p;
		p = from[p];
		minflow = std::min(minflow, flow[p][lp]);
	}
	p = 7;
	while(p != 0)
	{
		lp = p;
		p = from[p];
		flow[p][lp] -= minflow;
		flow[lp][p] += minflow;
	}
	return true;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int 테스트케이스 = 1; 테스트케이스 <= T; 테스트케이스 ++)
	{
		답 = 0;
		memset(flow, 0, sizeof(flow));
		memset(cost, 0, sizeof(cost));
		long long n;
		scanf("%lld",&n);
		for(int i = 0;i < 3; i ++)
		{
			scanf("%lld",&flow[0][i+1]);
		}
		for(int i = 0;i < 3; i ++)
		{
			scanf("%lld",&flow[i+4][7]);
		}
		for(int i = 1;i <= 3; i ++)
		{
			for(int j = 4; j <= 6; j ++)
			{
				flow[i][j] = n;
				scanf("%lld",&cost[i][j]);
				cost[i][j] = -cost[i][j];
				cost[j][i] = -cost[i][j];
			}
		}
		while(findShortest());
		for(int i = 4;i <= 6;i ++)
		{
			for(int j = 1;j <= 3;j ++)
			{
				답 += cost[i][j] * flow[i][j];
			}
		}
		printf("Case #%d: %lld\n", 테스트케이스, 답);
	}
	return 0;
}