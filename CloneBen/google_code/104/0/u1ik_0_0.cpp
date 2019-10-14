#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 100000;
long long x[N], y[N];
int n;

void gen(long long A, long long B, long long C, long long D, long long x0, long long y0, long long M)
{
    long long X = x0, Y = y0;
    x[0] = X, y[0] = Y;
    for (int i = 1; i < n; ++i)
    {
      X = (A * X + B) % M;
      Y = (C * Y + D) % M;
      x[i] = X;
      y[i] = Y;
    }
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int TC;
    scanf("%d", &TC);
    for (int cc = 1; cc <= TC; ++cc)
    {
        {
            long long A, B, C, D, x0, y0, M;
            cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;
            gen(A, B, C, D, x0, y0, M);
        }
                
        long long res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                for (int k = j + 1; k < n; ++k)
                {
                    long long xm, ym;
                    
                    xm = x[i] + x[j] + x[k];
                    ym = y[i] + y[j] + y[k];
                    if (xm % 3 != 0 || ym % 3 != 0) continue;
                    xm /= 3, ym /= 3;
                    ++res;
                }
        printf("Case #%d: %I64d\n", cc, res);
    }
    return 0;
}
