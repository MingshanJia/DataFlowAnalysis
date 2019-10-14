#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int tc, tcn, n, ch[202];
long long a[202];

void solve() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		n *= 2;
		for (int i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		
		printf("Case #%d: ", ++tcn);
		memset(ch, 0, sizeof(ch));
		for (int i = 0; i < n; i++) {
			if (ch[i])
				continue;
			printf("%lld ", a[i]);
			for (int j = i + 1; j < n; j++) {
				if (ch[j])
					continue;
				if (a[j] * 3 == a[i] * 4) {
					ch[j] = 1;
					break;
				}
			}
		}
		puts("");

	}
}

int main(void) {
	//freopen("Ain2.txt", "r", stdin);
	//freopen("Aout2.txt", "w", stdout);
	solve();
	return 0;
}