#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);

	int tt = 0;
	while (t--) {
		long long m, md, wd;
		scanf("%lld %lld %lld", &m, &md, &wd);

		int i, j;

		long long answer, mul = 0, rest = 0;
		for (i=0; i<wd; i++) {
			mul += (rest + md + wd-1) / wd;
			rest = (rest + md) % wd;
		}
		answer = mul * (m / wd);

		rest = 0;
		for (i=0; i<(m % wd); i++) {
			answer += (rest + md + wd-1) / wd;
			rest = (rest + md) % wd;
		}

		printf("Case #%d: %d\n", ++tt, answer);
	}

	return 0;
}
