#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 11001;
const int MAXM = 1000011;
const int MAXK = 101;
const int INF = 1000000005;
const double pi = acos(-1.0);

long long mol = (long long)(1e+9+7);

long long gcd(long long v1,long long v2,long long &a,long long&b)
{
	if(v2==0)
	{
		a=1;
		b=0;
		return v1;
	}
	else
	{
		long long d,temp;
		d=gcd(v2,v1%v2,a,b);
		temp=a;
		a=b;
		b=temp-v1/v2*b;
		return d;
	}
}

long long ni(long long val)
{
	long long a,b;
	gcd(val,mol,a,b);
	return (a%mol+mol)%mol;
}

long long C(long long a,long long b)
{
	long long ans=1;
	long long i,j;
	for(i=a,j=b;j>=1;j--,i--)
		ans=(ans*i%mol*ni(j))%mol;
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	long long T,cas;
	long long m,n,i,j,k;
	vector<vector<long long> > c(101,vector<long long >(101,0));
	for(i=0;i<=100;i++)
		for(j=0;j<=i;j++)
			c[i][j]=C(i,j);
	scanf("%lld",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%lld%lld",&m,&n);
		vector< vector<long long> > dp(m+1,vector<long long>(n+1,0LL));
		for(j=1;j<=n;j++)
			dp[1][j]=1LL;
		for(i=2;i<=m;i++)
		{
			for(j=2;j<=n;j++)
			{
				for(k=i-1;k<j;k++)
				if(dp[i-1][k]!=0)
				dp[i][j]=(dp[i][j]+dp[i-1][k]*c[j][j-k])%mol;
			}
		}
		printf("Case #%lld: %lld\n",cas,dp[m][n]);
	}
	return 0;
}