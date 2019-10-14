#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<ll, ll>
#define F first
#define S second
const ll N = 5005;
vector<ll> lengths;
// # <= l
ll get(ll l){ return upper_bound(lengths.begin(), lengths.end(), l) - lengths.begin();}
ll C2(ll n){
	return (n * 1ll * (n - 1)) / 2;
}
ll C3(ll n){
	return (n * (n - 1) * (n - 2)) / 6;
}
ll C4(ll n){
	return (n * (n - 1) * (n - 2) * (n - 3)) / 24;
}
map<ll, ll > freq;
set<int> lens;
int main(){
	ll t = 1;
	cin >> t;
	for(ll tt = 1; tt <= t; tt++){
		lengths.clear();
		freq.clear();
		lens.clear();
		ll n, l, ans = 0;
		cin >> n;
		for(ll i = 1; i <= n; i++){
			cin >> l;
			lengths.push_back(l);
			freq[l]++;
			lens.insert(l);
		}
		sort(lengths.begin(), lengths.end());
		for(auto it : freq){
			ll l = it.F, s = it.S;
			if(s >= 2){
				ll cnt = C2(s);
				for(ll x : lengths){
					if(x == l) continue;
					// [x + 1, x + 2 * l - 1]
					ll temp = get(x + 2 * l - 1) - get(x);
					if(l >= x + 1 && l < x + 2 * l)
						temp -= s;
					ans += cnt * temp;
				}
			}
		}
		for(ll l1 : lens){
			if(freq[l1] < 3) continue;
			for(ll l2 : lens){
				if(l1 != l2){
					if( (l1 < l2 && 3 * l1 > l2) || (l1 > l2))
					ans += C3(freq[l1]) * freq[l2];
				}
			}
		}
		/*for(ll l1 : lens)
			for(ll l2 : lens){
				if(l1 < l2) ans += C2(freq[l1]) * C2(freq[l2]);
			}
		for(ll l1 : lens) ans += C4(freq[l1]);*/
		cout << "Case #" << tt << ": " << ans << endl;
	}
}