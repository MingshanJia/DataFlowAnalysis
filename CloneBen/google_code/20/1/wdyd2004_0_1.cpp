#include <stdio.h>
#include <memory.h>
FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");
long long T,a,b,c,t,namugi[1005],v[1005],i,ans,A[1005];
int main(){
	for(fscanf(in,"%lld",&T);T--;){
		fscanf(in,"%lld%lld%lld",&a,&b,&c);
		namugi[0]=c; ans=0; A[0]=0;
		memset(v,-1,sizeof(v));
		int flag=0;
		for(i=0;i<a;i++){
			long long j=v[namugi[i]],k;
			if(j!=-1&&i!=j){
				k=(i-j);
				long long l=(a-i)/k;
				if(l){
					ans+=l*(A[i]-A[j]); a=a-l*k; i--; continue;
				}
			}
			v[namugi[i]]=i;
			long long B=b,C=c;
			if(B>c-namugi[i]){
				if(namugi[i]!=c){
					B-=(c-namugi[i]); ans++;
				}
				if(B%C==0){
					namugi[i+1]=c; ans+=B/C;
				}
				else{
					namugi[i+1]=B%C; ans+=B/C+1;
				}
			}
			else namugi[i+1]=namugi[i]+B,ans++;

			A[i+1]=ans;
		}
		fprintf(out,"Case #%lld: %lld\n",++t,ans);
	}
	return 0;
}
