#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

int a[1000000];
ll dp[1000000];

int main(void)
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ll all = 0;
		int n, m;
		ll x, y, z;
		cin >> n >> m >> x >> y >> z;
		ll g[128];
		for (int i = 0; i < m; i++) cin >> g[i];
		//
		for (int i = 0; i < n; i++) {
			a[i] = g[i % m];
			g[i % m] = (x * g[i % m] + y * ((ll)i+1)) % z;
		}
		//
		for (int i = 0; i < n; i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++)
				if (a[j] < a[i])
					dp[i] = (dp[i] + dp[j]) % MOD;
			all = (all + dp[i]) % MOD;
		}
		//
		cout << "Case #" << tc << ": " << all << endl;
	}
	return 0;
}
