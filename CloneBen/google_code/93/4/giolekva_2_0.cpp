#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, m;
int q[100000];

int main(void) {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int i, j, k, x, t;

	scanf("%d", &t);
	for(x = 0; x < t; x++) {
		scanf("%d %d", &n, &m);
		for(i = 0; i < m; i++)
			scanf("%d", &q[i]);
		
		long long sol = -1;

		sort(q, q + m);
		do {
			long long sum = 0;
			for(i = 0; i < m; i++) {
				int l = 0, r = n + 1;
				for(j = 0; j < i; j++) 
					if (q[j] < q[i]) {
						if (q[j] > l) l = q[j];
					} else {
						if (q[j] < r) r = q[j];
					}
				sum += r - l - 2;
			}
			if (sum < sol || sol == -1) sol = sum;
		}while (next_permutation(q, q + m));

		cout << "Case #" << x+1 << ": " << sol << endl;
	}

	exit(0);
}