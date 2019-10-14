#include <cstdio>
#include <algorithm>
#define INF 9223372036854775800L
long long t,n,m[4][4],a[4],b[4],v[11],ck[11],c,s,mx,f[4],g[4];
long long x[11]={0,1,1,1,2,2,2,3,3,3};
long long y[11]={0,1,2,3,1,2,3,1,2,3};
long long p[362883][11];

inline long long min2(long long k, long long l){
	if(k>l){return l;}
	return k;
}

void recall(long long lev){
	if(lev>9){
		c++;
		for(long long i=1;i<=9;i++){
			p[c][i]=v[i];
		}
	}else{
		for(long long i=1;i<=9;i++){
			if(ck[i]){continue;}
			ck[i]=1; v[lev]=i;
			recall(lev+1);
			ck[i]=0;
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	FILE *fp2=fopen("output.txt","w");
	scanf("%lld",&t);
	long long k,i,j,w;
	recall(1);
	for(k=1;k<=t;k++){
		printf("%lld\n",k);
		scanf("%lld",&n);
		for(i=1;i<=3;i++){ scanf("%lld",&a[i]); }
		for(i=1;i<=3;i++){ scanf("%lld",&b[i]); }
		for(i=1;i<=3;i++){
			for(j=1;j<=3;j++){
				scanf("%lld",&m[i][j]);
			}
		}
		mx=-INF;
		for(i=1;i<=c;i++){
			f[1]=a[1],f[2]=a[2],f[3]=a[3],g[1]=b[1],g[2]=b[2],g[3]=b[3]; s=0;
			for(j=1;j<=9;j++){
				w=min2(f[x[p[i][j]]],g[y[p[i][j]]]);
				s+=w*m[x[p[i][j]]][y[p[i][j]]];
				f[x[p[i][j]]]-=w;
				g[y[p[i][j]]]-=w;
			}
			if(s>mx){
				mx=s;
			}
		}
		fprintf(fp2,"Case #%lld: %lld\n",k,mx);
	}
	return 0;
}
