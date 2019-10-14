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

int a[2000000];
int d[1000];

int main() {
	int T; scanf("%d", &T);
	for (int tt = 0; tt < T; ++tt) {
		int n, m; scanf("%d %d", &n, &m);
		for (int i = 0; i < m; ++i) {
			scanf("%d", &d[i]);
		}
		memset(a, 0, sizeof(a));
		int last = n;
		for (int i = 1; i <= n; ++i) {
			for (int k = 0; k < i; ++k) {
				++last;
				if (last > n) last = 1;
				while (a[last]) {
					++last;
					if (last > n) last = 1;
				}
			}
			a[last] = i;
		}
		printf("Case #%d:", tt + 1);
		for (int i = 0; i < m; ++i) {
			printf(" %d", a[d[i]]);
		}
		cout << endl;
	}
	return 0;
}
