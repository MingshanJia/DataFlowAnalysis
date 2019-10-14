#pragma warning(disable:4996)

#include<stdio.h>

int T, l0;

int a[111][111], b[111][111];
int me[111];
int you[111];
int n = 3;
int m;

int main(void)
{
	int l1, l2, l3, l4;

	//freopen("input.txt","r",stdin);

	freopen("a1.in","r",stdin);
	freopen("a1.out","w",stdout);

	scanf("%d",&T);
	for(l0=1;l0<=T;l0++)
	{
		//fprintf(stderr,"%d %d\n",l0,T);
		scanf("%d",&m);
		for(l1=0;l1<n;l1++) scanf("%d",&me[l1]);
		for(l1=0;l1<n;l1++) scanf("%d",&you[l1]);

		for(l1=0;l1<n;l1++)
		{
			for(l2=0;l2<n;l2++)
			{
				scanf("%d",&a[l1][l2]);
				b[l1][l2] = 0;
			}
		}
		int ret = 0x80000000;


		for(l1=0;l1<=me[0] && l1 <= you[0];l1++)
		{
			for(l2=0;l1+l2<=me[0] && l2 <= you[1];l2++)
			{
				for(l3=0;l1+l3<=you[0]&&l3<=me[1];l3++)
				{
					for(l4=0;l2+l4<=you[1]&&l3+l4<=me[1];l4++)
					{
						b[0][0] = l1;
						b[0][1] = l2;
						b[0][2] = me[0] - l1 - l2;

						b[1][0] = l3;
						b[1][1] = l4;
						b[1][2] = me[1] - l3 - l4;

						b[2][0] = you[0] - b[0][0] - b[1][0];
						b[2][1] = you[1] - b[0][1] - b[1][1];
						b[2][2] = you[2] - b[0][2] - b[1][2];

						if(b[0][0] < 0) continue;
						if(b[0][1] < 0) continue;
						if(b[0][2] < 0) continue;

						if(b[1][0] < 0) continue;
						if(b[1][1] < 0) continue;
						if(b[1][2] < 0) continue;

						if(b[2][0] < 0)continue;
						if(b[2][1] < 0) continue;
						if(b[2][2] < 0) continue;


						if(b[2][0] + b[2][1] + b[2][2] != me[2])
						{
continue;
						}

						int calc = 0;

						calc += a[0][0] * b[0][0];
						calc += a[0][1] * b[0][1];
						calc += a[0][2] * b[0][2];
						calc += a[1][0] * b[1][0];
						calc += a[1][1] * b[1][1];
						calc += a[1][2] * b[1][2];
						calc += a[2][0] * b[2][0];
						calc += a[2][1] * b[2][1];
						calc += a[2][2] * b[2][2];

						if(calc > ret) ret = calc;
					}
				}
			}
		}
		

		printf("Case #%d: %d\n",l0,ret);
	}

	return 0;
}