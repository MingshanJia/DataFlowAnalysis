#include <stdio.h>

int main()
{
    int t, c, w, m, p, i, j;
    int a[100], b[100];

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
	scanf("%d %d %d", &m, &c, &w);

	for (j = 0; j < c; j++) scanf("%d %d", &a[j], &b[j]);

	p = w;

	for (j = c - 1; j >= 0; j--) {
	    if (p <= b[j]) {
		p = a[j] + p - 1;
	    } else if (p <= a[j] + b[j] - 1) {
		p -= b[j];
	    }
	}

	printf("Case #%d: %d\n", i + 1, p);
    }

    return 0;
}
