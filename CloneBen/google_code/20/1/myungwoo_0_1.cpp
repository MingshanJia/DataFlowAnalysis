#include <stdio.h>

typedef long long lld;

int T,K;
lld M,D,W;

lld gcd(lld a,lld b){ return b?gcd(b,a%b):a; }

int main()
{
	lld all,k,lcd,bonus;
	freopen("input.txt","r",stdin), freopen("output.txt","w",stdout);
	for (scanf("%d",&T);T--;){
		scanf("%lld%lld%lld",&M,&D,&W);
		all = M*D;
		k = (M*D-1)/W+1;
		lcd = W*D/gcd(W,D);
		bonus = all/lcd;
		if (all%lcd == 0) bonus--;
		k += M-bonus-1;
		printf("Case #%d: %lld\n",++K,k);
	}
}