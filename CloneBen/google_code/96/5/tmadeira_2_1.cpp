#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include <iostream>
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

string W = "welcome to code jam", S;
int n, m = 19;
int M[32][512];

int rec(int aW, int aS) {
	if (M[aW][aS] != -1) {
		return M[aW][aS];
	}
	int ret = 0;
	for (int i = aS; i < n; i++) {
		if (W[aW] == S[i]) {
			ret+= rec(aW+1, i+1);
			ret%= 10000;
		}
	}
	M[aW][aS] = ret;
	return ret;
}

int main() {
	int tests;
	scanf("%d\n", &tests);
	for (int test = 1; test <= tests; test++) {
		getline(cin, S);
		n = S.size();
		memset(M, -1, sizeof(M));
		for (int i = 0; i <= n; i++) {
			M[m][i] = 1;
		}
		for (int i = 0; i < m; i++) {
			M[i][n] = 0;
		}
		printf("Case #%d: ", test);
		printf("%04d\n", rec(0, 0));
	}
	return 0;
}

