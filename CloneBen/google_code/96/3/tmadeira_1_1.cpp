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

#define NMAX 128
#define INF 16384

int A[NMAX][NMAX];

int F[NMAX*NMAX];
int R[NMAX*NMAX];
char L[NMAX*NMAX];

int FIND(int x) {
	return (x != F[x]) ? F[x] = FIND(F[x]) : F[x];
}

void UNION(int x, int y) {
	x = FIND(x);
	y = FIND(y);
	if (R[x] > R[y]) {
		F[y] = x;
	} else {
		F[x] = y;
		if (R[x] == R[y]) {
			R[y]++;
		}
	}
}

int m, n;

int id(int i, int j) {
	return (i-1)*n+(j-1);
}

int main() {
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++) {
		scanf("%d %d", &m, &n);
		for (int i = 0; i <= m+1; i++) {
			for (int j = 0; j <= n+1; j++) {
				A[i][j] = INF;
				R[id(i, j)] = 0;
				F[id(i, j)] = id(i, j);
			}
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &A[i][j]);
			}
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				int k = min(A[i-1][j], A[i][j-1]);
				k = min(k, A[i+1][j]);
				k = min(k, A[i][j+1]);
				if (k < A[i][j]) {
					if (A[i-1][j] == k) {
						UNION(id(i, j), id(i-1, j));
					} else if (A[i][j-1] == k) {
						UNION(id(i, j), id(i, j-1));
					} else if (A[i][j+1] == k) {
						UNION(id(i, j), id(i, j+1));
					} else {
						UNION(id(i, j), id(i+1, j));
					}
				}
			}
		}
		char l = 'a';
		printf("Case #%d:\n", test);
		memset(L, 0, sizeof(L));
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (L[FIND(id(i, j))] == 0) {
					L[FIND(id(i, j))] = l++;
				}
				if (j != 1) {
					printf(" ");
				}
				printf("%c", L[FIND(id(i, j))]);
			}
			printf("\n");
		}
	}
	return 0;
}

