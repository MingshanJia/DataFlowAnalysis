#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

string gen(int n, string top)
{
	if (n == 0)
		return top;
	vector <string> a;
	if (top == "R")
		a = {gen(n - 1, "R"), gen(n - 1, "S") };
	else if (top == "S")
		a = {gen(n - 1, "S"), gen(n - 1, "P") };
	else if (top == "P")
		a = {gen(n - 1, "P"), gen(n - 1, "R") };
	sort(a.begin(), a.end() );
	return a[0] + a[1];
}

bool good(string s, int R, int P, int S)
{
	for (char c : s)
		if (c == 'R')
			R--;
		else if (c == 'P')
			P--;
		else if (c == 'S')
			S--;
	return R == 0 && P == 0 && S == 0;
}

void solve()
{
	int n;
	scanf("%d", &n);
	int R, P, S;
	scanf("%d%d%d", &R, &P, &S);
	string ans = "Z";
	string cand[3] = {gen(n, "R"), gen(n, "P"), gen(n, "S") };
	for (int i = 0; i < 3; i++)
		if (good(cand[i], R, P, S) )
			ans = min(ans, cand[i] );
	if (ans == "Z")
		ans = "IMPOSSIBLE";
	printf("%s\n", ans.c_str() );
}

void multitest()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("Case #%d: ", i);
		eprintf("Case #%d .. %d\n", i, n);
		solve();
	}


}

int main(int argc, char **)
{
	if (argc == 1)
		multitest();
	else
		solve();

	return 0;
}


