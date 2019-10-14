#pragma comment(linker, "/STACK:256000000")

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <memory.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <random>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;
typedef pair<int64, int> pli;
typedef pair<int, int64> pil;
const int INF = (int)(1e9 + 1e5);
const int64 LINF = (int64)(1e18);
const int64 MX = 100500;
const double EPS = 1e-9;
#define sq(x) ((x)*(x))
#define FAIL() (*(int*)(0))++
#ifdef _MY_DEBUG
#define I64d lld
#endif
const int MOD = 1000000007;
const int ROOT = 700;
const int PRM_ROOT = 5;

int test_num = 0;

struct group
{
    int64 n, e;
};

const int MAXN = 1005;

int n;
group a[MAXN];
int64 ans;

void init()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf ("%lld%lld", &a[i].n, &a[i].e);
    }
}

void solve()
{
    int64 cnt = a[1].n;
    for (int i = 2; i <= n; ++i)
    {
        int64 can = a[i].e * a[i].n;
        cnt -= can;
        if (cnt < 0)
        {
            cnt = 0;
        }
        cnt += a[i].n;
    }
    ans = cnt;
    ans = max(ans, a[n].e + 1);
}

void print_answer()
{
    printf("Case #%d: %lld\n", test_num, ans);
}

void run()
{
#ifdef _MY_DEBUG
    freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
#endif // _MY_DEBUG
    int t = 1; scanf ("%d", &t);
    for (test_num = 1; test_num <= t; ++test_num)
    {
        init();
        solve();
        print_answer();
    }
}
int main()
{
    srand(90);
    ios_base::sync_with_stdio(false); cin.tie(0);
    //test();
    run();
    return 0;
}