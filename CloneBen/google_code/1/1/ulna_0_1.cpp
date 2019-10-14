#include <bits/stdc++.h>
using namespace std;

int cnt[200055];

void solve() {
	int n;
	scanf("%d", &n);
	
	vector<int> a(n);
	
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);;
	}
	
	long long res = 0;
	
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) if (i != j) {
			long long val = 1ll * a[i] * a[j];
			
			bool op = false;
			long long add = 0;
			vector<int> vec;
			
			// i * j == val
			if (val <= (long long)2e5) {
				add += cnt[val];
				vec.push_back(val);
			}
			
			// i * val == j
			if (a[i] > 0 && a[j] % a[i] == 0) {
				add += cnt[a[j] / a[i]];
				vec.push_back(a[j] / a[i]);
			} else if (a[i] == 0) {
				if (a[j] == 0) {
					add += i;
					op = true;
				}
			}
			
			if (a[j] > 0 && a[i] % a[j] == 0) {
				add += cnt[a[i] / a[j]];
				vec.push_back(a[i] / a[j]);
			} else if (a[j] == 0) {
				if (a[i] == 0) {
					add += i;
					op = true;
				}
			}
			
			if (op) {
				res += i;
			} else {
				sort(vec.begin(), vec.end());
				vec.erase(unique(vec.begin(), vec.end()), vec.end());
				
				for (auto u : vec) res += cnt[u];
			}
		}
		
		cnt[a[i]]++;
	}
	
	printf("%lld\n", res);
	
	for (auto u : a) cnt[u]--;
}
int main() {
	int _t;
	cin >> _t;
	
	for (int _ = 0; _ < _t; _++) {
		printf("Case #%d: ", _ + 1);
		solve();
	}
}
