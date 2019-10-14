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
        ll n, x, ans = 0, c0 = 0, c1 = 0;
        scanf("%lld", &n);
        map<ll, ll> m;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &x);
            if (x == 0)
                c0++;
            else if (x == 1)
                c1++;
            else
                m[x]++;
        }
        ans = c0 * (c0 - 1) / 2 * (n - c0) + c0 * (c0 - 1) * (c0 - 2) / 6 + c1 * (c1 - 1) * (c1 - 2) / 6;
        for (auto &p1 : m) {
            if (m.count(p1.first * p1.first))
                ans += p1.second * (p1.second - 1) / 2 * m[p1.first * p1.first];
            ans += c1 * p1.second * (p1.second - 1) / 2;
            for (auto &p2 : m) {
                if (p2.first >= p1.first || p1.first * p2.first > N)
                    break;
                if (m.count(p1.first * p2.first))
                    ans += p1.second * p2.second * m[p1.first * p2.first];
            }
        }
        printf("Case #%d: %lld\n", z, ans);
    }
}
