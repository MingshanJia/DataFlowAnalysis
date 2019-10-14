#include <stdio.h>
#include <string.h>

int a[510], b[510];

int main() {
	int cas;
	scanf("%d", &cas);
	for (int re = 1; re <= cas; re++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", a + i, b + i);
		}
		int p;
		scanf("%d", &p);
		printf("Case #%d:", re);
		for (int i = 0; i < p; i++) {
			int k;
			scanf("%d", &k);
			int ans = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] <= k && b[i] >= k) {
					ans++;
				}
			}
			printf(" %d", ans);
		}
		puts("");
	}
}