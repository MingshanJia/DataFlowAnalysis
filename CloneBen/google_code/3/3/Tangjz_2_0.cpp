#include <bits/stdc++.h>
using namespace std;
typedef long double DB;
const int maxt = 101;
const DB eps = 1e-12;
int t, x[3], y[3], z[3];
int sgn(DB x) {
	return (x > eps) - (x < -eps);
}
int dcmp(DB x, DB y) {
	return sgn(x - y);
}
bool check(DB rad) {
	DB pL = x[0] + rad * 2, pR = x[2] - rad * 2;
	// 1 circle
	if(dcmp(x[2], pL) <= 0)
		return 1;
	// 2 circle 2 + 1
	if(dcmp(pL + rad, pR - rad) >= 0 && dcmp(pL, x[1]) >= 0)
		return 1;
	// 2 circle 1 + 2
	if(dcmp(pL + rad, pR - rad) >= 0 && dcmp(x[1], pR) >= 0)
		return 1;
	// 3 circle
	if(dcmp(pL + rad, pR - rad) >= 0 && dcmp(pL, x[1]) <= 0 && dcmp(x[1], pR) <= 0)
		return 1;
	return 0;
}
int main() { // only small case
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		for(int i = 0; i < 3; ++i)
			scanf("%d%d%d", x + i, y + i, z + i);
		sort(x, x + 3);
		DB L = 0, R = 1000;
		for(int i = 0; i < maxt; ++i) {
			DB M = L + (R - L) / 2;
			if(check(M))
				R = M;
			else
				L = M;
		}
		printf("Case #%d: %.10f\n", Case, (double)L);
	}
	return 0;
}
