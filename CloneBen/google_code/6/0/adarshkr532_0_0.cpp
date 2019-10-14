#include<bits/stdc++.h>
using namespace std;

#define ld double
#define int long long int
#define pi pair<ld,ld>
#define pb push_back
#define fi first
#define se second
#define mod 1e18
#define inf 1e9
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#ifndef LOCAL
#define endl'\n'
#endif

const int N = 200005;

vector<string> v;

signed main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out1.txt","w",stdout);
	IOS;
	int t, p, n;
	cin >> t;
	for(int z = 1; z <= t; z++){
		cin >> n >> p;
		int ans = pow(2, n);
		v.clear();
		for(int i = 1; i <= p; i++){
			string s;
			cin >> s;
			v.pb(s);
		}
		sort(v.begin(), v.end());
		for(int i = 0; i < v.size(); i++){
			int flag = 1;
			for(int j = 0; j < i; j++){
				int x = v[j].size();
				if(v[i].substr(0, x) == v[j])
					flag = 0;
			}
			if(flag)
				ans -= pow(2, n-v[i].size());
		}
		cout << "Case #" << z << ": " << ans << endl;
	}
 	return 0;
}