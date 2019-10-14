#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

const int maxn = 5050;

int n;
int go[maxn][2], start[maxn][2], len[maxn][2];
int b[maxn][2];

int res;

void scan() {
    cin >> n;
    forn(i, n) forn(j, 2) cin >> go[i][j] >> start[i][j] >> len[i][j], --go[i][j];
}

int dist(int x, int y) {
    if (y >= x) return y-x;
    return 24-(x-y);
}

int cc;
void run(int v, int t, int sum, int cnt) {
    ++cnt;
    if (cnt == n*2+1) {
        res = min(res, sum);
        return;
    }
    forn(i, 2) if (!b[v][i]) {
        b[v][i] = 1;
        int wait = dist(t, start[v][i]);
        assert((t+wait)%24 == start[v][i]);
        run(go[v][i], (t + wait + len[v][i]) % 24, sum + wait, cnt);
        b[v][i] = 0;
    }
}

void solve(int tn) {
    res = 1e9;
//     cc = 0;
    run(0, 0, 0, 0);
//     cerr << cc << endl;
    forn(i, n) forn(j, 2) res += len[i][j];
    cout << "Case #" << tn << ": " << res << endl;
}

int main() {
#ifdef LOCAL
//     freopen("c.in", "r", stdin);
#endif

    int t;
    cin >> t;
    forn(i, t) {
        scan();
        solve(i+1);
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
