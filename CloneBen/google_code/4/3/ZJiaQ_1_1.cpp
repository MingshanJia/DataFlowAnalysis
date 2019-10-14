#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int solve(int r,int c)
{
	int d[3],th=0;
	int ret=0;
	d[0]=(c/3)*2+c%3;
	if(c>=2)
	{
		d[1]=1+((c-2)/3)*2+(c-2)%3;
	}
	else d[1]=1;
	d[2]=((c-1)/3)*2+(c-1)%3;
	for(int i=1;i<=r;i++)
	{
		ret+=d[th];
		th++;
		th%=3;
	}
	return ret;
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int r,c;
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&r,&c);
		if(r<c)swap(r,c);
		int ans=0;
		if(c==2)
		{
			ans=r/3*4+r%3*2;
			printf("Case #%d: %d\n",++cas,ans);
			continue;
		}
		ans=max(solve(r,c),solve(c,r));
		printf("Case #%d: %d\n",++cas,ans);
	}
}