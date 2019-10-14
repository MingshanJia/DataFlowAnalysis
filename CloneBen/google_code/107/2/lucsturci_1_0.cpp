#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int N = 1007, inf = 0x3f3f3f3f;

ll tot[N];

void solve() {
	int n;
	cin >> n;

	memset(tot, 0, sizeof tot);
	for(int i = 0; i < n; ++i) {
		ll a, b;
		cin >> a >> b;
		tot[b] = a;
	}

	ll last = -1;
	for(int i = 0; i < N; ++i) {
		if(tot[i] == 0) continue;

		ll cnt = tot[i] * i;
		for(int j = 0; j < i; ++j) {
			ll x = min(tot[j], cnt);
			tot[j] -= x;
			cnt -= x;
		}
		last = i;
	}

	ll cnt = 0;
	for(int i = 0; i < N; ++i) cnt += tot[i];
	cout << max(cnt, last + 1) << endl;

}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	for(int i = 0; i < t; ++i) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
	
}