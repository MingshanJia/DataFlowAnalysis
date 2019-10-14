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

const int N = 5000005;
int A[N], pre[N];

void solve()
{
	int n;
	cin >> n;
	char c;
	for(int i = 1; i<=n; i++)
	{
		cin >> c;
		A[i] = c - '0';
		pre[i] = pre[i-1] + A[i];
	}
	int ans = 0, sz;
	if(n%2)
		sz = (n+1)/2;
	else
		sz = n/2;
	for(int i = sz; i<=n; i++)
		ans = max(ans, pre[i] - pre[i-sz]);
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