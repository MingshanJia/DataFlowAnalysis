#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long c;
    long long t;
    int s;
} coffee;

int cmp(const void *a, const void *b)
{
    return ((coffee *)b)->s - ((coffee *)a)->s;
}


int main()
{
    int t, n, i, j, l, m;
    long long k;
    coffee c[100];

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
	int p = 2;
	long long sum = 0;
	long long a[1000][2] = {0, 0, 1e18, 1e18};

	scanf("%d %lld", &n, &k);

	for (j = 0; j < n; j++) scanf("%lld %lld %d", &c[j].c, &c[j].t, &c[j].s);

	qsort(c, n, sizeof(coffee), cmp);

	for (j = 0; j < n; j++) {
	    for (l = p - 2; l >= 0; l--) {
		if (c[j].t > a[l + 1][0]) {
		    if (a[l + 1][0] - c[j].c > a[l][1]) {
			a[l + 1][0] -= c[j].c;

			sum += c[j].c * c[j].s;

			break;
		    } else {
			sum += (a[l + 1][0] - a[l][1]) * c[j].s;

			c[j].c -= a[l + 1][0] - a[l][1];
			a[l + 1][0] = a[l][1];
		    }
		} else if (c[j].t > a[l][1]) {
		    if (c[j].t - a[l][1] > c[j].c) {
			for (m = p; m > l; m--) {
			    a[m + 1][0] = a[m][0];
			    a[m + 1][1] = a[m][1];
			}

			a[l + 1][0] = c[j].t - c[j].c;
			a[l + 1][1] = c[j].t;

			sum += c[j].c * c[j].s;

			p++;

			break;
		    } else {
			sum += (c[j].t - a[l][1]) * c[j].s;

			c[j].c -= c[j].t - a[l][1];
			a[l][1] = c[j].t;
		    }
		}
	    }
	}

	printf("Case #%d: %lld\n", i + 1, sum);
    }

    return 0;
}
