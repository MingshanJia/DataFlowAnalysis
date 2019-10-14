#include <stdio.h>

int tc, ntc;
int main()
{
	scanf("%d",&ntc);
	int a, b;
	for (tc=1; tc<=ntc; tc++)
	{
		scanf("%d %d",&a,&b);
		printf("Case #%d: ",tc);
		
		if (b%2 == 1) printf("BLACK\n");
		else printf("WHITE\n");
	}
}