
#include <stdio.h>
#include <string.h>

char str[100][200];
int main(){

	int tt,tcas, N,i,j;
	freopen("C-small-1-attempt0.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&tt);
	for (tcas = 1;tcas<=tt;tcas++)
	{
		scanf("%d",&N);
		gets(str[0]);
		for (i=0;i<N;i++)
			gets(str[i]);
		int ans = 0;
		for (i=0;i<N;i++){
			for (j=0;j<i;j++)
				if (strcmp(str[i],str[j])<0)
					break;
			if (j<i) ans++;
		}
		printf("Case #%d: %d\n",tcas,ans);
	}
}

