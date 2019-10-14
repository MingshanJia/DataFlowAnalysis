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

	double ans = 0;
	for (int mask = 0; mask < (1 << (2 * n)); mask++) {
		vector <int> p1;
		vector <int> p2;
		for (int i = 0; i < 2 * n; i++) {
			if (((1 << i) & mask) != 0) {
				p1.push_back(i);
			}
			else {
				p2.push_back(i);
			}
		}

		if (p1.size() == p2.size()) {
			sort(p2.begin(), p2.end());
			do {
				double tans = 1;
				for (int i = 0; i < p2.size(); i++) {
					tans *= (1 - prob[p2[i]] * prob[p1[i]]);
				}
				ans = max(tans, ans);
			} while (next_permutation(p2.begin(), p2.end()));
		}
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