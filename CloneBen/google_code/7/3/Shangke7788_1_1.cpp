#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 555;
int a[MAX_N], b[MAX_N], n;
int c[MAX_N * 10], p, ans[MAX_N];

int main() {
	int T;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++) {
		scanf("%d", &n);
		memset(c, 0, sizeof c);
		memset(ans, 0, sizeof ans);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", a + i, b + i);
			if (a[i] > b[i]) swap(a[i], b[i]);
			for (int j = a[i]; j <= b[i]; j++) {
				++c[j];
			}
		}
		scanf("%d", &p);
		printf("Case #%d: ", ca);
		for (int i = 1; i <= p; i++) {
			int x;
			scanf("%d", &x);
			if (x > 5000 || x < 0) {
				printf("%d%c", 0, " \n"[i == p]);
			} else printf("%d%c", c[x], " \n"[i == p]);
		}
	}
	return 0;
}
