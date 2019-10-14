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

int t, n, lis[5555];
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	FOR (cas, 1, t) {
		cout << "Case #" << cas << ": ";
		cin >> n;
		FOR (i, 1, n) cin >> lis[i];
		sort(lis + 1, lis + 1 + n);
		int st = 1;
		// PR(lis, 1, n);
		long long ans = 0;
		while (st <= n) {
			int en = st;
			while (en + 1 <= n && lis[st] == lis[en + 1]) en++;
			// cout << st << ' ' << en << endl;
			long long range = en - st + 1;
			// ans += range * (range - 1) * (range - 2) * (range - 3) / 24;
			FOR (i, 1, st - 1) if (lis[st] - lis[i] < 2 * lis[st]) {
				ans += range * (range - 1) * (range - 2) / 6 * (st - i);
				break;
			}
			// BUG(ans);
			FORD (i, n, en + 1) if (lis[i] - lis[st] < 2 * lis[st]) {
				ans += range * (range - 1) * (range - 2) / 6 * (i - en);
				break;
			}
			// BUG(ans);
			v.clear();
			FOR (i, 1, st - 1) v.pb(lis[i]);
			FOR (i, en + 1, n) v.pb(lis[i]);
			int r = 0;
			int l = 0;
			while (l < v.size()) {
				while (r + 1 < v.size() && v[r + 1] - v[l] < 2 * lis[st]) r++;
				int ll = l;
				while (ll + 1 < v.size() && v[ll + 1] == v[l]) ll++;
				ans += range * (range - 1) / 2 * (r - ll) * (ll - l + 1);
				l = ll + 1;
			}
			st = en + 1;
			// BUG(ans);
		}
		cout << ans << endl;
	}
}