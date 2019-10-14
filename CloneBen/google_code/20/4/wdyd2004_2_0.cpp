#include <stdio.h>
#include <algorithm>
FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");
int T,t;
int n,p,q,m,i,j,cnt;
long long s[1005],vo[10005],D[10005],ok[10005];
int wx[10005],wy[10005];
struct List{
	long long x,y,z;
	bool operator()(List a,List b){
		return a.x<b.x;
	}
}list[1000005];
struct Heap{
	long long x,z;
	bool operator()(Heap a,Heap b){
		return a.z<b.z;
	}
}heap[1000005];
int main(){
	for(fscanf(in,"%d",&T);T--;){
		fscanf(in,"%d%d%d",&n,&p,&q); m=0;
		for(i=0;i<p;i++) fscanf(in,"%lld%lld",&s[i],&vo[i]),s[i]--;
		for(i=0;i<n;i++) wx[i]=wy[i]=0; cnt=0;
		for(i=0;i<q;i++){
			long long d,tt,x,y;
			fscanf(in,"%lld%lld%lld",&d,&tt,&x); x--;
			tt--;
			while(tt--){
				fscanf(in,"%lld",&y); y--;
				list[m].x=x; list[m].y=y; list[m++].z=d;
				list[m].x=y; list[m].y=x; list[m++].z=d;
				x=y;
			}
		}
		std::sort(list,list+m,List());
		for(i=1;i<m;i++) if(list[i].x!=list[i-1].x) wy[list[i-1].x]=wx[list[i].x]=i;
		wy[list[m-1].x]=m;
		for(i=0;i<n;i++) ok[i]=0;
		for(i=0;i<p;i++){
			for(j=0;j<n;j++) D[j]=1e15;
			D[s[i]]=0; cnt=0;
			heap[cnt].x=s[i]; heap[cnt++].z=0; std::push_heap(heap,heap+cnt,Heap());
			while(cnt){
				long long x=heap[0].x,z=heap[0].z;
				std::pop_heap(heap,heap+cnt,Heap()); cnt--;
				if(D[x]!=z) continue;
				for(j=wx[x];j<wy[x];j++){
					int y=list[j].y;
					if(D[y]>D[x]+list[j].z){
						D[y]=D[x]+list[j].z;
						heap[cnt].x=y; heap[cnt++].z=D[y]; std::push_heap(heap,heap+cnt,Heap());
					}
				}
			}
			for(j=0;j<n;j++){
				if(D[j]*vo[i]>ok[j]) ok[j]=D[j]*vo[i];
			}
		}
		long long ans=1e10;
		for(i=0;i<n;i++) if(ans>ok[i]) ans=ok[i];
		if(ans>2147483647) ans=-1;
		fprintf(out,"Case #%d: %lld\n",++t,ans);
	}
	return 0;
}