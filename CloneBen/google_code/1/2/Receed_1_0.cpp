#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 200001;

void scan(vector<ll> &v) {
    ll a, b, c, md;
    if (v.size() < 2)
        v.emplace_back();
    scanf("%lld%lld%lld%lld%lld%lld", &v[0], &v[1], &a, &b, &c, &md);
    for (int i = 2; i < v.size(); i++)
        v[i] = (a * v[i - 1] + b * v[i - 2] + c) % md;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#else
    //freopen("f.in", "r", stdin); 
    //freopen("f.out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    scanf("%d", &t);
    for (int z = 1; z <= t; z++) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<ll> x(n), y(n), q(m);
        scan(x);
        scan(y);
        scan(q);
        vector<pair<ll, ll>> ql, e;
        for (int i = 0; i < n; i++) {
            e.push_back({min(x[i], y[i]), -1});
            e.push_back({max(x[i], y[i]) + 1, 1});
        }
        for (int i = 0; i < m; i++)
            ql.push_back({q[i] + 1, i + 1});
        sort(ql.begin(), ql.end());
        sort(e.rbegin(), e.rend());
        ll ans = 0, pos = 0, cc = 0, lc = 0, lb = 0, ca;
        for (auto pp : ql) {
            while (pos < e.size() && lc + cc * (lb - e[pos].first) < pp.first) {
                lc += (lb - e[pos].first) * cc;
                lb = e[pos].first;
                cc += e[pos].second;
                pos++;
            }
            if (pos == e.size())
                ca = 0;
            else
                ca = lb + 1 - (pp.first - lc + cc - 1) / cc;
            ans += pp.second * ca;
            //cout << ca << '\n';
        }
        printf("Case #%d: %lld\n", z, ans);
        fflush(stdout);
    }
}
