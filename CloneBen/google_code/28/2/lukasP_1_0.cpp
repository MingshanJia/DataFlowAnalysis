#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <bitset>
#include <utility>
#include <list>
#include <numeric>

#include <cstdio>
#include <cmath>
#include <cctype>
using namespace std;

#define REP(i,n) for(__typeof(n) i=0; i<(n); ++i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

typedef long long ll;
typedef pair<int, int> PI;
template <class T> void zlepsi(T &a, T b)
{
    a = max(a, b);
}
template <class T> void zlepsiMin(T &a, T b)
{
    a = min(a, b);
}
int main() {
    int t; scanf("%d", &t);
    REP(sd,t)
    {
        int k, n; scanf("%d %d", &n, &k);
        int a[15], b[15];
        REP(i,n) scanf("%d %d", &a[i], &b[i]);

        int s = 1 << n;
        int h[k+1][s];
        REP(i,k+1) REP(j,s) h[i][j] = 1234567890;

        h[0][0] = 0;
        int res = 1234567890;
        REP(j,s) REP(e,k)
        {
            for (int l = j; l > 0; l = (l-1)&j)
            {
                bitset<16> c(l);
                int x[2] = {1234567890, 0},
                    y[2] = {1234567890, 0};
                REP(i,n) if (c[i])
                {
                    zlepsiMin(x[0], a[i]);
                    zlepsi(x[1], a[i]);
                    zlepsiMin(y[0], b[i]);
                    zlepsi(y[1], b[i]);
                }
                int q = max(x[1] - x[0], y[1] - y[0]);
                int w = (j^l)&j;
                zlepsiMin(h[e+1][j], max(h[e][w], q));
            }
            if (j == s - 1)
                zlepsiMin(res, h[e+1][j]);
        }


        printf("Case #%d: %d\n", sd+1, res);
    }
}
