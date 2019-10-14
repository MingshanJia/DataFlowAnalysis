#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

string a[maxn], r[maxn];
int b[maxn];

int main() {
	freopen("C-small-1-attempt1.in", "r", stdin);
	freopen("C-small-1-attempt1.ou", "w", stdout);
	int T, cases = 0;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		getline(cin, a[0]);
		for(int i = 1; i <= n; i++) {
			getline(cin, a[i]);
			r[i] = a[i];
			//cout << a[i] << endl;
		}
		sort(r + 1, r + 1 + n);
		for(int i = 1; i <= n; i++) {
			b[i] = lower_bound(r + 1, r + 1 + n, a[i]) - r;
		}
		int ans = 0;
		for(int i = 2; i <= n; i++) {
			if(b[i] < b[i - 1]) {
				int u = i;
				while(u != 1 && b[u] < b[u - 1]) {
					swap(b[u], b[u - 1]);
					u--;
				}
				ans++;
			}
		}
		printf("Case #%d: %d\n", ++cases, ans);
	}
	return 0;
}
