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

bool cmp(int i, int j) {
	return p[i] < p[j];
}
bool cmp2(int i, int j) {
	return p[i] > p[j];
}

double calc2(vector<int> a, vector<int> b) {
	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), cmp2);
	double temp = 1.0;
	for (int i = 0; i < n; i++) {
		temp *= (1 - p[a[i]] * p[b[i]]);
	}
	return temp;
}

double calc3() {
	vector<int> a(n * 2);
	for (int i = 0; i < n * 2; i++) {
		a[i] = i;
	}
	sort(a.begin(), a.end(), cmp);
	double temp = 1.0;
	for (int i = 0; i < n; i++) {
		temp *= (1 - p[a[i]] * p[a[n * 2 - i - 1]]);
	}
	return temp;
}


int main() {
#ifdef _DEBUG
	freopen("B-large.in",  "r", stdin);
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

		double ans3 = calc3();
		cout.precision(6);
		cout << "Case #" << test + 1 << ": " << fixed << ans3 << endl;

	}
	return 0;
}