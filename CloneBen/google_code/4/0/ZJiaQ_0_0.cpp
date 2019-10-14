#include <stdio.h>
double dp[2222][2222];
void INIT()
{
	dp[1][0]=1;
	for(int i=2;i<=2000;i++)
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
	}
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T,cas=0;
	scanf("%d",&T);
	INIT();
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		double ans=dp[n][m];
		for(int i=1;i<=n+m;i++)
		{
			ans/=i;
		}
		for(int i=1;i<=n;i++)ans*=i;
		for(int i=1;i<=m;i++)ans*=i;
		printf("Case #%d: %.8f\n",++cas,ans);
	}
}