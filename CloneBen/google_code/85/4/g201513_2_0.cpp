#include<stdio.h>
#include<string.h>

const int maxn = 120;

bool p[maxn][maxn];
int X1[maxn],X2[maxn],Y1[maxn],Y2[maxn];
int n;

int main()
{
	int ntest;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	scanf("%d",&ntest);
	for(int test=1;test<=ntest;test++)
	{
		scanf("%d",&n);
		memset(p,0,sizeof(p));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&X1[i],&Y1[i],&X2[i],&Y2[i]);
			for(int x=X1[i];x<=X2[i];x++)
				for(int y=Y1[i];y<=Y2[i];y++)
					p[x][y] = true;
		}
		bool ok = true;
		int ans = 0;
		while(ok)
		{
			ok = false;
			for(int i=maxn-1;i>=1;i--)
				for(int j=maxn-1;j>=1;j--)
				{
					if(p[i-1][j] && p[i][j-1])
					{
						p[i][j] = true;
					}
					else if(!p[i-1][j] && !p[i][j-1])
					{
						p[i][j] = false;
					}
					ok |= p[i][j];
				}
/*			for(int i=0;i<10;i++)
			{
				for(int j=0;j<10;j++)
					printf("%d ",p[i][j]);
				puts("");
			}*/
			ans++;
		}
		printf("Case #%d: %d\n",test,ans);
	}
	return 0;
}
