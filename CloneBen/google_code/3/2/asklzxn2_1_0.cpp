#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int T, n, cnt;
int a[5005];
int b[12500005];

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	scanf("%d", &T);
	for (int Cas = 1; Cas <= T; ++Cas) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		sort(a, a + n);
		cnt = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < i; ++j)
				if (a[i] != a[j])
					b[cnt++] = a[i] - a[j];
		sort(b, b + cnt);
		long long ans = 0;
		for (int i = 0; i < n;) {
			int s = i;
			for (; i < n && a[i] == a[s]; ++i);
			int num = i - s;
			if (num == 1) continue;
			int res = lower_bound(b, b + cnt, 2 * a[s]) - b;
			int limit;
			if (a[s] > 1000000001 / 3) limit = 1000000001;
			else limit = a[s] * 3;
			int j = lower_bound(a, a + n, limit) - a;
			ans += 1ll * num * (num - 1) / 2 * (res - num * (j - num));
			ans += 1ll * num * (num - 1) * (num - 2) / 6 * (j - num);
			
		}
		cout << "Case #" << Cas << ": " << ans << "\n";
	}
	return 0;
}
