
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
   
int n, k;
pair<int, int> a[1007];
double dp[1002][1002];

bool cmp(pair<int, int> a, pair<int, int> b){
	return (ll)a.x * (ll)a.y > (ll)b.x * (ll)b.y;
}

bool is_testing = 0;
int main(){
	if (is_testing){
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	int tt;
	cin >> tt;
	for (int ss = 0; ss < tt; ss++){
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i].y >> a[i].x;
		sort(a, a + n, cmp);
		double ans = 0;
		for (int i = 0; i < n; i++){
			double now = pi * (double)a[i].y * (double)a[i].y + (double)2 * pi * (double)a[i].x * (double)a[i].y;
			int was = 1;
			for (int j = 0; j < n; j++) if (i != j){
				if (was == k) break;
				was++;
				now += (double)2 * pi * (double)a[j].x * (double)a[j].y;
			}
			ans = max(ans, now);
		}
		cout << "Case #" << ss + 1 << ": ";
		cout.precision(8);
		cout << fixed << ans << "\n";
	}
}