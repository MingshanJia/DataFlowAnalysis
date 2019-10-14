#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <queue>
#include <numeric>
using namespace std;
typedef long long li;
#define mp make_pair
#define sz(a) (int)a.size()
const int N = 1e5 + 5;
double p[N];
int n;

double calc(vector<int> a, vector<int> b) {
	double ans = 0.0;
	do {
		double temp = 1.0;
		for (int i = 0; i < n; i++) {
			temp *= (1 - p[a[i]] * p[b[i]]);
		}
		ans = max(ans, temp);
	} while (next_permutation(a.begin(), a.end()));
	return ans;
}

int main() {
#ifdef _DEBUG
	freopen("B-small-attempt0.in",  "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout.sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int test = 0; test < t; test++) {
		
		cin >> n;
		for (int i = 0; i < 2 * n; i++) {
			cin >> p[i];
		}
		int nn = 2 * n;


		double ans = 0.0;
		for (int mask = 0; mask < (1 << nn); mask++) {
			int cntbit = 0;
			for (int j = 0; j < nn; j++) {
				if ((mask & (1 << j)) != 0)
					cntbit++;
			}
			if (cntbit == n) {
				vector<int> a, b;
				for (int j = 0; j < nn; j++) {
					if ((mask & (1 << j)) != 0) {
						a.push_back(j);
					}
					else {
						b.push_back(j);
					}
				}
				assert(a.size() == n);
				assert(b.size() == n);
				ans = max(ans, calc(a, b));
			}
		}
		cout.precision(6);
		cout << "Case #" << test + 1 << ": " << fixed << ans << endl;
	}
	return 0;
}