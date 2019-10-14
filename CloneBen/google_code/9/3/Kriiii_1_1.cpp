#include <stdio.h>

int B,L,N;
double u[404][404],v[404][404];

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);

		scanf ("%d %d %d",&B,&L,&N);

		u[0][0] = B * 750;
		for (int l=2;l<=L;l++){
			for (int i=0;i<l;i++) for (int j=0;j<l-i;j++) v[i][j] = 0;
			for (int i=0;i<l-1;i++) for (int j=0;j<l-1-i;j++){
				double p = u[i][j] - 250;
				if (p >= 0){
					p /= 3;
					v[i][j] += p;
					v[i+1][j] += p;
					v[i][j+1] += p;
				}
			}
			for (int i=0;i<l;i++) for (int j=0;j<l-i;j++) u[i][j] = v[i][j];
		}

		for (int k=0;k<L;k++) for (int i=k,j=0;j<=k;i--,j++){
			N--;
			if (N == 0){
				if (u[i][j] >= 250)
					u[i][j] = 250;
				printf ("%.12lf\n",u[i][j]);
			}
		}
	}

	return 0;
}