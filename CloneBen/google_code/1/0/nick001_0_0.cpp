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
const int MAX_N = (int)2e5 + 123;

int n;
int a[MAX_N];
int cnt[MAX_N];

void solve(int testId) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    ll shit = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
                if (1ll * a[i] * a[j] == (ll)a[k] || 1ll * a[i] * a[k] == (ll)a[j] || 1ll * a[j] * a[k] == (ll)a[i])
                    shit++;
    ll ans = 0;
    int x, y, z;
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]--;
        for (int j = i + 1; j <= n; j++) {
            cnt[a[j]]--;
            x = (1ll * a[i] * a[j] <= (ll)2e5 ? a[i] * a[j] : -1);
            y = (a[j] != 0 && a[i] % a[j] == 0 ? a[i] / a[j] : -2);
            z = (a[i] != 0 && a[j] % a[i] == 0 ? a[j] / a[i] : -3);
            if (x >= 0)
                ans += cnt[x];
            if (y != x && y >= 0)
                ans += cnt[y];
            if (z != y && z != x && z >= 0)
                ans += cnt[z];
        }
        for (int j = i + 1; j <= n; j++)
            cnt[a[j]]++;
    }
//    assert(shit == ans);
    printf("Case #%d: %lld\n", testId, shit);
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
