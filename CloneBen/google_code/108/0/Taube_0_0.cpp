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

const int MAXN = 105;

int f, s;
bool used[MAXN][MAXN];
pii p[MAXN];

void init()
{
	scanf ("%d%d", &f, &s);
	for (int i = 1; i <= f; i++)
	{
		scanf ("%d%d", &p[i].first, &p[i].second);
	}
}

void solve()
{
	init();
	int ans = 0;
	for (int i = 1; i <= s; i++)
	{
		memset(used[i], 0, sizeof(used[i]));
		int res = 0;
		for (int j = 1; j <= f; j++)
		{
			pii q = p[j];
			if (q.first == i && !used[q.first][q.second])
			{
				used[q.first][q.second] = true;
				res++;
			}
			else if (q.second == i && !used[q.second][q.first])
			{
				used[q.second][q.first] = true;
				res++;
			}
		}
		ans = max(ans, res);
	}
	printf("Case #%d: %d\n", t, ans);
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
