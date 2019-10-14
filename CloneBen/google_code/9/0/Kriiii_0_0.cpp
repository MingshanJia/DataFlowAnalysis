#include <stdio.h>

const long long mod = 1000000007;
long long C[101][101],V[101][101];
int N,M;

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	for (int i=0;i<=100;i++){
		C[i][0] = C[i][i] = 1;
		for (int j=1;j<i;j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
	}

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);

		scanf ("%d %d",&M,&N);
		V[0][0] = 1;
		for (int i=1;i<=M;i++){
			for (int j=0;j<=N;j++) V[i][j] = 0;
			for (int j=1;j<=N;j++) for (int k=0;j+k<=N;k++){
				V[i][j+k] = (V[i][j+k] + C[N-k][j] * V[i-1][k]) % mod;
			}
		}

		printf ("%lld\n",V[M][N]);
	}

	return 0;
}