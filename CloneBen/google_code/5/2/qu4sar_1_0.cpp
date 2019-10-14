//AV
//quasar

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> graph;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, cs = 1;
	cin >> t;
	double pi = 3.1415926535897;
	while (t--){
		int v, d;
		double g = 9.8;
		cin >> v >> d;
		double ans = (d*g) / (v*v);
		ans = min(1.0, ans);
		ans = max(0.0, ans);
		ans = asin(ans) / 2;
		ans = (ans * 360) / (2 * pi);
		cout << fixed;
		cout << setprecision(7) << "Case #" << cs++ << ": " << ans << "\n";
	}
}
