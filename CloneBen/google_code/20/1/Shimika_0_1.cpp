#include <cstdio>
long long m,d,w,a[105],ck[105],r,x,l,s,k,t;
long long pre,trm,presum,trmsum,sum;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%lld",&k);
	for(t=1;t<=k;t++){
		scanf("%lld %lld %lld",&m,&d,&w);
		pre=trm=presum=trmsum=sum=r=x=l=s=0;
		int i;
		for(i=0;i<=100;i++){a[i]=ck[i]=0;}

		for(i=1;i<=m;i++){
			x=d; l=0;
			if(r!=0){ 
				if(x>r){
					x-=r; l++; 
				}else{
					r-=x; l++; x=0;
				}
			}

			if(x==0){
			}else{
				if(x%w==0){
					r=0; l+=x/w;
				}else{
					r=(x/w+1)*w-x; l+=x/w+1;
				}
			}
			a[i]=l;
			s+=l;
			//printf("%lld %lld %lld\n",x,l,r);

			if(ck[r]){
				pre=ck[r]-1;
				trm=i-ck[r];
				break;
			}
			ck[r]=i;
		}
		if(trm==0){
			sum=s;
		}else{
			for(i=1;i<=pre;i++){ presum+=a[i]; }
			for(i=1;i<=trm;i++){ trmsum+=a[i+pre]; }
			sum+=presum; m-=pre;
			sum+=trmsum*(m/trm); m%=trm;
			for(i=1;i<=m;i++){ sum+=a[i+pre]; }
		}
		printf("Case #%lld: %lld\n",t,sum);
	}
	return 0;
}
