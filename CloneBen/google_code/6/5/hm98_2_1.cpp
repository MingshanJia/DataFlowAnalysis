#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define MOD 1000000007LL
#define INF 1000000000000000018LL
#define F first
#define S second
#define ll long long
#define ld long double
#define eps 1e-9

ll gcd(ll a, ll b)
{
	if(a == 0LL)
		return b;
	if(b == 0LL)
		return a;
	return gcd(b, a%b);
}

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll modx(ll base, ll ex)
{
	ll ans = 1LL, val = base;
	while(ex > 0LL)
	{
		if(ex & 1LL)
			ans = (ans*val)%MOD;
		val = (val*val)%MOD;
		ex = ex>>1LL;
	}
	return ans;
}

const int N = 200005;
ll fact[N], ifact[N], pw2[N];

void pre()
{
	fact[0] = ifact[0] = pw2[0] = 1LL;
	for(int i = 1; i<N; i++)
	{
		pw2[i] = (pw2[i-1]*2)%MOD;
		fact[i] = (fact[i-1]*i)%MOD;
		ifact[i] = modx(fact[i], MOD-2LL);
	}
	return;
}

ll C(int n, int r)
{
	if(n < r)
		return 0LL;
	ll ans = (fact[n]*ifact[r])%MOD;
	ans = (ans*ifact[n-r])%MOD;
	return ans;
}

void solve()
{
	int n, m;
	cin >> n >> m;


	ll ans = 0LL, temp;
	for(int i = 1; i<=m; i++)
	{
		temp = (C(m, i)*pw2[i])%MOD;
		temp = (temp*fact[2*n - i])%MOD;
		if(i&1)
			ans = (ans + temp)%MOD;
		else
			ans = (ans - temp + MOD)%MOD;
	}
	ans = (fact[2*n] - ans + MOD)%MOD;
	cout << ans << "\n";

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	// freopen("in.in", "r", stdin);
	// freopen("out.out", "w", stdout);

	clock_t clk = clock();

	pre();
	
	int t = 1;
	cin >> t;
	for(int tests = 1; tests <= t; tests++)
	{
		cout << "Case #" << tests << ": ";
		solve();
	}

	clk = clock() - clk;
	cerr << "Time Elapsed: " << fixed << setprecision(10) << ((long double)clk)/CLOCKS_PER_SEC << "\n";

	return 0;
}