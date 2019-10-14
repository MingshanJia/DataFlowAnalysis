#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
double v, d;
const double PI = acos(-1.0);
const double eps = 1e-8;

int main()
{
    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B-small-attempt0.out", "w", stdout);
    int t, ca = 1;
    cin >> t;
    while ( t -- )
    {
        cin >> v >> d;
        double x = d * 9.8 / v / v;
        x = asin(x);
        while ( x < 0 ) x += 2 * PI;
        x *= 0.5;
        printf("Case #%d: %.7f\n", ca ++, x * 180 / (PI));
    }
    return 0;
}
