#include<stdio.h>

const int a[31]={1,5,27,143,751,935,607,903,991,335,47,
		943,471,55,447,463,991,95,607,263,151,
		855,527,743,351,135,407,903,791,135,647};

int h,i,n,t;

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&t);
	for(h=0;h<t;h++)
	{
		scanf("%d",&n);
		printf("Case #%d: %03d\n",h+1,a[n]);
	}
	return 0;
}
