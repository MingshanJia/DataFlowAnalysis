#include<bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define pb push_back
#define ctz __builtin_ctz
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl

constexpr int mod = 1e9 + 7;
constexpr int maxn =  2e5 + 5;
int n,m;

ll fact[maxn], factinv[maxn], pow2[maxn];


ll modpow(ll base,int pow) {
	ll a=base,ans=1;
	while(pow) {
		if(pow&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		pow/=2;
	}
	return ans;
}

inline ll binom(int n,int k) {
	ll intermediate = (fact[n] * factinv[k]) % mod;
	return (intermediate * factinv[n-k]) % mod;
}

ll get(int k) {
	ll a1 = (binom(2*n-k,k) * fact[m]) % mod;
	ll a2 = (a1 * fact[2*(n-k)]) % mod;
	ll a3 = (a2 * factinv[m-k]) % mod;
	return (a3 * pow2[k]) % mod;
}

int main() {
	int tc;
	string s;

	fact[0]=factinv[0]=pow2[0]=1;
	for(int i=1;i<maxn;++i) {
		fact[i]=(fact[i-1]*i) % mod;
		factinv[i]=modpow(fact[i],mod-2);
		pow2[i]=(pow2[i-1]*2)%mod;
	}

	scanf("%d",&tc);
	for(int casenum=1;casenum<=tc;++casenum) {
		scanf("%d%d",&n,&m);
		ll ans = 0;
		for(int i=0;i<=m;++i) {
			ll ways = get(i);
			if(i&1) {
				ans = (ans + mod - ways) % mod;
			} else ans = (ans + ways) % mod;
			//db2(ans,ways);
		}
		printf("Case #%d: %lld\n",casenum,ans);
	}
}

