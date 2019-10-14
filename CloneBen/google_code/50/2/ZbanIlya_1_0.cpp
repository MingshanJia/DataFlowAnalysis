#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
#include <cassert>
#include <queue>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

const int MAXN = -1;
const double eps = 1e-10;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cout.precision(10);
	cout << fixed;
	cerr.precision(10);
	cerr << fixed;

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";
		cerr << "Case #" << test << ": ";

		int n;
		double v, x;
		cin >> n >> v >> x;
		vector<double> s(n);
		vector<double> c(n);
		for (int i = 0; i < n; i++) cin >> s[i] >> c[i];
		vector<pair<double, double> > a(n);
		for (int i = 0; i < n; i++) a[i] = make_pair(c[i], s[i]);
		sort(a.begin(), a.end());

		double maxflow = 0;
		for (int i = 0; i < n; i++) maxflow += s[i];

		double l = v / maxflow, r = 1e12;
		for (int it = 0; it < 200; it++) {
			double m = (l + r) / 2.0;

			double mn1 = 0, mn2 = 0;
			for (int i = 0; i < n; i++) {
				double o = min(v - mn2, a[i].second * m);
				mn1 += o * a[i].first;
				mn2 += o;
			}
			double mn = mn1 / mn2;

			double mx1 = 0, mx2 = 0;
			for (int i = n - 1; i >= 0; i--) {
				double o = min(v - mx2, a[i].second * m);
				mx1 += o * a[i].first;
				mx2 += o;
			}
			double mx = mx1 / mx2;

			if (mn < x + eps && x - eps < mx) r = m;
			else l = m;
		}

		if (r > 1e11) {
			cout << "IMPOSSIBLE" << endl;
			cerr << "IMPOSSIBLE" << endl;
		} else {
			cout << r << endl;
			cerr << r << endl;
		}
	}

    return 0;
}