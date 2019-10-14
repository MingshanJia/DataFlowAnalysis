#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <memory.h>
#include <sstream>
#include <cassert>
#include <ctime>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;
typedef pair<int64, int> pli;

const int INF = (int)(1e9+1e5);
const int64 LINF = (int64)(4e18);
const double EPS = 1e-10;
const int MOD = (int)1e9 + 7;
#define sq(x) ((x)*(x))
#define FAIL() ((*(int*)0)++)
#define y0 y00

int t;

const int MAXN = 55;

int n, d;
char s[MAXN][MAXN];
vector <pii> v1;
vector <pii> v3;

void init()
{
	scanf ("%d%d", &d, &n);
}

void precalc()
{
	for (int i = 0; i < d; i++)
	{
		char c;
		if (i & 1)
		{
			c = '/';
		}
		else
		{
			if ((i / 2) & 1)
			{
				c = 'I';
			}
			else
			{
				c = 'O';
			}
		}
		for (int j = 0; j < d; j++)
		{
			s[i][j] = c;
		}
	}
	v1.clear();
	v3.clear();
	for (int i = 1; i < d; i += 2)
	{
		v1.push_back(pii(i, 0));
		v1.push_back(pii(i, d - 1));
		for (int j = 1; j < d - 1; j++)
		{
			v3.push_back(pii(i, j));
		}
	}
}

void solve()
{
	init();
	precalc();
	n = 287 - n;
	while (n >= 3 && !v3.empty())
	{
		pii x = v3.back();
		v3.pop_back();
		s[x.first][x.second] = 'I';
		n -= 3;
	}
	while (n >= 1 && !v1.empty())
	{
		pii x = v1.back();
		v1.pop_back();
		s[x.first][x.second] = 'I';
		n--;
	}
	assert(n == 0);
	printf("Case #%d:\n", t);
	for (int i = 0; i < d; i++)
	{
		printf("%s\n", s[i]);
	}
}

int main()
{
	//srand(time(0)); testgen(10, 5, 30);
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef _MY_DEBUG
    freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
#endif
    double st = clock();
    int te = 1;
    scanf ("%d", &te);
    for (t = 1; t <= te; t++)
    {
    	solve();
    }

    //fprintf(stderr, "%.3lf\n", (clock() - st) / CLOCKS_PER_SEC);
    return 0;
}
