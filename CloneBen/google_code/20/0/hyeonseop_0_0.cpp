#pragma warning(disable:4996)

#include <iostream>

int tc;
int mon, day, week, res;

void input(){
	scanf("%d %d %d", &mon, &day, &week);
}

void process(){
	int i, t = 0;
	res = 0;
	for(i = 0; i < mon; i++){
		res += (t + day + week - 1) / week;
		t = (t + day) % week;
	}
}

void output(){
	printf("Case #%d: %d\n", tc, res);
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