//Input 1
#include <cstdio>
#include <cstdlib>

int T,N,K;
double P;
double list[58];
int cmp(const void *ka,const void *kb) {
	double a=*(double *)ka;
	double b=*(double *)kb;
	if(a<b) return -1;
	if(a>b) return 1;
	return 0;
}
double EPS=0.00000000001;
int main() {
	scanf("%d",&T);
	for(int cases=1;cases<=T;cases++) {
		scanf("%d%d",&N,&K);
		scanf("%lf",&P);
		for(int i=0;i<N;i++) scanf("%lf",&list[i]);
		qsort(list,N,sizeof(double),cmp);
		list[N]=1;
		for(int i=1;i<=N;i++) {
			if(P+EPS<(list[i]-list[i-1])*i) {
				for(int j=0;j<i;j++) list[j]+=P/i;
				break;
			}
			P-=(list[i]-list[i-1])*i;
			for(int j=0;j<i;j++) list[j]=list[i];
		}
		double sol=1;
		for(int i=0;i<N;i++) sol*=list[i];
		printf("Case #%d: %.12lf\n",cases,sol);
	}
	return 0;
}
