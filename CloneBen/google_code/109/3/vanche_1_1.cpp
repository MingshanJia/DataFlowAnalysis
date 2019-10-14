#include <cstdio>
#include <cstring>
int tc, tcn,d,k,n,le,mid,ri;

int get(int t) {
	int ret;
	if ((t - 1) % 2 == 0)
		ret = (t - 1 + n) % d;
	else
		ret = (t - 1 - n + d) % d;

	return ret;
}

void solve() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d", &d, &k, &n);
		n %= d;
		mid = get(k);
		for (int i = 1; i <= d; i++) {
			int ret = get(i);
			if (ret == (mid + 1) % d)
				le = i;
			if (ret == (mid - 1 + d) % d)
				ri = i;
		}
		printf("Case #%d: %d %d\n", ++tcn, le, ri);
	}
}

int main(void) {
	//freopen("Bin2.txt", "r", stdin);
	//freopen("Bout2.txt", "w", stdout);
	solve();
	return 0;
}