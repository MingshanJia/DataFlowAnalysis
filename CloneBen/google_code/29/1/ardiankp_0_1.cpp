#include <stdio.h>
#include <string.h>

typedef long long LL;
int tc, ntc;

char a[100], b[100], c[100];
int la, lb, lc;

char res[100];
int lres;

int main()
{
	scanf("%d",&ntc);
	LL v;
	int i;
	for (tc=1; tc<=ntc; tc++)
	{
		scanf("%s %s %s",a,b,c);
		la = strlen(a);
		lb = strlen(b);
		lc = strlen(c);		
		v = 0;
		for (i=0; i<la; i++)
			v = v*lb + strchr(b,a[i])-b;
			
		//printf("v = %lld, lc = %d\n",v,lc);
		lres = 0;
		while (v)
		{
			res[lres++] = v%lc;
			v /= lc;
		}
		
		printf("Case #%d: ",tc);
		for (i=lres-1; i>=0; i--) printf("%c",c[res[i]]);
		printf("\n");
	}
}