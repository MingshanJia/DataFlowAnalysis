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

const int MAXN = 85;

int n;
double q[MAXN];
double cur[MAXN];

void init()
{
	scanf ("%d", &n);
	for (int i = 1; i <= 2 * n; i++)
	{
		scanf ("%lf", &q[i]);
	}
}

void solve()
{
	init();
	for (int i = 1; i <= n; i++)
	{
		//q[i] = 1.0 - q[i];
	}
	sort (q + 1, q + 2 * n + 1);
	double l = 0.0, r = 1.0, ans;
	for (int it = 0; it < 128; it++)
	{
		double mid = (l + r) / 2.0;
		bool succ = true;
		memcpy(cur, q, sizeof(cur));
		double res = 1;
		for (int i = 1; i <= 2 * n; i++)
		{
			if (cur[i] < 0)
			{
				continue;
			}
			for (int j = 2 * n; j >= 1; j--)
			{
				if (cur[j] < 0)
				{
					continue;
				}
				if (cur[j] * cur[i] <= mid)
				{
					//printf("%d-%d ", i, j);
					res *= (1.0 - cur[i] * cur[j]);
					cur[j] = -1.0;
					cur[i] = -1.0;
					break;
				}
			}
			//printf("\n");
			if (cur[i] >= 0.0)
			{
				succ = false;
				break;
			}
		}
		if (succ)
		{
			//printf("%.7lf %.7lf\n", mid, res);
			r = mid;
			ans = res;
		}
		else
		{
			l = mid;
		}
	}
	printf("Case #%d: %.8lf\n", t, ans);
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
