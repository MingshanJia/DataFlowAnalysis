#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int ca = 1; ca <= T; ca++) {
		int V, D;
		cin >> V >> D;
		printf("Case #%d: %.7lf\n", ca, asin(((double)(98 * D) / (double)(V * V)) / 10) / 2 / 3.1415926535 * 180);
	}
	return 0;
}
