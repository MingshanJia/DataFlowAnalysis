#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

bool was[105][105];

int sum[105];

void clear(int s) {
	for (int i = 0; i <= s; i++) {
		for (int j = 0; j <= s; j++)
			was[i][j] = false;
		sum[i] = 0;
	}
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int f, s;
		cin >> f >> s;
		int mx = 0;
		clear(s);
		for (int j = 0; j < f; j++) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			if (!was[x][y]) {
				was[x][y] = true;
				sum[x]++;
			}
			if (!was[y][x]) {
				was[y][x] = true;
				sum[y]++;
			}
			mx = max(mx, sum[x]);
			mx = max(mx, sum[y]);
		}

		cout << "Case #" << i + 1 << ": " << mx << '\n';

	}



	return 0;
}