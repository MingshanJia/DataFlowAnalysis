#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int d, n;

void solve() {
	cin >> d >> n;
	for (int i = 1; i <= d; i++) {
		if (i % 2 == 0) {
			for (int j = 1; j <= d; j++) {
				cout << "O";
			}
			cout << endl;
			continue;
		} else {
			int cnt = min(16, n);
			int empty = d - cnt * 3;
			n -= cnt;
			for (int j = 1; j <= cnt; j++) {
				cout << "I/O";
			}
			for (int j = 1; j <= empty; j++) {
				cout << "O";
			}
			cout << endl;
		}
	}
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int tc;
	cin >> tc;
	cout << fixed << setprecision(6);
	for (int i = 1; i <= tc; i++) {
		cout << "Case #" << i << ":" << endl;
		solve();
	}
	return 0;
}