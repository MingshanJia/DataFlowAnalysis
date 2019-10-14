#include <stdio.h>
#include <time.h>
double dp[2222][2222];
void INIT()
{
	
	/*for(int i=2;i<=2000;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(j+1<i)
			{
				dp[i][j]+=dp[i-1][j];
			}
			if(j>0)
			{
				dp[i][j]+=dp[i][j-1];
			}
		}
	}*/
}
double solve(int n,int m)
{
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{dp[i][j]=0;
			if(i)dp[i][j]+=dp[i-1][j]*(n-i+1)/(n+m-i-j+1);
			if(j)dp[i][j]+=dp[i][j-1]*(m-j+1)/(n+m-i-j+1);
		}
	}
	return dp[n][m];
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T,cas=0;
	scanf("%d",&T);
//	T=100;
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		double ans=solve(n,m);
		printf("Case #%d: %.8f\n",++cas,ans);
	}

}