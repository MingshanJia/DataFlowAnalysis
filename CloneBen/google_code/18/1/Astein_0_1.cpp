#include <cstdio>
#include <iostream>

using namespace std;

long long r[3], c[3], a[3][3];
long long s[3][3];
long long seq[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

int main() {
	long long T;
	cin >> T;
	for (long long cn = 1; cn <= T; ++cn) {
		long long N;
		cin >> N;
		for (long long i = 0; i < 3; ++i) cin >> r[i];
		for (long long i = 0; i < 3; ++i) cin >> c[i];
		for (long long i = 0; i < 3; ++i)
			for (long long j = 0; j < 3; ++j)
				cin >> a[i][j];
		for (long long i = 0; i < 3; ++i) {
			for (long long j = 0; j < 3; ++j) {
				long long mv = min(r[i], c[j]);
				s[i][j] = mv;
				r[i] -= mv;
				c[j] -= mv;
			}
		}
		bool changed = true;
		while (changed) {
			changed = false;
			
			for (long long i = 0; i < 6; ++i) {
				for (long long j = 0; j < 6; ++j) {
					if (i == j) continue;
					long long mv = s[0][seq[i][0]];
					for (long long k = 1; k < 3; ++k) {
						mv = min(mv, s[k][seq[i][k]]);
					}
					if (mv > 0) {
						long long suma = 0, sumb = 0;
						for (long long k = 0; k < 3; ++k) {
							suma += a[k][seq[i][k]];
							sumb += a[k][seq[j][k]];
						}
						if (suma < sumb) {
							for (long long k = 0; k < 3; ++k) {
								s[k][seq[i][k]] -= mv;
								s[k][seq[j][k]] += mv;
							}
							changed = true;
						}
					}
				}
			}
			for (long long c1 = 0; c1 < 9; ++c1) {
				long long x1 = c1 / 3, y1 = c1 % 3;
				for (long long c2 = 0; c2 < 9; ++c2) {
					long long x2 = c2 / 3, y2 = c2 % 3;
					if (x1 == x2 || y1 == y2) continue;
					long long mv = min(s[x1][y1], s[x2][y2]);
					if (mv > 0) {
						long long suma = a[x1][y1] + a[x2][y2];
						long long sumb = a[x1][y2] + a[x2][y1];
						if (suma < sumb) {
							s[x1][y1] -= mv;
							s[x2][y2] -= mv;
							s[x1][y2] += mv;
							s[x2][y1] += mv;
							changed = true;
						}
					}
				}
			}
		}
		long long ret = 0;
		for (long long i = 0; i < 3; ++i)
			for (long long j = 0; j < 3; ++j)
				ret += s[i][j] * a[i][j];
		cout << "Case #" << cn << ": " << ret << endl;
	}
}

