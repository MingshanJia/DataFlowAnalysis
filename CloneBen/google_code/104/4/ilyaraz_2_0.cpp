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

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int nt;
	cin >> nt;
	forn(it, nt)
	{
		int k, n;
		cin >> k >> n;
		vi d(n);
		forn(i, n) cin >> d[i];
		queue<int> q;
		for (int i = 1; i <= k; i++) q.push(i);
		vi ans(k);
		for (int i = 1; i <= k; i++)
		{
			for (int j = 0; j < i - 1; j++)
			{
				int cur = q.front();
				q.pop();
				q.push(cur);
			}
			int cur = q.front();
			q.pop();
			ans[cur - 1] = i;
		}
		cout << "Case #" << (it + 1) << ": ";
		forn(i, n) cout << ans[d[i] - 1] << " ";
		cout << "\n";
	}
	return 0;
}
