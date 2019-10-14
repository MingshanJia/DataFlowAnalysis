#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXM 1004
typedef long long lld;

int T,TN,N,B,M,K,X,Y; lld ans;

struct Z{
	lld p,q;
	bool operator < (const Z &b)const{
		return p<b.p;
	}
} A[MAXM];

void proc()
{
	int i,rec=0,t,min=1e16,x=0,y=0;
	for (i=1,t=K;i<=K;i++) if (A[i].q){
		while (t >= i && A[i].p+A[t].p >= B){
			if (A[t].q && (i != t || A[t].q > 1)) rec = t;
			t--;
		}
		if (rec && i > rec) break;
		if (rec && (i != rec || A[i].q > 1) && min > A[i].p+A[rec].p) min = A[i].p+A[rec].p, x = i, y = rec;
	}
	for (i=K+1;i<=M;i++) if (A[i].q && min > A[i].p) min = A[i].p, x = i, y = 0;
	X = x, Y = y;
}

bool use()
{
	if (!X || !A[X].q || (Y && !A[Y].q) || (X == Y && A[X].q < 2)){ proc(); }
	if (!X) return 0;
	A[X].q--; ans += A[X].p;
	if (Y){
		if (!A[Y].q) return 0;
		A[Y].q--, ans += A[Y].p;
	}
	return 1;
}

int main()
{
	int i,j,k;
	freopen("input.txt","r",stdin), freopen("output.txt","w",stdout);
	for (scanf("%d",&T);T--;){
		scanf("%d%d%d",&N,&M,&B);
		for (i=1;i<=M;i++){
			scanf("%lld%lld",&A[i].p,&A[i].q);
		}
		sort(A+1,A+M+1); K = X = Y = ans = 0;
		for (i=1;i<=M&&A[i].p<B;i++) K = i;
		for (i=1;i<=N;i++){
			if (!use()) break;
		}
		printf("Case #%d: %lld\n",++TN,i<=N?-1:ans);
	}
}