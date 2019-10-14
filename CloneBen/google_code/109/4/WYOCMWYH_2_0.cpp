#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

void Solve(int test_num) {
    printf("Case #%d:", test_num);
    int c, v, l;
    scanf("%d%d%d", &c, &v, &l);
    ll nc = c, nv = v;
    for (int i = 1; i < l; ++i) {
        ll n_c = (nv * c) % mod;
        nv = ((nc + nv) * v) % mod;
        nc = n_c;
    }
    printf(" %lld\n", nv); 

}
    
int main() {
    freopen("c.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; ++i) Solve(i + 1);
}
