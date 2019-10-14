#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct TEdge {
    int from, to;
    int st, d, fin;
};

const int maxn = 2100;
TEdge es[maxn];
vi ein[maxn], eout[maxn];
int vis[maxn];
int cycle[maxn];

void dfs(int v, int cc) {
    if (vis[v]) return;
    vis[v] = 1;
    cycle[v] = cc;
    int to = es[v].to, i = 0;
    while (ein[to][i] != v) ++i;
    dfs(eout[to][i], cc);
}

int pen(int i, int j) {
    int fi = es[i].fin, fj = es[j].st;
    return (fj - fi + 24) % 24;
}

int par[maxn];

int root(int v) {
    if (par[v] == v) return v;
    return par[v] = root(par[v]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    cin >> t;
    for1(tc, t) {
        int n;
        cin >> n;
        forn(i, 2 * n) {
            int from = i / 2;
            int to, st, d;
            cin >> to >> st >> d;
            --to;
            int fin = (st + d) % 24;
            es[i] = {from, to, st, d, fin};
            eout[from].pb(i);
            ein[to].pb(i);
        }

        int ans = 1e9;
        for1(i, n - 1) {
            if (pen(ein[i][0], eout[i][1]) + pen(ein[i][1], eout[i][0]) < pen(ein[i][0], eout[i][0]) + pen(ein[i][1], eout[i][1])) swap(eout[i][0], eout[i][1]);
        }
        int totald = 0;
        forn(i, 2 * n) totald += es[i].d;

        forn(zin, 2) {
            forn(zout, 2) {
                forn(i, 2 * n) vis[i] = 0;
                int cc = 0;
				int res = es[eout[0][0]].st + totald;
                forn(i, n) forn(j, 2) {
                    if (!i && !j) continue;
                    res += pen(ein[i][j], eout[i][j]);
                }
                forn(i, 2 * n) {
                    if (vis[i]) continue;
                    dfs(i, cc++);
                }
                
                vector< pair<int, pii> > me;
                for1(i, n - 1) {
                    if (cycle[ein[i][0]] == cycle[ein[i][1]]) continue;
                    int add = pen(ein[i][0], eout[i][1]) + pen(ein[i][1], eout[i][0]) - pen(ein[i][0], eout[i][0]) - pen(ein[i][1], eout[i][1]);
                    me.pb({add, {cycle[ein[i][0]], cycle[ein[i][1]]}});
                }
                sort(all(me));
                forn(i, cc) par[i] = i;
                for (auto w: me) {
                    int add = w.fi, x = w.se.fi, y = w.se.se;
                    x = root(x), y = root(y);
                    if (x == y) continue;
                    res += add;
                    par[x] = y;
                }
                uin(ans, res);

                swap(eout[0][0], eout[0][1]);
            }
            swap(ein[0][0], ein[0][1]);
        }
        cout << "Case #" << tc << ": " << ans << '\n';
        
        forn(i, n) ein[i].clear(), eout[i].clear();
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
