#include <stdio.h>
#include <math.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    for(int x = 1; x <= t; x++) {
	double v, d;
	scanf("%lf %lf", &v, &d);
	double res = d*9.8/(v*v);
	res = res > 1 ? 1:res;
	res = asin(res)/2*180/M_PI;
	printf("Case #%d: %f\n", x, res);
    }
}
