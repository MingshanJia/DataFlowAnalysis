#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:64000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
//#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)((x).size()))

#define forn(i, x) for (int i = 0; i < int(x); i++)
#define fors(i, x) forn(i, sz(x))

template<typename T> T sqr(T x) { return x * x;            }
template<typename T> T abs(T x) { return (x > 0) ? x : -x; }

bool g[1500][1500];
bool was[1500];

ll gcd(ll a, ll b)
{
	if (a) return gcd(b % a, a);
	return b;
}

void dfs(int a, int b, int x)
{
	was[x] = true;
	for (int i = a; i <= b; i++)
	{
		if (!g[x][i]) continue;
		if (was[i]) continue;
		dfs(a, b, i);
	}
}

bool check(int a, int b, int p)
{
	int d = gcd(a, b);
	for (int i = 2; i * i <= d; i++)
	{
		if (d % i == 0)
		{
			if (i >= p) return true;
			while (d % i == 0) d /= i;
		}
	}
	if (d >= p) return true;
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int nt;
	cin >> nt;
	forn(it, nt)
	{
		ll a, b, p;
		cin >> a >> b >> p;
		memset(g, 0, sizeof(g));
		for (int i = a; i <= b; i++)
			for (int j = a; j < i; j++)
				if (check(i, j, p))
					g[i][j] = g[j][i] = true;		
		int ans = 0;
		memset(was, 0, sizeof(was));
		for (int i = a; i <= b; i++)
		{
			if (was[i]) continue;
			ans++;
			dfs(a, b, i);
		}
		cout << "Case #" << (it + 1) << ": " << ans << "\n";
	}
	return 0;
}
