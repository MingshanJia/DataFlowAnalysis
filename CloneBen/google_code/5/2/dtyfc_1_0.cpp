#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);

int main() {
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.ou", "w", stdout);
	int T, v, d, cases = 0;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &v, &d);
		double l = 0, r = pi / 4, ans;
		for(int i = 0; i < 100; i++) {
			double mid = (l + r) / 2;
			if(sin(2.0 * mid) * v * v / 9.8 <= d) {
				l = mid;
				ans = mid;
			} else {
				r = mid;
			}
		}
		printf("Case #%d: %.10f\n", ++cases, ans * 180.0 / pi);
	}
	return 0;
}
