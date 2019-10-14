// Nurbakyt Madibek or just NICK
// Look at my code! IT'S AWESOME

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <bitset>
#include <unordered_set>

using namespace std;

#define pb push_back
#define pp pop_back
#define f first
#define s second
#define mp make_pair
#define sz(a) (int)((a).size())
#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif
#define fname "."

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pi;
typedef pair < int, ull > pu;
typedef pair < ll, ll > pl;

const int inf = (int)1e9 + 123;
const int MAX_N = (int)4e5 + 123;

int n, q;
int l[MAX_N], r[MAX_N], k[MAX_N];
int x[MAX_N], y[MAX_N], z[MAX_N], a[5], b[5], c[5], m[5];

ll cnt(int x) {
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if (x > r[i])
            continue;
        else if (x >= l[i])
            res += (r[i] - x + 1);
        else
            res += (r[i] - l[i] + 1);
    }
    return res;
}

int findKth(int k) {
    int l = 0, r = (int)1e9, mid = -1, best = 0;
    while(l <= r) {
        mid = (l + r) / 2;
        if (cnt(mid) >= k) {
            best = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return best;
}

void solve(int testId) {
    scanf("%d%d", &n, &q);
    scanf("%d%d%d%d%d%d", &x[1], &x[2], &a[1], &b[1], &c[1], &m[1]);
    scanf("%d%d%d%d%d%d", &y[1], &y[2], &a[2], &b[2], &c[2], &m[2]);
    scanf("%d%d%d%d%d%d", &z[1], &z[2], &a[3], &b[3], &c[3], &m[3]);
    
    for (int i = 1; i <= n; i++) {
        if (i > 2) {
            x[i] = (1ll * a[1] * x[i - 1] + 1ll * b[1] * x[i - 2] + 1ll * c[1]) % m[1];
            y[i] = (1ll * a[2] * y[i - 1] + 1ll * b[2] * y[i - 2] + 1ll * c[2]) % m[2];
        }
        l[i] = min(x[i], y[i]) + 1;
        r[i] = max(x[i], y[i]) + 1;
//        cout << l[i] << ' ' << r[i] << endl;
    }
    ll ans = 0;
    for (int i = 1, cur; i <= q; i++) {
        if (i > 2) {
            z[i] = (1ll * a[3] * z[i - 1]+ 1ll * b[3] * z[i - 2] + 1ll * c[3]) % m[3];
        }
        k[i] = z[i] + 1;
        cur = findKth(k[i]);
//        cout << k[i] << " and ans is " << cur << endl;
        ans += 1ll * cur * i;
    }
//    cout << endl;
    printf("Case #%d: %lld\n", testId, ans);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int numberOfTests;
    scanf("%d", &numberOfTests);
    int it = 0;
    while(numberOfTests--) {
        it++;
        solve(it);
    }
    return 0;
}
