#include <stdio.h>

bool row[36][36];
bool coloumn[36][36];
bool block[36][36];

void init(int n)
{
	for(int i=0;i<n*n;i++)
	{
		for (int j=0;j<n*n;j++)
		{
			row[i][j]=false;
			coloumn[i][j]=false;
			block[i][j]=false;
		}
	}
}

bool judge(int n)
{
	init(n);
	int v;
	bool ret=true;
	for (int i=0;i<n*n;i++)
	{
		for (int j=0;j<n*n;j++)
		{
			scanf("%d",&v);
			if(!ret)
				continue;
			if(v<=0||v>n*n)
			{
				ret=false;
				continue;
			}
			if(row[i][v-1])
			{
				ret=false;
				continue;;
			}
			row[i][v-1]=true;
			if(coloumn[j][v-1])
			{
				ret=false;
				continue;
			}
			coloumn[j][v-1]=true;
			int blockId=(i/n)*n+(j/n);
			if(block[blockId][v-1])
			{
				ret=false;
				continue;
			}
			block[blockId][v-1]=true;
		}
	}

	return ret;
}

int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	{
		int n;
		scanf("%d",&n);
		bool res=judge(n);
		if(res)
			printf("Case #%d: Yes\n",i);
		else
			printf("Case #%d: No\n",i);
	}

	return 0;
}