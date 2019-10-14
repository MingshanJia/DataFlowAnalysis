#include <bits/stdc++.h>
using namespace std;

int n;
int arr[7005];
long long num[200005];
long long ab[200005];

int main() {
	int t, no = 0; scanf("%d", &t);
	while (t--) {
		memset(num, 0, sizeof(num));
		memset(ab, 0, sizeof(ab));
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &arr[i]), ++num[arr[i]];
		for (int i = 0; i < n; ++i) {
			if (arr[i] <= 1) continue;
			for (int j = i + 1; j < n; ++j) {
				if (arr[j] <= 1) continue;
				if ((long long) arr[i] * arr[j] > 200000) continue;
				ab[arr[i] * arr[j]]++;
			}
		}
		long long ans = 0;
		long long ans2 = 0;
		for (int i = 0; i < n; ++i) {
			ans += ab[arr[i]];
		}

		for (int i = 2; i < 200005; ++i) {
			ans2 += (long long)num[i] * (num[i] - 1) / 2;
		}

		ans += (long long)ans2 * num[1];

		ans += (long long)num[1] * (num[1] - 1) * (num[1] - 2) / 6;

		ans += (long long)num[0] * (num[0] - 1) * (num[0] - 2) / 6;

		ans += ((long long)num[0] * (num[0] - 1) / 2) * (n - num[0]);

		printf("Case #%d: %lld\n", ++no, ans);
	}
	return 0;
}