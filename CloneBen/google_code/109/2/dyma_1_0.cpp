#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4;

int a[maxn];

void solve() {
	int n, d, k;
	cin >> d >> k >> n;
	for (int i = 1; i <= d; i++) {
		a[i - 1] = i;
	}
	for (int it = 0; it < n; it++) {
		for (int l = it % 2, step = 0; step + step < d; step++, l += 2) {
			l %= d;
			swap(a[l], a[(l + 1) % d]);
		}
	}
	for (int i = 0; i < d; i++) {
		if (a[i] == k) {
			cout << a[(i + 1) %d] << " " << a[(i - 1 + d + d) % d] << endl;			
		}
	}
}

int main() {
	int test = 0;
	cin >> test;
	for (int i = 1; i <= test; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}



