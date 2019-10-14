#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int B = 110;
int f[B][B];
int d[B][B][B];

void pre() {
    forn (i, B)
        forn (j, B) {
            if (i || j)
                f[i][j] = 1;
            if (i && j)
                f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
            if (i > 2)
                f[i][j] = max(f[i][j], f[i-3][j] + 1);
            if (j > 2)
                f[i][j] = max(f[i][j], f[i][j-3] + 1);
        }
}

int cnt[5];

int p2() {
    int res = cnt[0];
    res += (cnt[1] + 1) / 2;
    return res;
}

int p3() {
    int a = cnt[1], b = cnt[2];
    int res = f[a][b];
    res += cnt[0];
    return res;
}

int test = 1;
void solve() {
    int n, p;
    cin >> n >> p;
    forn (i, p)
        cnt[i] = 0;
    forn (i, n) {
        int x;
        cin >> x;
        cnt[x % p]++;
    }
    cout << "Case #" << test++ << ": ";
    if (p == 2)
        cout << p2() << '\n';
    else if (p == 3)
        cout << p3() << '\n';
}

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    pre();
    int tn;
    cin >> tn;
    forn (i, tn)
        solve();
}
