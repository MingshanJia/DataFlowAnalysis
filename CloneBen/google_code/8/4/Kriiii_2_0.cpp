#include <stdio.h>

int B[10],C[1000001];

int main()
{
	freopen ("1.in","r",stdin);
	freopen ("1.out","w",stdout);

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);

		for (int i=0;i<10;i++) scanf ("%d",&B[i]);
		int X; scanf ("%d",&X);
		for (int i=1;i<=X;i++){
			bool good = 1; int cnt = 0, t = i;
			while (t){
				if (!B[t%10]) good = 0;
				cnt++; t /= 10;
			}
			if (good) C[i] = cnt;
			else C[i] = 10000;

			for (int x=2;x*x<=i;x++) if (i % x == 0){
				int u = C[x] + C[i/x] + 1;
				if (C[i] > u)
					C[i] = u;
			}
		}

		if (C[X] == 10000) puts("Impossible");
		else printf ("%d\n",C[X]+1);
	}

	return 0;
}