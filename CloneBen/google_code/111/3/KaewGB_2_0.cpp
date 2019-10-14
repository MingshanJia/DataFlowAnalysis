#include <stdio.h>

long long int choose(int n, int c){
	int i;
	long long int count=1;
	for(i=0;i<c;i++)
		count *= (n-i);
	for(i=1;i<=c;i++)
		count /= i;
	return count;
}
long long int factorial(int n){
	int i;
	long long int count=1;

	if(n<2)
		return 1;

	for(i=1;i<=n;i++)
		count *= i;
	return count;
}
void solve(){
	int n, k, i, remaining;
	int table[30];
	long long int count=1;

	scanf("%d %d", &n, &k);
	// Find #people per table
	for(i=0;i<k;i++)
		table[i] = n/k + (i<n%k);

	// Counting
	remaining=n;
	count = factorial(n);
//	printf("%d! = %lld\n", n, count);
	for(i=0;i<k;i++){
		count /= factorial(table[i]);
//		printf("/=%d! = %lld\n", table[i], factorial(table[i]));
		if(table[i]>3){
			count *= (long long int)factorial(table[i]-1)/(long long int)2;	// #ways to seat selected people in the table
//			printf("%d! = %lld\n", table[i]-1, factorial(table[i]-1)/2);
		}
	}
//	printf("n mod k=%d, other=%d\n", n%k, k-(n%k));
	count /= factorial(n%k) * factorial(k-(n%k));
	printf("%lld", count);
}

int main(int argc, char *argv[]){
	int i, t;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		printf("Case #%d: ", i+1);
		solve();
		printf("\n");
	}
	return 0;
}

