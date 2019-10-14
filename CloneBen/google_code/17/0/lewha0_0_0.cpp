#pragma warning(disable:4996)
#include<stdio.h>

#define Swap(aa,bb) {cc=aa;aa=bb;bb=cc;}

int cc;

int n, m, B, BB;
int a[1111], b[1111];
int T;
int ret;
int flag;
int value, idx1, idx2;

int main(void)
{
	int l0, l1, l2, l3;
	//freopen("input.txt","r",stdin);

	freopen("a1.in","r",stdin);
	freopen("a1.out","w",stdout);

	scanf("%d",&T);
	for(l0=1;l0<=T;l0++)
	{
		scanf("%d %d %d",&n,&m,&B);
		ret = 0;
		for(l1=0;l1<m;l1++) scanf("%d %d",&a[l1],&b[l1]);

		while(n > 0)
		{
			value = -1;
			for(l1=0;l1<m;l1++)
			{
				if(a[l1] >= B && b[l1] >= 1 && (value == -1 || value > a[l1]))
				{
					value = a[l1];
					idx1 = l1;
					idx2 = -1;
				}
				if(a[l1]+a[l1] >= B && b[l1] >= 2 && (value == -1 || value > a[l1]+a[l1]))
				{
					value = a[l1] + a[l1];
					idx1 = l1;
					idx2 = l1;
				}
				for(l2=l1+1;l2<m;l2++)
				{
					if(a[l1]+a[l2] >= B && b[l1] >= 1 && b[l2] >= 1 && (value == -1 || value > a[l1]+a[l2]))
					{
						value = a[l1] + a[l2];
						idx1 = l1;
						idx2 = l2;
					}
				}
			}
			if(value == -1)
			{
				ret = -1;
				break;
			}

			if(idx2 == -1)
			{
				int can = b[idx1];
				if(can > n) can = n;

				ret += a[idx1] * can;
				b[idx1] -= can;
				n -= can;

			}
			else if(idx1 == idx2)
			{
				int can = (b[idx1] >> 1);
				if(can > n) can = n;
				ret += ((a[idx1] * can) << 1);
				b[idx1] -= (can << 1);
				n -= can;
			}
			else
			{
				int can = b[idx1];
				if(can > b[idx2]) can = b[idx2];
				if(can > n) can = n;
				ret += (a[idx1]+a[idx2]) * can;
				b[idx1] -= can;
				b[idx2] -= can;
				n -= can;
			}
		}

		printf("Case #%d: %d\n",l0,ret);
	}
}