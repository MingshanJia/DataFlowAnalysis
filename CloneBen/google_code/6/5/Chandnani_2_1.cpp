#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll mod = 1e9+7;
ll f[1000009],inv[1000009];
void pre(){
	f[0] = f[1] = inv[0] = inv[1] = 1;
	repA(i,2,1000000) {
		f[i] = f[i-1]*i%mod;
		inv[i] = (mod - (mod/i)*inv[mod%i]%mod)%mod;
	}
	repA(i,2,1000000){
		inv[i] = inv[i-1]*inv[i]%mod;
	}
	
}
ll C(int n,int r){
	if(r<0||r>n) return 0;
	else return f[n]*inv[r]%mod*inv[n-r]%mod;
}
void solve(){
	int n,m;cin>>n>>m;
	ll ans = f[2*(n)];
	ll pw = 1;
	int x = 2*n;
	repA(i,1,m){
		x--;
		pw=pw*2%mod;
		if(i%2) ans-=C(m,i)*pw%mod*f[x]%mod;
		else ans+=C(m,i)*pw%mod*f[x]%mod;
	}
	cout<<(ans%mod+mod)%mod;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	rep(i,n) cout<<"Case #"<<i+1<<": ",solve(),cout<<"\n";	
	return 0;
}

