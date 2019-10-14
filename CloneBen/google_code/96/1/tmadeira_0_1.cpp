#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define ll long long
#define llu unsigned long long

#define ABS(X) max((X), -(X))

using namespace std;

#define DMAX 5005
#define LMAX 20
#define NMAX 505

char P[DMAX][LMAX];

int main() {
	int l, d, n;
	scanf("%d %d %d", &l, &d, &n);
	for (int i = 0; i < d; i++) {
		scanf("%s", P[i]);
	}
	for (int t = 1; t <= n; t++) {
		set <int> S[l];
		for (int j = 0; j < l; j++) {
			char c;
			scanf(" %c", &c);
			S[j].clear();
			if (c == '(') {
				char tmp[NMAX];
				scanf(" %[^)])", tmp);
				int k = strlen(tmp);
				for (int i = 0; i < k; i++) {
					S[j].insert(tmp[i]);
				}
			} else {
				S[j].insert(c);
			}
		}
		int count = 0;
		for (int i = 0; i < d; i++) {
			int ok = 1;
			for (int j = 0; j < l && ok; j++) {
				if (S[j].find(P[i][j]) == S[j].end()) {
					ok = 0;
				}
			}
			count+= ok;
		}
		printf("Case #%d: %d\n", t, count);
	}
	return 0;
}

