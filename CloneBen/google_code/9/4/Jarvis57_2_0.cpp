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

int test, n, a[1000], res, k;
bool ok[1000];

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> test;
    FOR(t, 1, test) {
        cin >> n >> k;
        RESET(ok, true);
        FOR(i, 1, n) {
            cin >> a[i];
            int flag = 0;
            DOW(j, i-1, 1) {
                if (ok[j] && a[i]==a[j]) 
                    flag ++;
                if (ok[j] && a[i]!=a[j])
                    break;
            }
            if (flag >= 2) {
                DOW(j, i-1, 1) {
                    if (ok[j] && a[i]==a[j]) 
                        flag --, ok[j] = false;
                    if (flag == 0) break;
                }
                ok[i] = false;
            }
        }
        res = 0;
        FOR(i, 1, n) res += ok[i];
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
