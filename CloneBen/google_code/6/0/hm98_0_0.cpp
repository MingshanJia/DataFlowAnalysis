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

const int N = 20005;
vector<int> v;
ll ans[N];
int adj[2][N];
bool mark[N];
int node_cnt;

void insert(int node, int pos)
{
	if(pos == v.size())
	{
		mark[node] = true;
		return;
	}
	if(adj[v[pos]][node] == 0)
	{
		node_cnt++;
		adj[v[pos]][node] = node_cnt;
	}
	insert(adj[v[pos]][node], pos+1);

	return;
}

void calc(int node, int d, int n)
{
	ans[node] = 0;
	for(int i = 0; i<2; i++)
	{
		if(!mark[node])
		{
			if(adj[i][node] == 0)
				ans[node] += (1LL<<(n - d - 1));
			else
			{
				calc(adj[i][node], d+1, n);
				ans[node] += ans[adj[i][node]];
			}
		}
	}
	return;
}

void solve()
{
	memset(adj, 0, sizeof(adj));
	memset(mark, false, sizeof(mark));

	int n, m;
	string s;
	cin >> n >> m;
	node_cnt = 0;
	for(int i = 1; i<=m; i++)
	{
		cin >> s;
		v.clear();
		for(int j = 0; j<s.size(); j++)
		{
			if(s[j] == 'B')
				v.pb(0);
			else
				v.pb(1);
		}
		insert(0, 0);
	}
	calc(0, 0, n);
	cout << ans[0] << "\n";

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