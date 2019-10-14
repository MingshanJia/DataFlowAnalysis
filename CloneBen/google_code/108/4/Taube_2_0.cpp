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

const int c = 8;
int n, d;
char s[MAXN][MAXN];
pii p[c] = {
			pii(0, 0),
			pii(0, 2),
			pii(0, 4),
			pii(2, 0),
			pii(2, 4),
			pii(4, 0),
			pii(4, 2),
			pii(4, 4)
};

void init()
{
	scanf ("%d%d", &d, &n);
}

void solve()
{
	init();
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < d; j++)
		{
			s[i][j] = '/';
			if (i % 5 == 2 && j % 5 == 2)
			{
				s[i][j] = 'I';
			}
		}
	}
	for (int i = 0; i < d / 5; i++)
	{
		for (int j = 0; j < d / 5; j++)
		{
			for (int h = 0; h < c; h++)
			{
				if (n)
				{
					int x = i * 5 + p[h].first;
					int y = j * 5 + p[h].second;
					s[x][y] = 'O';
					--n;
				}
			}
		}
	}
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
