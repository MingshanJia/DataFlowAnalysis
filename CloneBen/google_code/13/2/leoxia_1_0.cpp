#include <iostream>
#include <cmath>
using namespace std;

#define g 9.8

int main() {
	int T, V, D;
	cin >> T;
	const double PI = acos(-1);
	for (int t = 1; t <= T; t++) {
		cin >> V >> D;
		double x = 9.8*D/(V*V);
		if (x > 1) x = 1;
		else if (x < -1) x=-1;
		
		double th = asin(x) * 90.0 / PI;
		printf("Case #%d: %.7lf\n", t, th);
		//cout << "Case #" << t <<": " << th << endl;
	}
	return 0;
}