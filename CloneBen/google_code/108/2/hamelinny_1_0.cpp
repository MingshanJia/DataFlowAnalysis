#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

double p[105];


int main() {
	freopen("B-small1.in", "r", stdin);
	freopen("B-small1.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < 2 * n; j++) {
			cin >> p[j];
		}

		sort(p, p + 2 * n);

		double ans = 1.0;

		for (int j = 0; j < n; j++) {
			ans *= (1 - p[j] * p[2 * n - 1 - j]);
		}

		cout << "Case #" << i + 1 << ": " << fixed << setprecision(8) << ans << '\n';

	}



	return 0;
}