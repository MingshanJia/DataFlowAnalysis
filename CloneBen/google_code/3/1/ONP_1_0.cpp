#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <ctime>

using namespace std;

int n, l[5100];
int c[5100], a[5100], s[5100];
int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int ca = 0;
	int T;
	for (scanf("%d", &T); T; T--) {
		printf("Case #%d: ", ++ca);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", l + i);
		sort(l, l + n);
		memset(c, 0, sizeof c);
		c[0] = 1, a[0] = l[0];
		int m = 1;
		for (int i = 1; i < n; i++)
			if (l[i] == a[m - 1]) c[m - 1]++;
			else {
				c[m] = 1, a[m] = l[i];
				m++;
			}
		s[0] = c[0] * (c[0] - 1) / 2;
		for (int i = 1; i < m; i++)
			s[i] = s[i - 1] + c[i] * (c[i] - 1) / 2;
		long long ans = 0;
		for (int i = 0; i < m; i++)
			for (int j = i + 1; j < m; j++) {
				for (int k = 0; k < m; k++)
					if (k != i && k != j && a[k] + (long long)a[i] + a[k] > a[j])
						ans += (long long)c[i] * (long long)c[j] * c[k] * (long long)(c[k] - 1) / 2;
				if (a[i] * 3LL > a[j])
					ans += (c[i] - 2) * (long long)(c[i] - 1) * c[i] / 6 * c[j];
				ans += (c[j] - 2) * (long long)(c[j] - 1) * c[j] / 6 * c[i];
			}
		cout << ans << endl;
	}
}

