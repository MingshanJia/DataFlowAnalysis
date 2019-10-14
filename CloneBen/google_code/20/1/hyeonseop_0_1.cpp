#pragma warning(disable:4996)

#include <iostream>

int tc;
long long mon, day, week, res;

void input(){
	scanf("%lld %lld %lld", &mon, &day, &week);
}

long long gcd(long long x, long long y){
	if(x == 0){
		return y;
	}
	return gcd(y % x, x);
}

void process(){
	res = mon * day / week;
	res += mon;
	res -= mon / (week / gcd(week % day, day));
}

void output(){
	printf("Case #%d: %lld\n", tc, res);
}

int main(){
	int t;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for(tc = 1; tc <= t; tc++){
		input();
		process();
		output();
	}
	return 0;
}