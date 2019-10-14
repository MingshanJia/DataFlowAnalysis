#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
#include <algorithm>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <string>
#include <queue>
#include <random> 
#include <map>
#include <numeric>
using namespace std;
typedef long long li;
#define mp make_pair
#define sz(a) (int)a.size()
const int N = 1e3 + 5;
const int INF = 1e9 + 7;
char c[N];
string s[N];

double calc() {
	int n;
	cin >> n;
	vector <double> prob(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		cin >> prob[i];
	}

	sort(prob.begin(), prob.end());
	double ans = 1;
	for (int i = 0; i < n; i++) {
		ans *= (1 - prob[i] * prob[2 * n - i - 1]);
	}
	return ans;
}
void solve() {
	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
		
		double ans = calc();
		cin.precision(6);
		cout << "Case #" << q + 1 << ": " << fixed << ans << endl;
 	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout.sync_with_stdio(false);
	cin.tie(0);
	srand(time(NULL));
	solve();

	return 0;
}