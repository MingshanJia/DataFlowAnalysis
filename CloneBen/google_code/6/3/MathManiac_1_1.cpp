#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long double ld;
typedef long long int LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define Sync_Off ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
#define X first
#define Y second
#define trace(x) cout << #x" is " << (x) << endl
#define trace2(x,y) cout << #x" is " << (x) << ","#y" is " << (y) << endl

LL MOD = 1000000007;
LL powM(LL x,LL n){
	LL y=1;
	for( ; n!=0 ; x=(x*x)%MOD , n/=2) if(n&1) y = (y*x)%MOD;
	return y;
}
inline LL inv(LL x){ return powM(x,MOD-2); }
inline LL mul(LL x,LL y){ return (x*y)%MOD; }
inline LL divd(LL x,LL y){ return (x*inv(y))%MOD; }

int main(){
	Sync_Off
	int t; cin >> t;
	int cas=1;
	while(t--){
		cout << "Case #" << (cas++) << ": ";
		int n; cin >> n;
		string s; cin >> s;
		vector<LL> dig(n+1,0);
		for(int i=1 ; i<=n ; i++) dig[i] = (s[i-1]-'0');
		vector<LL> pref(n+1,0);
		for(int i=1 ; i<=n ; i++) pref[i] = pref[i-1]+dig[i];
		int w = (n+1)/2;
		LL res = 0;
		for(int i=w ; i<=n ; i++) res = max(res,pref[i]-pref[i-w]);
		cout << res << "\n";
	}
}
