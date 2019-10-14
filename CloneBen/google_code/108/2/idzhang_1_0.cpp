#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

const int MAXN = 50;
double p[2*MAXN];

int main() {
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int n;
		cin >> n;
		for (int i = 0; i < 2*n; i++) {
			cin >> p[i];
		}
		// sort probabilities
		sort(p, p+2*n);
		// probability of succeeding
		double res = 1;
		for (int i = 0; i < n; i++) {
			res *= (1-p[i]*p[2*n-1-i]);
		}
		cout << "Case #" << tc+1 << ": ";
		cout << fixed << setprecision(6) << res << endl;
	}
}