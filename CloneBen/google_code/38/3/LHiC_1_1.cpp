#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

const int MAXN = 4000;
int gfl = 0;
int hh[MAXN];
int was[MAXN];
int ans[MAXN * 2];
vector<pair<int, int> > eds[MAXN];

int dfs1(int v, int h, int p) {
    hh[v] = h;
    was[v] = 1;
    int up = 0;
    for (auto e: eds[v]) {
        if (e.second == -p)
            continue;
        int u = e.first;
        if (!was[u]) {
            up += dfs1(u, h + 1, e.second);
        }
        else if (hh[u] > hh[v]) {
            up -= 1;
        }
        else {
            if (e.second > 0) {
                ans[e.second - 1] = 1;
            }
            else {
                ans[-e.second - 1] = -1;
            }
            ++up;
        }
    }
    if (p != 0) {
        if (p > 0)
            ans[p - 1] = up;
        else
            ans[-p - 1] = -up;
        if (up == 0)
            gfl = 1;
    }
    return up;
}

int slv(int x) {
    gfl = 0;
    dfs1(x, 0, 0);
    if (gfl)
        return 0;
    return 1;
}
int n, m;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        eds[i].clear();
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        eds[a].push_back(make_pair(b, i + 1));
        eds[b].push_back(make_pair(a, -i - 1));
    }
    memset(was, 0, sizeof(was));
    for (int i = 0; i < n; ++i) {
        if (!was[i]) {
            if (!slv(i)) {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }
    for (int i = 0; i < m; ++i)
        cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    int tt;
    cin >> tt;
    for (int i = 0; i < tt; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}


