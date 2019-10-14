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

const int maxn = 2020;

int n, m;
vector<pii> e[maxn];
int val[maxn];
set<pii> special;
int b[maxn];
int used[maxn];

void scan() {
    cin >> n >> m;
    forn(i, n) e[i].clear();
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        e[--u].pb({i,--v});
        e[v].pb({~i,u});
    }
    fill(val, val+m, 0);
    memset(used, 0, sizeof used);
}

void inc(int x) {
    if (x >= 0) ++val[x];
    else --val[~x];
}

int mabs(int x) {
    if (x >= 0) return x;
    return ~x;
}

vi sv;
vi st;
void dfs(int v) {
    sv.pb(v);
    b[v] = 1;
    for (auto kv: e[v]) {
        int to, id;
        tie(id, to) = kv;
        if (used[mabs(id)]) continue;
        used[mabs(id)] = 1;
        if (!b[to]) {
            st.pb(id);
            dfs(to);
            st.pop_back();
        } else {
            int i = st.size() - 1;
            while (true) {
                inc(st[i]);
                if (sv[i] == to) break;
                --i;
                assert(i >= 0);
            }
            inc(id);
        }
    }
    sv.pop_back();
}

void solve(int tn) {
    memset(b, 0, sizeof b);
    forn(i, n) if (!b[i]) dfs(i);
    cout << "Case #" << tn << ":";
    if (count(val, val+m, 0)) {
        cout << " IMPOSSIBLE\n";
        return;
    }
    forn(i, m) cout << " " << val[i];
    cout << "\n";
}

int main() {
#ifdef LOCAL
//     freopen("b.in", "r", stdin);
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
