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

double x[3], y[3], z[3];
int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int ca = 0;
	int T;
	for (scanf("%d", &T); T; T--) {
		printf("Case #%d: ", ++ca);
		double ma = -1100, mi = 1100;
		for (int i = 0; i < 3; i++) {
			scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
			ma = max(ma, x[i]);
			mi = min(mi, x[i]);
		}
		printf("%.8f\n", (ma - mi) / 6);
	}
}

