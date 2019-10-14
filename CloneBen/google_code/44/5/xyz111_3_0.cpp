#include <cstdio>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int n, a[1000], ans;
int b[1000];

int sum(int x) {
	int cnt = 0;
	for (int i = 0; i < n * n; i++)
		if ((1 << i) & x)
			cnt += 1;
	return cnt;
}

bool pei(int A, int B) {
	for (int i = 0; i < (1 << n); i++) {
		int arr = 0;
		for (int j = 0; j < n; j++)
			if ((1 << j) & (A & i))
				arr |= b[j];
		if (sum(A & i) > sum(arr & B)) {
			// printf("?? %d %d\n", i, arr);
			return false;
		}
	}
	return true;
}

bool valid(int S) {
	for (int i = 0; i < n; i++) {
		b[i] = 0;
		for (int j = n - 1; j >= 0; j--) {
			b[i] *= 2;
			if (S & (1 << (i * n + j)))
				b[i] += 1;
		}
	}
	for (int A = 0; A < (1 << n); A++)
		for (int B = 0; B < (1 << n); B++)
			if (sum(A) == sum(B) && pei(A, B)) {
				// printf("?? %d %d\n", A, B);
				if (!pei((1 << n) - 1 - A, (1 << n) - 1 - B))
					return false;
			}
	return true;
}

void doit() {
	scanf("%d", &n);
	int tot = 0;
	for (int i = 0; i < n * n; i++) {
		char k;
		for (k = getchar(); k <= 32; k = getchar());
		a[i] = k - '0';
		tot += a[i] * (1 << i);
	}
	ans = n * n;
	// printf("%d\n", valid(15));
	for (int i = 0; i < (1 << (n * n)); i++)
		if ((i & tot) == tot && valid(i)) {
			ans = min(ans, sum(i) - sum(tot));
		}
	printf("%d\n", ans);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: " , i);
		doit();
	}
}
