#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define INF 99999999999LL

int n, p, m;
long long bit[40007][2], bin;
long long res;
int friends[40007];
int fri_info[107][2];

int line[1000007][3], lc;
int se[40007][2];
long long dist[107][40007];
int visit[40007];


int comp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

void renew(int now)
{
	while(now)
	{
		bit[now][0] = bit[now*2][0]; bit[now][1] = bit[now*2][1];
		if(bit[now*2+1][0] < bit[now][0])
		{
			bit[now][0] = bit[now*2+1][0]; bit[now][1] = bit[now*2+1][1];
		}
		now /= 2;
	}
}

void dijkstra(int fp)
{
	int st = fri_info[fp][0], i, j, now, mindist, pos;
	for(i = bin; i < bin*2; i++)
	{
		bit[i][0] = INF;
		bit[i][1] = i-bin+1;
	}
	
	for(i = se[st][0]; i <= se[st][1]; i++)
		bit[bin+line[i][1]-1][0] = line[i][2];

	for(i = bin-1; i >= 1; i--)
	{
		bit[i][0] = bit[i*2][0]; bit[i][1] = bit[i*2][1];
		if(bit[i*2+1][0] < bit[i][0])
		{
			bit[i][0] = bit[i*2+1][0]; bit[i][1] = bit[i*2+1][1];		
		}
	}

	for(i = 1; i <= n; i++){ dist[fp][i] = INF; visit[i] = 0;}
	now = st;
	visit[now] = 1;
	dist[fp][now] = 0;

	for(i = 0; i < n-1; i++)
	{
		if(bit[1][0] == INF) break;
		mindist = dist[fp][bit[1][1]] = bit[1][0];
		pos = bit[1][1];
		visit[pos] = 1;
		bit[bin+pos-1][0] = INF;
		renew((bin+pos-1)/2);
		for(j = se[pos][0]; j <= se[pos][1]; j++)
		{
			if(visit[line[j][1]] == 0 && mindist + line[j][2] < bit[bin+line[j][1]-1][0])
			{
				bit[bin+line[j][1]-1][0] = mindist + line[j][2];
				renew((bin+line[j][1]-1)/2);
			}
		}
	}
}

int main(void)
{
	int t, tl=0, i, j, k, lcn, a, b, c;
	long long sum;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	while(t--)
	{
//		memset(bit, 0, sizeof(bit)); memset(friends, 0, sizeof(friends)); memset(fri_info, 0, sizeof(fri_info));
	//	memset(line ,0, sizeof(line)); memset(se, 0, sizeof(se)); memset(dist, 0, sizeof(dist)); memset(visit, 0, sizeof(visit)); //bit, friends, fri_info, line, se, dist, visit
		scanf("%d %d %d", &n, &p, &m);
		for(bin = 1; bin < n; bin *= 2);

		for(i = 1; i <= n; i++) friends[i] = se[i][0] = se[i][1] = 0;
		for(i = 1; i <= p; i++)
		{
			scanf("%d %d", &fri_info[i][0], &fri_info[i][1]);
			friends[fri_info[i][0]] += fri_info[i][1];
		}

		lc = 0;
		for(i = 1; i <= m; i++)
		{
			scanf("%d %d", &c, &lcn);
			scanf("%d", &a);
			for(j = 0; j < lcn-1; j++)
			{
				scanf("%d", &b);
				line[++lc][0] = a;
				line[lc][1] = b;
				line[lc][2] = c;

				line[++lc][0] = b;
				line[lc][1] = a;
				line[lc][2] = c;

				a = b;
			}
		}
		qsort(line+1, lc, sizeof(line[0]), comp);
		
		for(i = 1; i <= lc; i++)
		{
			if(se[line[i][0]][0] == 0) se[line[i][0]][0] = i;
			se[line[i][0]][1] = i;
		}

		for(i = 1; i <= p; i++)
			dijkstra(i);
		
		res = INF;
		for(j = 1; j <= n; j++)
		{
			sum = 0;
			for(k = 1; k <= p; k++)
			{
				if(dist[k][j] * fri_info[k][1] > sum)
					sum = dist[k][j] * fri_info[k][1];

				if(sum >= INF) break;				
			}
			if(sum < res) res = sum;			
		}

		if(res == INF) res = -1;
		printf("Case #%d: %lld\n", ++tl, res);
	}
	return 0;
}
/*
1
3 2 1
1 1
3 100
1 3 1 2 3
*/
/*
#include <stdio.h>

#define INF 99999999999
long long dist[117][117];
int n, p, m;
int fri_info[107][2];

int main(void)
{
	int t, tl = 0;
	int i, j, k, c, a, b, lcn;
	long long res, sum;

	freopen("input.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &n, &p, &m);
		
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
				dist[i][j] = INF;
		}
		for(i = 1; i <= n; i++)
			dist[i][i] = 0; 

		for(i = 1; i <= p; i++)
			scanf("%d %d", &fri_info[i][0], &fri_info[i][1]);

		for(i = 0; i < m; i++)
		{
			scanf("%d %d %d", &c, &lcn, &a);
			for(j = 0; j < lcn-1; j++)
			{
				scanf("%d", &b);
				dist[a][b] = dist[b][a] = c;
				a = b;
			}
		}

		
		for(k = 1; k <= n; k++)
		{
			for(i = 1; i <= n; i++)
			{
				for(j = 1; j <= n; j++)
				{
					if(dist[i][k] + dist[k][j] < dist[i][j])
						dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}

		res = INF;
		for(i = 1; i <= n; i++)
		{
			sum = 0;
			for(j = 1; j <= p; j++)
			{
				if(dist[fri_info[j][0]][i] * fri_info[j][1] > sum)
					sum = dist[fri_info[j][0]][i] * fri_info[j][1];
			}
			if(sum < res) res = sum;
		}
		if(res == INF) res = -1;
		printf("Case #%d: %lld\n", ++tl, res);
	}
}

*/