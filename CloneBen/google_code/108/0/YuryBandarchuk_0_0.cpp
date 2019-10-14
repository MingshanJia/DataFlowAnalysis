#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int f, s;
int x[1111], y[1111];
int a[1111][1111];

int solve() {
	cin >> f >> s;
	for (int i = 1; i <= s; i++) {
		for (int j = 1; j <= s; j++) {
			a[i][j] = 0;
		}
	}
	for (int i = 1; i <= f; i++) {
		cin >> x[i] >> y[i];
	}
	int ans = 0;
	for (int i = 1; i <= s; i++) {
		for (int z = 1; z <= s; z++) {
			for (int zz = 1; zz <= s; zz++) {
				a[z][zz] = 0;
			}
		}
		for (int j = 1; j <= f; j++) {
			int px = x[j];
			int py = y[j];
			if (py == i) {
				swap(px, py);
			}	
			a[px][py] = 1;
		}
		int c = 0;
		for (int j = 1; j <= s; j++) {
			c += a[i][j];
		}
		ans = max(ans, c);
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