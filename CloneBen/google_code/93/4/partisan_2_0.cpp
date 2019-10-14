#include <cstdio>

#define P 10005
#define Q 105
#define inf 1000000000

int t,test;
int p,n,i,x,y,ans;
int a[Q];
bool used[Q];

void dfs(int d,int sum)
{
	if(d==n)
	{
		if(sum<ans)
			ans=sum;
	}else
	{
		int i,j;
		int cnt;
		for(i=0;i<n;i++)
			if(!used[i])
			{
				cnt=0;
				j=i-1;
				while(j>=0 && used[j]) j--;
				if(j==-1)
					cnt+=a[i]-1;else
					cnt+=a[i]-a[j]-1;
				j=i+1;
				while(j<n && used[j]) j++;
				if(j==n)
					cnt+=p-a[i];else
					cnt+=a[j]-a[i]-1;
				used[i]=1;
				dfs(d+1,sum+cnt);
				used[i]=0;
			}
	}
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&test);
	for(t=1;t<=test;t++)
	{
		scanf("%d%d",&p,&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		ans=inf;
		dfs(0,0);
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}

