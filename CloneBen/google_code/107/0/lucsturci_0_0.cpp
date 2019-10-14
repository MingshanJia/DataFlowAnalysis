#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int N = 1000007, inf = 0x3f3f3f3f;

void solve() {
	int n;
	cin >> n;

	priority_queue<int> pq;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		pq.push(-a);
	}

	ll ans = 0;
	int l, r;
	l = 0, r = n-1;
	while(pq.size()) {
		int x = -pq.top();
		pq.pop();
		//Left
		int a = l;
		int b = (n-1)-r;
		if(a < b) {
			l++;
		} else {
			--r;
		}
		ans += (x - min(a, b)) * (x - min(a, b));
	}

	cout << ans << endl;
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