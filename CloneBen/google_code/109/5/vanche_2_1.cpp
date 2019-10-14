#include <cstdio>
#include <cstring>
#define LL long long
#define mod 1000000007
int tc, tcn,l;
LL c, v,dc[505],dv[505];

void solve() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%lld %lld %d", &c, &v, &l);
		memset(dc, 0, sizeof(dc));
		memset(dv, 0, sizeof(dv));

		dc[1] = c;
		dv[1] = v;
		for (int i = 2; i <= l; i++) {
			dc[i] = (dv[i - 1]*c)%mod;
			dv[i] = (dv[i - 1]*v + dc[i - 1]*v) % mod;
		}
		printf("Case #%d: %lld\n", ++tcn, dv[l]);
	}
}

int main(void) {
	//freopen("cin2.txt", "r", stdin);
	//freopen("cout2.txt", "w", stdout);
	solve();
	return 0;
}