#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int begin[1000005];
int end[1000005];
int T,A1,A2,B1,B2;

void init()
{
	memset(begin,0,sizeof(begin));
	begin[1]=1;
	end[1]=1;
	end[2]=3;
	begin[2]=2;
	begin[3]=2;
	for(int i=3;i<=1000000;i++)
	{
		end[i]=begin[i]+i-1;
		end[i]=min(end[i],1000000);
		for(int j=end[i];!begin[j];j--)
			begin[j]=i;
	}
	return;
}

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	scanf("%d",&T);
	init();
	for(int test=1;test<=T;test++)
	{
		scanf("%d%d%d%d",&A1,&A2,&B1,&B2);
		long long ans=(long long)(B2-B1+1)*(long long)(A2-A1+1);
		for(int i=A1;i<=A2;i++)
		{
			if(begin[i]>B2||end[i]<B1)
				continue;
			ans-=(min(B2,end[i])-max(B1,begin[i])+1);
		}
		printf("Case #%d: %I64d\n",test,ans);
	}
	return 0;
}

