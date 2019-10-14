#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define DOW(i, a, b) for(int i=a; i>=b; i--)
#define FOREACH(it, c) for(typeof(c.begin()) it=c.begin(); it!=c.end(); it++)
#define RESET(c, val) memset(c, val , sizeof(c))
#define base 1000000007

long long f[200][200];
int n, test, m;

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> test;
    FOR(t, 1, test) {
        cin >> m >> n;
        RESET(f, 0);
        f[0][0]=1;
        FOR(i, 1, n) FOR(j, 1, m) {
            f[i][j] = (f[i-1][j] * j + f[i-1][j-1]*(m-j+1)) % base;
        }
        printf("Case #%d: %lld\n", t, f[n][m]);
    }
    return 0;
}
