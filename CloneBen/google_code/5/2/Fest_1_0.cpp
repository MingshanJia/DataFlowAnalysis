#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

int main() {
#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out_small.txt", "w", stdout);
#endif // LOCAL
	int t, v, d, cas = 0;
	double g = 9.8;
	scanf("%d", &t);
	while (t-- && scanf("%d%d", &v, &d)) {
		printf("Case #%d: %.7f\n", ++cas, asin(1.0 * g * d / (v * v)) * 90 / PI);
	}
	return 0;
}
