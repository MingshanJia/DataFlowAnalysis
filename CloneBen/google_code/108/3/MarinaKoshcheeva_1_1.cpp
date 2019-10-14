#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100;

long double p[MAXN];
int n;

void solve() {
	memset(p, 0, sizeof(p));
	scanf("%d", &n);
	int m = n;
	n = 2 * n;
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	sort(p, p + n);
	long double result = 1;
	for (int i = 0; i < m; ++i)
		result = result * (1 - p[i] * p[n - i - 1]);
	printf("%.8Lf", result);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
}
