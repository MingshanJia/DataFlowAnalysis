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
#define N 10010

int dp[N];

int main()
{
	// freopen("D1.in","r",stdin);
	// freopen("D1.out","w",stdout);
	int t,i,j;
	dp[0]=0;
	for(i=1;i<N;i++)
	{
		dp[i]=i;
		for(j=1;j*j<=i;j++)
			dp[i]=min(dp[i],dp[i-j*j]+1);
	}
	sd(t);
	for(int tt=1;tt<=t;tt++)
	{
		int n;
		sd(n);
		printf("Case #%d: %d\n",tt,dp[n]);
	}
}