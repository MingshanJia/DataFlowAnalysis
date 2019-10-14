#include <stdio.h>
#include <algorithm>
#define Min(a,b) ((a)>(b)?(b):(a))
#define Max(a,b) ((a)>(b)?(a):(b))
FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");
int a[3],b[3],A[3],B[3],T,t,i,j,table[3][3],g[9];
long long ans,n;
struct List{
	long long x,y,z;
}list[12];
int main(){
	for(fscanf(in,"%d",&T);T--;){
		fscanf(in,"%lld",&n); ans=-1e12;
		for(i=0;i<3;i++) fscanf(in,"%d",&a[i]),A[i]=a[i];
		for(i=0;i<3;i++) fscanf(in,"%d",&b[i]),B[i]=b[i];
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				fscanf(in,"%d",&table[i][j]);
				list[i*3+j].x=i; list[i*3+j].y=j; list[i*3+j].z=table[i][j];
			}
		}
		for(i=0;i<9;i++) g[i]=i;
		int what=9*8*7*6*5*4*3*2*1;
		while(what--){
			long long good=0;
			for(i=0;i<3;i++) a[i]=A[i],b[i]=B[i];
			for(i=0;i<9;i++){
				int x=list[g[i]].x,y=list[g[i]].y;
				long long tar=Min(a[x],b[y]);
				a[x]-=tar; b[y]-=tar; good+=tar*list[g[i]].z;
			}
			std::next_permutation(g,g+9);
			ans=Max(good,ans);
		}
		fprintf(out,"Case #%d: %lld\n",++t,ans);
	}
	return 0;
}