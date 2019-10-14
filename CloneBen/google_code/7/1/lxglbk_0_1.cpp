#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
const int N = 1005;

int mat[N][N],dp[N][N],n;
static int dir[4][2]={1,0,0,1,-1,0,0,-1};
int Dfs(int x,int y)
{
	if(dp[x][y]!=-1) return dp[x][y];
	dp[x][y]=1;
	for(int k=0;k<4;k++)
	{
		int nx=x+dir[k][0];
		int ny=y+dir[k][1];
		if(nx<1 || nx>n || ny<1 || ny>n) continue;
		if(mat[nx][ny]==mat[x][y]+1)
		{
			int v=Dfs(nx,ny);
			if(dp[x][y]<v+1) dp[x][y]=v+1;
		}
	}
	return dp[x][y];
}
int main()
{
	int T,CAS=0;

	for(scanf("%d",&T);CAS<T;CAS++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&mat[i][j]);
				dp[i][j]=-1;
			}
		}
		int ans=0,index=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int v=Dfs(i,j);
				if(ans<v || ans==v && index>mat[i][j])
				{
					ans=v;
					index=mat[i][j];
				}
			}
		}
		printf("Case #%d: %d %d\n",CAS+1,index,ans);
	}
	return 0;
}

