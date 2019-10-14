#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 5e6 + 10;

int n, a[MAXN], pt[MAXN];
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;	cin >> te;
	for (int w = 1; w <= te; w++){
		cout << "Case #" << w << ": ";
		cin >> n;
		cin >> s;
		for (int i = 0; i < n; i++) a[i] = (int)(s[i] - '0');

		for (int i = 0; i < n; i++) pt[i+1] = pt[i] + a[i];

		int ans = 0;
		int k = n+1>>1;
		for (int i = k; i <= n; i++)
			ans = max(ans, pt[i] - pt[i-k]);
		cout << ans << "\n";
	}
	return 0;
}
