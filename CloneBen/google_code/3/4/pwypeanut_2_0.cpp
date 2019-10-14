#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int x, y, z;
		vector<int> v;
		for (int i = 0; i < 3; i++) {
			scanf("%d%d%d", &x, &y, &z);
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		printf("Case #%d: %.10lf\n", tc, (double)(v.back() - v.front()) / 6);
	}
}
