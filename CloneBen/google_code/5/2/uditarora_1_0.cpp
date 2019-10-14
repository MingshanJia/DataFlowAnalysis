#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

// v*cosx*t = d;
// t = 2*v*sinx/g
// d = (v^2)*sin(2x)/g;
// sin(2x) = d*g/v^2

int main(void) {
	int t, v, d;
	scanf("%d", &t);
	for (int tn = 1; tn <= t; ++tn) {
		scanf("%d %d", &v, &d);
		double x2 = (double)d*9.8/((double)v*v);
		if (x2 > 1)
			x2 = 1;
		double angle = asin(x2)/(double)2;
		angle = angle*(double)180/((double)M_PI);
		printf("Case #%d: %.7lf\n", tn, angle);
	}
	return 0;
}