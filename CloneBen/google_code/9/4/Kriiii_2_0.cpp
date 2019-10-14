#include <stdio.h>

int N,K,A[111],D[111];
bool can[111][111];

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);

		scanf ("%d %d",&N,&K);
		for (int i=1;i<=N;i++) scanf ("%d",&A[i]);
		
		for (int i=0;i<=N+1;i++) for (int j=0;j<=N+1;j++) can[i][j] = 0;
		for (int i=1;i<=N+1;i++) can[i][i-1] = 1;
		for (int l=3;l<=N;l+=3){
			for (int i=1,j=l;j<=N;i++,j++){
				for (int a=i;a<=j;a++) if (can[i][a-1]){
					for (int b=a+1;b<=j;b++) if (can[a+1][b-1]){
						for (int c=b+1;c<=j;c++) if (can[b+1][c-1] && can[c+1][j]){
							if (A[c] - A[b] == K && A[b] - A[a] == K){
								can[i][j] = 1;
							}
						}
					}
				}
			}
		}

		for (int i=1;i<=N;i++){
			D[i] = i;
			for (int j=1;j<=i;j++){
				if (can[j][i]){
					if (D[i] > D[j-1])
						D[i] = D[j-1];
				}
				else{
					if (D[i] > D[j-1] + i - j + 1)
						D[i] = D[j-1] + i - j + 1;
				}
			}
		}

		printf ("%d\n",D[N]);
	}

	return 0;
}