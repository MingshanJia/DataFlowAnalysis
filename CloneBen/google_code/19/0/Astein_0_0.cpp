#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int table[1000][4000];

int main() {
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		int n;
		scanf("%d", &n);
		vector<pair<int, int> > a(n);
		vector<int> best(n, -1);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i].first, &a[i].second);
			table[i][0] = 1;
		}
		int ret = 0;
		vector<int> p(n);
		for (int i = 0; i < n; ++i) p[i] = i;
		do {
			int ct = 0;
			for (int i = 0; i < n; ++i) {
				if (ct <= a[p[i]].first) {
					ct += a[p[i]].second;
				} else break;
			}
			if (ret < ct) ret = ct;
		} while (next_permutation(p.begin(), p.end()));
		printf("Case #%d: %d\n", cn, ret);
	}
}

