#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define DOW(i, a, b) for(int i=a; i>=b; i--)
#define FOREACH(it, c) for(typeof(c.begin()) it=c.begin(); it!=c.end(); it++)
#define RESET(c, val) memset(c, val , sizeof(c))
#define base 1000000007
#define oo 1000000000000000001LL

int test, n;
long long k, f[205][205];

long long cal(int i, int x) {
    if (x<0) return 0;
    if (f[i][x] != -1) return f[i][x];

    if (i==n+1) {
        f[i][x] = (x==0); 
        return f[i][x];
    }
    f[i][x] = min(oo, cal(i+1, x-1) + cal(i+1, x+1));
    return f[i][x];
}
int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> test;
    FOR(t, 1, test) {
        cin >> n >> k; n*=2;
        RESET(f, -1);
        cal(1, 0);

        printf("Case #%d: ", t);
        if (f[1][0] < k) {
            cout << "Doesn't Exist!" << endl;
        } else {
            int x = 0;
            FOR(i, 1, n) {
                if (f[i+1][x+1] >= k) {
                    x++; printf("(");
                } else {
                    k -= f[i+1][x+1];
                    x--; printf(")");
                }
            }
            cout << endl;
        }
    }
    return 0;
}
