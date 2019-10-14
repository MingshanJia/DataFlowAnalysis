#include <stdio.h>

long long gcd(long long a, long long b)
{
	if(a % b == 0) return b;
	if(a < b) return gcd(b, a);
	return gcd(b, a%b);
}

int main(void)
{
	int t, lt = 0;
	long long a, b, c, d, e;
	long long d1;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld %lld %lld", &a, &b, &c);
		d = a*b;
		if(d % c != 0) e = d / c + 1;
		else e = d / c;
		d1 = c / gcd(b, c);
		
		e += (a-1);
		e -= (a-1)/d1;


		printf("Case #%d: %lld\n", ++lt, e);
	}	

	return 0;
}