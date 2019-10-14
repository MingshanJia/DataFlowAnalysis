#include<stdio.h>

long long months, mday, wday, r[1000], l[1000], rot, rem;

void process(){
	int i,n;
	r[1]=mday%wday; l[1]=(mday+wday-1)/wday;
	for(n=2;;n++){
		r[n]=(mday+r[n-1])%wday;
		if(r[n]==r[1]){
			n--;
			break;
		}
		l[n]=(mday+r[n-1]+wday-1)/wday;
	}
	rot=months/n;
	rem=months%n;
	long long ans=0;
	for(i=1;i<=n;i++){
		ans+=l[i];
	}
	ans*=rot;
	for(i=1;i<=rem;i++){
		ans+=l[i];
	}
	printf("%lld\n",ans);
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t, i=0;
	for(scanf("%d",&t);t>0;t--){
		scanf("%lld%lld%lld",&months,&mday,&wday);
		printf("Case #%d: ",++i);
		process();
	}
	return 0;
}