#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;

const long double eps = 1e-7;

string s[50];

int count() {
	int ans = 0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (s[i][j] == 'I') {
				for (int dx = -1; dx <= 1; dx++) {
					for (int dy = -1; dy <= 1; dy++) {
						int x = i + dx;
						int y = j + dy;
						if (x >= 0 && x < 15 && y >= 0 && y < 15) {
							if (s[x][y] == '/') {
								int xx = x + dx;
								int yy = y + dy;
								if (xx >= 0 && xx < 15 && yy >= 0 && yy < 15) {
									if (s[xx][yy] == 'O') {
										++ans;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return ans;
}

void init() {
	for (int i = 0; i < 15; i++) {
		s[i] = "I/O/I/O/I/O/I/O";
	}
}

void solve() {
	int x;
	cin >> x >> x;
	init();
	for (int i = 0; i < 15; i++) {
		if (count() == x) break;
		for (int j = 0; j < 15; j++) {
			if (count() == x) break;
			if (s[i][j] == 'I') {
				if (count() > x) {
					s[i][j] = '/';
					if (count() < x) {
						s[i][j] = 'O';
						if (count() > x) {
							s[i][j] = '/';
						} else if (count() < x) {
							s[i][j] = 'I';
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 15; i++) {
		if (count() == x) break;
		for (int j = 0; j < 15; j++) {
			if (count() == x) break;
			if (s[i][j] == '/') {
				if (count() > x) {
					s[i][j] = 'O';
					if (count() < x) {
						s[i][j] = '/';
					}
				}
			}
		}
	}
	for (int i = 0; i < 15; i++) {
		if (count() == x) break;
		for (int j = 0; j < 15; j++) {
			if (count() == x) break;
			if (s[i][j] == 'O') {
				if (count() > x) {
					s[i][j] = '/';
					if (count() < x) {
						s[i][j] = 'O';
					}
				}
			}
		}
	}
	for (int i = 0; i < 15; i++) {
		cout << s[i] << endl;
	}
	if (count() == x) {
		cerr << "YES: " << x << endl;
	} else {
		cerr << "FAIL: " << x << endl;
	}
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("kek.out","w",stdout);
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cout << "Case #" << i << ":" << endl;
		solve();
		cerr << i << endl;
	}
	return 0;
}