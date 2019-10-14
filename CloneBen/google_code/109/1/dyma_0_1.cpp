#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000;

bool used[maxn];
int a[maxn];

void solve() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n + n; i++)
		cin >> a[i];
	for (int i = 0; i < n + n; i++)
		used[i] = false;
	sort(a, a + n + n);
	for (int i = 0; i < n + n; i++) {
		if (!used[i]) {
			cout << a[i] << " ";
			for (int j = i + 1; j < n + n; j++) {
				if (a[i] / 3 == a[j] / 4 && !used[j]) {
					used[j] = true;
					break;
				}
			}
		}
	}
	cout << endl;
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