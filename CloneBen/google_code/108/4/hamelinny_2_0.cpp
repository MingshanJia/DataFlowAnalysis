#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

char field[20][20];


void clear() {
	for (int i = 0; i < 15; i += 4) {
		for (int j = 0; j < 15; j++) {
			field[j][i] = 'I';
		}
	}
	for (int i = 2; i < 15; i += 4) {
		for (int j = 0; j < 15; j++) {
			field[j][i] = 'O';
		}
	}
	for (int i = 1; i < 15; i += 2) {
		for (int j = 0; j < 15; j++) {
			field[j][i] = '/';
		}
	}
}

int main() {
	freopen("C-small.in", "r", stdin);
	freopen("C-small.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		
		int d, n;
		cin >> d >> n;

		n = 287 - n;


		clear();

		int si = 1, sj = 1;
		while (n - 3 >= 0 && si < 14) {
			field[si][sj] = 'O';
			sj += 2;
			if (sj >= 15) {
				si++;
				sj = 1;
			}
			n -= 3;

		}
		si = 0, sj = 1;
		while (n > 0) {
			field[si][sj] = 'O';
			sj += 2;
			if (sj >= 15) {
				si = 14;
				sj = 1;
			}
			n--;
		}

		cout << "Case #" << i + 1 << ": " << '\n';

		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				cout << field[i][j];
			}
			cout << '\n';
		}

	}



	return 0;
}