
#include <bits/stdc++.h>
	
#define pub push_back
#define ll long long
#define mp make_pair
#define all(a) a.begin(), a.end()
#define x first
#define y second
	
const int INF = (int)1e9 + 7;
const ll LINF = (ll)4e18 + 7;
	
const double pi = acos(-1.0);

using namespace std;
   
int tt, n, m;
int was[1447];
int dp[1447][727][2][2];

bool is_testing = 0;
int main(){
	if (is_testing){
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> tt;
	for (int ss = 0; ss < tt; ss++){
		for (int i = 0; i < 27 * 67; i++) was[i] = -1;
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			int l, r;
			cin >> l >> r;
			r--;
			for (int j = l; j <= r; j++) was[j] = 0;
		}
		for (int i = 0; i < m; i++){
			int l, r;
			cin >> l >> r;
			r--;
			for (int j = l; j <= r; j++) was[j] = 1;
		}
		for (int i = 0; i < 1447; i++) for (int j = 0; j < 727; j++) for (int v = 0; v < 2; v++) for (int s = 0; s < 2; s++) dp[i][j][v][s] = INF;
		if (was[0] == -1) dp[0][1][0][0] = 0, dp[0][0][1][1] = 0;
		if (was[0] == 0) dp[0][1][0][0] = 0;
		if (was[0] == 1) dp[0][0][1][1] = 0;
		for (int i = 1; i < 1440; i++) for (int j = 0; j <= 720; j++) for (int v = 0; v < 2; v++) for (int s = 0; s < 2; s++) for (int f = 0; f < 2; f++){
			if (dp[i - 1][j][v][s] == INF) continue;
			if (was[i] != -1 && was[i] != f) continue;
			dp[i][j + (f == 0)][v][f] = min(dp[i][j + (f == 0)][v][f], dp[i - 1][j][v][s] + (s != f));
		}
		int ans = INF;
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) ans = min(ans, dp[1439][720][i][j] + (i != j));
		cout << "Case #" << ss + 1 << ": " << ans << "\n";
	}
}