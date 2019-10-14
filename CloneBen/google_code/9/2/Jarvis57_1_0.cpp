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

double f[405][400*250];
int n, test, l, lv[400*250], L, N;
double b, res;
vector<int> v[400*250];

void cal(int l, int n) {
    if (f[l][n] > -0.5) return;
    if (l == 1) {
        f[l][n] = b;
        if (l==L && n==N) 
            res = min(1.0, f[l][n]);        
        f[l][n] = max(0.0, b-1);
        return;
    }
    f[l][n] = 0; 
    FOREACH(u, v[n]) 
        if (lv[*u] < l) {
            cal(l-1, *u);
            f[l][n] += f[l-1][*u] / 3;
        }
    if (l==L && n==N) 
        res = min(1.0, f[l][n]);
    f[l][n] = max(0.0, f[l][n] - 1);
    return ;
}
int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    int cc = 1, k;
    lv[0] = 0; lv[1] = 1; v[1].push_back(1);
    FOR(i, 2, 400) {
        k = cc - (i-1);
        FOR(j, 1, i) {
            lv[++cc] = i; 
            if (lv[k]+1   == lv[cc]) v[cc].push_back(k);
            if (lv[k+1]+1 == lv[cc]) v[cc].push_back(k+1);
            v[cc].push_back(cc);
            k ++;
        }
    }

    cin >> test;
    FOR(t, 1, test) {
        cin >> b >> l >> n; b*=3; 
        N = n, L = l;
        FOR(i, 0, l) FOR(j, 0, n) 
            f[i][j] = -1;
        cal(l, n);
        printf("Case #%d: %.9lf\n", t, res*250);
    }
    return 0;
}
