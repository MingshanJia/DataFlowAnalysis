#include <stdio.h>
int n,c,C,i,m;
long long int A[500005],X,Y,Z;
int B[500005];
int D[500005];
int main() {
	scanf("%d",&C);
	for(c=1;c<=C;c++) {
		int j;
		long long res1 = 0;
		scanf("%d%d%lld%lld%lld",&n,&m,&X,&Y,&Z);
		for(i=0;i<m;i++) scanf("%d",A+i);
		for(i=0;i<n;i++) {
			B[i] = A[i%m];
//			printf("%d ",B[i]);
			A[i%m] = (X * A[i%m] + Y * (i + 1)) % Z;
		}
		for(i=0;i<n;i++) {
			long long res = 1;
			for(j=0;j<i;j++) {
				if(B[i]>B[j]) res += D[j], res %= 1000000007;
			}
			D[i] = res;
			res1 += res;
			res1 %= 1000000007;
		}
		printf("Case #%d: %lld\n",c,res1);
	}
	return 0;
}
