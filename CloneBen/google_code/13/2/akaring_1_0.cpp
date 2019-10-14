//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define REP(i,n) for (int i=0,n_=int(n); i<n_; ++i)
#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(),(c).end()
using namespace std; typedef long long lint;
template<typename T> inline void checkMin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (a < b) a = b; }

const double PI = acos(-1.0);

int main() {
	int n_case;
	scanf("%d", &n_case);
	for (int index = 1; index <= n_case; ++index) {
		double v, d, g = 9.8;
		scanf("%lf%lf", &v, &d);
		printf("Case #%d: %.10lf\n", index, 0.5 * asin(d * g / (v * v)) * 180 / PI);
	}
	return 0;
}
