/*input
4
3 2
BBB
RB
5 1
R
4 3
R
B
RBRB
50 5
BRBRBBBRBRRRBBB
BRBRBRRRBRRRBRB
BBBRBBBRBRRRBBB
BRBRBRRRBRRRB
BRBRBBBRBBBRB
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

void solve(ll id){
	ll n,p; cin>>n>>p;
	map<string,bool> f;
	map<string,bool> x;
	set<string> v1;
	FOR(i,0,p) v1.insert(nextStr());
	vector<string> v;
	for(string val: v1) v.pb(val);
	sort(v.begin(),v.end(),[](string a, string b){
		return a.size() < b.size();
	}); 
	FOR(i,0,v.size()){
		string s = v[i];
		string now = "";
		bool fail = false;
		FOR(j,0,s.size()){
			now+=s[j];
			if(f[now]){
				fail=true; break;
			}
		}
		if(!fail){
			x[s] = true;
			f[s] = true;
		}
	}
	ll ans = power(2,n,MOD*MOD);
	for(auto val: x){
		ans-=power(2,n-val.first.size(),MOD*MOD);
	}
	cout<<"Case #"<<id<<": "<<ans<<endl;
}

int main(){
	fast_cin();
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
	ll t; cin>>t;
	FOR(i,0,t) solve(i+1);
	return 0;
}