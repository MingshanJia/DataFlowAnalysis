#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long lld;

int T,TN,seq1[3],seq2[3];
lld N,A[3],B[3],L[3],W[3][3],ans;

void proc()
{
	int i,j;
	lld k,v=0;
	for (i=0;i<3;i++) L[i] = B[i];
	for (i=0;i<3;i++){
		k = A[seq1[i]];
		for (j=0;j<3;j++){
			if (k > L[seq2[j]]){
				v += L[seq2[j]]*W[seq1[i]][seq2[j]];
				k -= L[seq2[j]];
				L[seq2[j]] = 0;
			}else{
				v += k*W[seq1[i]][seq2[j]];
				L[seq2[j]] -= k;
				k = 0;
			}
		}
	}
	if (ans < v) ans = v;
}

int main()
{
	int i,j,k;
	freopen("input.txt","r",stdin), freopen("output.txt","w",stdout);
	for (scanf("%d",&T);T--;){
		scanf("%lld",&N);
		for (i=0;i<3;i++) scanf("%lld",A+i);
		for (i=0;i<3;i++) scanf("%lld",B+i);
		for (i=0;i<3;i++) for (j=0;j<3;j++) scanf("%lld",W[i]+j);
		for (i=0;i<3;i++) seq1[i] = seq2[i] = i;
		ans = -1e18;
		for (;;){
			for (;;){
				proc();
				next_permutation(seq2,seq2+3);
				for (i=0;i<3;i++) if (seq2[i] != i) break;
				if (i == 3) break;
			}
			next_permutation(seq1,seq1+3);
			for (i=0;i<3;i++) if (seq1[i] != i) break;
			if (i == 3) break;
		}
		printf("Case #%d: %lld\n",++TN,ans);
	}
}