#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const int maxn = 300;


ll a[maxn], ans[maxn];

void Solve(int test_num) {
    int n;
    scanf("%d", &n);
    multiset<ll> x;

    for (int i = 0, j = 0; i < 2 * n; ++i) {
        scanf("%lld", a + i);
        if (x.count(a[i])) {
            x.erase(x.find(a[i]));
        } else {
            assert(a[i] % 3 == 0);
            ans[j++] = a[i];
            x.insert(4 * a[i] / 3);
        }
    }

    printf("Case #%d:", test_num);
    for (int i = 0; i < n; ++i) printf(" %lld", ans[i]);
    printf("\n");
    
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) Solve(i + 1);
}
