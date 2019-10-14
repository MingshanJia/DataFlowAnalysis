#include<bits/stdc++.h>
#include <unistd.h>
using namespace std;

#define sd(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
#define sl(a) scanf("%lld",&a)
#define clr(a) memset(a,0,sizeof(a))
#define debug(a) printf("check%d\n",a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
#define N 310
#define INF 100000
int dp[N][N][N], valid[N][N][N], minn[N];
char s[N];
int main()
{
	// freopen("A.in","r",stdin);
	// freopen("A.out","w",stdout);
	int t,i,j,k;
	sd(t);
	for(int tt=1;tt<=t;tt++)
	{
		// cerr<<"test: "<<tt<<'\n';
		scanf("%s",(s+1));
		//cout<<"check: "<<(s+1)<<'\n';
		int n=strlen(s+1);
		
		clr(valid);
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				valid[i][i][j]=(s[i]==s[j]);
		for(int len=2;len<=n;len++)
			for(i=1;i+len-1<=n;i++)
				for(j=i+len;j+len-1<=n;j++)
					valid[i][i+len-1][j]=(valid[i][i+len-2][j]&(s[i+len-1]==s[j+len-1]));
		
		for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
		for(k=0;k<=n;k++)
			dp[i][j][k]=INF;
		dp[0][1][0]=0;

		for(i=0;i<=n;i++)
			minn[i]=INF;
		minn[0]=1;

		for(i=1;i<=n;i++)
		{
			dp[i][1][0]=dp[i-1][1][0]+1;
			minn[i]=dp[i][1][0];
			for(j=1;j<i;j++)
				for(k=j;k+(k-j+1)<=i;k++)
				{
					dp[i][j][k]=dp[i-1][j][k]+1;
					if(valid[j][k][i-(k-j)])
					{
						dp[i][j][k]=min(dp[i][j][k],dp[i-(k-j+1)][j][k]+1);
						dp[i][j][k]=min(dp[i][j][k],minn[i-(k-j+1)]+2);
					}
					minn[i]=min(minn[i],dp[i][j][k]);
				}
		}
		printf("Case #%d: %d\n",tt,minn[n]);
	}
}