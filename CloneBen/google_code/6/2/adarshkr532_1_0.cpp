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
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out1.txt","w",stdout);
	IOS;
	int t, n;
	string s;
	cin >> t;
	for(int z = 1; z <= t; z++){
		cin >> n >> s;
		int x = n-n/2, sum = 0, mx = 0;
		for(int i = 0; i < x; i++){
			sum += (s[i]-'0');
		}
		mx = sum;
		for(int i = x; i < n; i++){
			sum += (s[i]-'0') - (s[i-x]-'0');
			mx = max(sum, mx);
		}
		cout << "Case #" << z << ": " << mx << endl;
	}
 	return 0;
}