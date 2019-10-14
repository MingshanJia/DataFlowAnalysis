#include <iostream>
#include <cmath>
#include <cstdio>
#define PI acos(-1.0)
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for(int cs = 1; cs <= t; ++cs) {
		int v, d;
		scanf("%d%d", &v, &d);
		double s = 9.8 * d / v / v;
		double angle = asin(s) / 4 / PI * 360;
		printf("Case #%d: %.7lf\n", cs, angle);
	}
	return 0;
}
