/*input
5
2 1
2 2
3 1
3 2
10 5
*/

// Nihesh Anderson - knandy

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
ll MOD=1000000007;

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char *name, Arg1 &&arg1) {
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

#else
#define trace(...)
#endif // ifndef ONLINE_JUDGE

#define fast_cin() ios_base::sync_with_stdio(false)
#define pb push_back
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define debug1(x) cerr << x << endl;
#define debug2(x,y) cerr << x << " " << y << endl;
#define debug3(x,y,z) cerr << x << " " << y << " " << z << endl;
#define FOR(i, a, b) for (ll i=a; i<(b); i++)
#define FORR(i, a, b) for (ll i=a; i>=(b); i--)
ll INF = 2000000000000000001;
double EPS = 1e-9;
ll nextInt(){ll inp; cin>>inp; return inp;}
string nextStr(){string inp; cin>>inp; return inp;}
double nextDouble(){double inp; cin>>inp; return inp;}
ll power(ll a, ll n, ll md){if(n==0){return 1;}else{ll res=power(a,n/2,md);res=(res*res)%md;if(n%2!=0){res=(res*a)%md;}return res;}}
random_device rndm;
mt19937 grndm(rndm());
void mix(ll* a, ll* b){shuffle(a,b,grndm);}

ll fact[200005];

ll nCr(ll a, ll b){
	return (fact[a]*((power(fact[a-b],MOD-2,MOD)*power(fact[b],MOD-2,MOD))%MOD))%MOD;
}

ll nPr(ll a, ll b){
	return (fact[a]*power(fact[a-b],MOD-2,MOD))%MOD;
}

void solve(ll id){
	ll n,m; cin>>n>>m;
	ll ans = fact[2*n];
	FOR(i,1,m+1){
		if(i%2){
			ans = (ans - ((fact[2*n-2*i]*((((nPr(m,i)*nCr(2*n-i,i))%MOD)*power(2,i,MOD))%MOD))%MOD) + MOD)%MOD;
		}
		else{
			ans = (ans+ ((fact[2*n-2*i]*((((nPr(m,i)*nCr(2*n-i,i))%MOD)*power(2,i,MOD))%MOD))%MOD))%MOD;
		}
	}
	cout<<"Case #"<<id<<": "<<ans<<endl;
}

int main(){
	fast_cin();
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
	ll t; cin>>t;
	fact[0] = 1;
	FOR(i,1,200005){
		fact[i] = (i*fact[i-1])%MOD;
	}
	FOR(i,0,t) solve(i+1);
	return 0;
}