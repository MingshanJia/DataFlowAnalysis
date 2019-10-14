#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, n;
	double prob;
	cin >> t;
	for (int test=1; test<=t; test++) {
		cin >> n;
		vector<double> arr;
		for (int i=0; i<2*n; i++) {
			cin >> prob;
			arr.push_back(prob);
		}
		sort(arr.begin(), arr.end());
		double ans = 1.00;
		for (int i=0; i<n; i++) {
			ans = ans*(1.00 - arr[i]*arr[2*n-1-i]);
		}
		printf("Case #%d: %lf\n", test, ans);
	}

	return 0;
}