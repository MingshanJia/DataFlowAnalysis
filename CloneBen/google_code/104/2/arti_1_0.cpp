#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>

#include <iostream>

#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;

typedef long long i64;

bool _p[1000000];
int u[10000];
int p[1000000];

int main() {
	int T; scanf("%d", &T);
	int pc = 0;
	for (int i = 2; i <= 10000; ++i) if (!_p[i]) {
		p[pc++] = i;
		for (int j = i * i; j <= 10000; j += i) {
			_p[j] = true;
		}
	}
	for (int tt = 0; tt < T; ++tt) {
		i64 A, B, P;
		cin >> A >> B >> P;
		for (int i = A; i <= B; ++i) {
			u[i] = i;
		}
		int x = 0;
		while (p[x] < P) ++x;
		while (true) {
			bool ff = false;
			for (int i = A; i <= B; ++i) {
				for (int j = i + 1; j <= B; ++j) if (u[i] != u[j]) {
					bool f = false;
					for (int k = x; p[k] <= B; ++k) if ((i % p[k] == 0) && (j % p[k] == 0)) {
						f = true;
						break;
					}
					if (f) {
						ff = true;
						int t = u[i];
						for (int k = A; k <= B; ++k) {
							if (u[k] == t) u[k] = u[j];
						}
					}
				}
			}
			if (!ff) break;
		}
		sort(u + A, u + B + 1);
		int result = unique(u + A, u + B + 1) - (u + A);
		printf("Case #%d: ", tt + 1);
		cout << result << endl;
	}
	return 0;
}
