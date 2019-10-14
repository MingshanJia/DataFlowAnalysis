#include <stdio.h>

int main()
{
    int t, i, j;
    long long n;
    int a[100];

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
	int p = 0, sum = 0, f = 0;

	scanf("%lld", &n);

	while (n) {
	    a[p++] = n % 2;
	    n /= 2;
	}

	if (p == 1) {
	    printf("Case #%d: %d\n", i + 1, a[0]);

	    continue;
	}

	for (j = 0; j < p - 1; j++) {
	    if (a[j] == 0) {
		if (f == 0) {
		    sum += 2;
		    f = 1;
		} else {
		    sum++;
		}
	    } else {
		if (f == 0) {
		    sum++;
		} else {
		    sum += 2;
		}
	    }
	}

	if (f == 0) sum++;

	printf("Case #%d: %d\n", i + 1, sum);
    }

    return 0;
}
