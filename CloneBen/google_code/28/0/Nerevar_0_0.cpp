#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>

using namespace std;

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define VI vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define all(v) v.begin(), v.end()

#define NMAX 2005

int c[NMAX][NMAX];

string ans[3] = {"UNKNOWN", "WHITE", "BLACK"};

int calc(int w, int b)
{
	if (w == 1 && b == 0) return 1;
	if (w == 0 && b == 1) return 2;
	if (c[w][b] != -1) return c[w][b];
//	c[w][b] = 0;
	bool p[3];
	p[0] = p[1] = p[2] = false;
	if (w > 0 && b > 0)
	{
		p[calc(w - 1, b)] = true;
	}
	if (w > 1)
	{
		p[calc(w - 1, b)] = true;
	}
	if (b > 1)
	{
		p[calc(w + 1, b - 2)] = true;
	}
	if (p[0]) return (c[w][b] = 0);
	if (p[1] && p[2]) return (c[w][b] = 0);
	if (p[1]) return (c[w][b] = 1);
	return c[w][b] = 2;
}

void solve(int tc)
{
	cerr << tc << endl;
	int w, b;
	scanf("%d %d", &w, &b);
	printf("Case #%d: %s\n", tc, ans[calc(w, b)].c_str());		
}

int main()
{
	freopen(CIN_FILE, "rt", stdin);
	freopen(COUT_FILE, "wt", stdout);
	memset(c, 255, sizeof(c));
	int tc;
	cin >> tc;
	forn(it, tc) solve(it + 1);
	return 0;
}
         	
