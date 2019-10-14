#include<stdio.h>

int num[10002],pos[10002];

void SET(int K)
{
	int now,cnt,cur,i;

	for(i=1;i<=K;i++) num[i]=-1;
	now=1;
	cnt=0;
	cur=K;
	for(i=1;i<=K;i++)
	{
		while(1)
		{
			cur++;
			if(cur>K) cur=1;
			if(num[cur]==-1) cnt++;
			if(cnt==i) {num[cur]=i; pos[i]=cur; cnt=0; break;}
		}
	}
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-output.w","w",stdout);

	int Q,ks,n,a,K,i;

	scanf("%d",&Q);
	for(ks=1;ks<=Q;ks++)
	{
		scanf("%d",&K);
		SET(K);
//		printf("done\n");
		scanf("%d",&n);
		printf("Case #%d:",ks);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			printf(" %d",num[a]);
		}
		printf("\n");

	}


	return 0;
}