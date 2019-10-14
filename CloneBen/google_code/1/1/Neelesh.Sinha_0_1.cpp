#include <bits/stdc++.h>
using namespace std;

long long int a[200001];

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-largeoutput","w",stdout);
	long long int t,n,x,ans,i,j,k;
	scanf("%lld",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%lld",&n);
		long long int b[n];
		for(j=0;j<=200000;j++)
		{
			a[j]=0;
		}
		for(j=0;j<n;j++)
		{
			scanf("%lld",&b[j]);
			a[b[j]]++;
		}
		ans=0;
		if(a[0]>=3)
		{
			ans+=(a[0]*(a[0]-1)*(a[0]-2))/6;
		}
		if(a[1]>=3)
		{
			ans+=(a[1]*(a[1]-1)*(a[1]-2))/6;
		}
		if(a[0]>=2)
		{
			ans+=((a[0]*(a[0]-1))/2)*(n-a[0]);
		}
		if(a[1]>=1)
		{
			for(j=2;j<=200000;j++)
			{
				ans+=a[1]*((a[j]*(a[j]-1))/2);
			}
		}
	for(j=0;j<n-1;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(b[j]<2 || b[k]<2)
					continue;
				else
				{
					if(b[j]*b[k]<=200000)
						ans+=a[b[j]*b[k]];
				}
			}
		}
		printf("Case #%lld: %lld\n",i,ans);
	}
	return 0;
}
