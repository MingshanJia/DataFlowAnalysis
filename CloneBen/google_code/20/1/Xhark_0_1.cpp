#include <stdio.h>
long long gcd(long long x, long long y){
	if (x == 0) return y;
	return gcd(y % x, x);
}
int main(){
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T-->0){
		long long month, day, week;
		scanf("%lld %lld %lld", &month, &day, &week);
		long long sol;
		sol = 0;
		long long gg = gcd(day, week);

		long long tt = week / gg;
		long long pre = month / tt;
		long long post = month % tt;

		long long i;
		for(i=0;i<week;i+=gg) {
			//pre번 i부터 시작함 ^^
			sol += pre * ((i+day+week-1)/week);
		}
		long long now;
		now = 0;
		for(i=0;i<post;i++){
			//now 부터 시작함
			sol += (now+day+week-1) / week;
			now = (now + day) % week;
		}

		static int cs = 1;
		printf("Case #%d: %lld\n", cs++,sol);
	}
	return 0;
}