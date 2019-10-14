#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int n;
double p[100500];

double solve() {
	cin >> n;
	for (int i = 1; i <= n + n; i++) {
		cin >> p[i];
	}
	sort(p + 1, p + 1 + n + n);
	int le = 1;
	int ri = n + n;
	double ans = 1.0;
	while (le < ri) {
		ans = ans * (1 - p[le++] * p[ri--]);
	}
	return ans;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int tc;
	cin >> tc;
	cout << fixed << setprecision(6);
	for (int i = 1; i <= tc; i++) {
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}