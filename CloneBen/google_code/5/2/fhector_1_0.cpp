#include <cstdio>
#include <cmath>
#define PI 3.1415926

int main()
{
#define LOCAL
#ifdef LOCAL
    //freopen("in", "r", stdin);
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++)
    {
        int v, d;
        scanf("%d%d", &v, &d);
        double t = (d*9.8) / (2*v*v);
        double angle = asin(2*t);
        double ans = angle / PI * 180 / 2;
        printf("Case #%d: %.7lf\n",kase, ans);
    }
    return 0;
}
