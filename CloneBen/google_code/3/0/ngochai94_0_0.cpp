#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define all(x) x.begin(), x.end()
#define uni(x) x.erase(unique(all(x)), x.end());
#define BUG(x) cout << #x << " = " << x << endl
#define BUGP(x) cout << #x << " = " << x._1 << ", " << x._2 << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto _i:x) cout << _i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 1e-6
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int t, same[333][333], dp[333][333], cul[333];
string s;

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	FOR (cas, 1, t) {
		cout << "Case #" << cas << ": ";
		cin >> s;
		reset(same, 0);
		reset(dp, 55);
		int n = s.size();
		FOR (i, 1, n) FOR (j, i + 1, n) {
			int tmp = 0;
			while (i - tmp > 0 && j - tmp > i && s[i - tmp - 1] == s[j - tmp - 1]) tmp++;
			same[i][j] = same[j][i] = tmp;
		}
		dp[0][0] = 0;
		cul[0] = 0;
		FOR (i, 1, n) {
			dp[i][0] = cul[i - 1] + 1;
			cul[i] = dp[i][0];
			FOR (j, 1, i - 1) {
				FOR (k, 1, i - 1) if (same[i][k] >= j) {
					dp[i][j] = min(dp[i][j], dp[k][j] + 1 + i - j - k);
					dp[i][j] = min(dp[i][j], cul[k] + 2 + i - j - k);
					dp[i][j] = min(dp[i][j], cul[i - j] + 2);
				}
				cul[i] = min(cul[i], dp[i][j]);
			}
		}
		// FOR (i, 1, n) cout << i << ' ' << s.substr(0, i) << ' ' << cul[i] << endl;
		cout << cul[n] << endl;
	}
}