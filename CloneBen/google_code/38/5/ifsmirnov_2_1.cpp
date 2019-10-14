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
int from[maxn], to[maxn], start[maxn], len[maxn];
vi in[maxn], out[maxn];

int dist(int x, int y) {
    if (y >= x) return y-x;
    return 24-(x-y);
}

int cost(int v, int i, int j) {
    if (v == 0 && i == 0 && j == 0) {
        return 0;
    }
    int idIn = in[v][i];
    int idOut = out[v][j];
    int l = (start[idIn] + len[idIn]) % 24;
    int r = start[idOut];
    return dist(l, r);
}

void scan() {
    cin >> n;
    forn(i, n) in[i].clear(), out[i].clear();
    forn(i, n*2) {
        from[i] = i/2;
        cin >> to[i] >> start[i] >> len[i];
        --to[i];

        in[to[i]].pb(i);
        out[from[i]].pb(i);
    }
}

int firstTotal;

int nc;
int col[maxn];

void go(int id) {
    int Start = id;
    while (true) {
//         cerr << id << endl;
        col[id] = nc;
        int v = to[id];

        int i = 0;
        if (in[v][i] != id) ++i;
        assert(in[v][i] == id);

        int j = i;
        if (col[out[v][j]] != -1) break;

        int nid = out[v][j];
        firstTotal += cost(v, i, j);
        id = nid;
    }
//     cerr << endl;

    assert(id != Start);
    int v = to[id];
    assert(v == from[Start]);
    int i = 0;
    while (in[v][i] != id) ++i;
    assert(in[v][i] == id);
    int j = 0;
    while (out[v][j] != Start) ++j;
    assert(out[v][j] == Start);
    assert(i == j);
    firstTotal += cost(v, i, j);
}

int p[maxn];

int get(int x) { return x == p[x] ? x : (p[x] = get(p[x])); }
bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    p[x] = y;
    return true;
}
int doMst(int n, vector<pair<int, pii>> es) {
    sort(all(es));
    forn(i, n) p[i] = i;
    int rem = n;
    int s = 0;
    for (auto kv: es) {
        assert(kv.se.fi >= 0);
        assert(kv.se.se >= 0);
        assert(kv.se.fi < n);
        assert(kv.se.se < n);
        if (unite(kv.se.fi, kv.se.se)) {
            s += kv.fi;
            --rem;
        }
    }
    if (rem > 1) return 1e9;
    return s;
}

void solve(int tn) {
    forn(i, n) if (i) {
        if (cost(i, 0, 0) + cost(i, 1, 1) > cost(i, 0, 1) + cost(i, 1, 0)) {
            swap(out[i][0], out[i][1]);
        }
    }

    int addition = 0;
    forn(i, n*2) addition += len[i];

    int res = 1e9;

    forn(IIII, 2) {
        forn(III, 2) {
            firstTotal = 0;
            memset(col, -1, sizeof col);
            nc = 0;
            forn(i, n*2) if (col[i] == -1) {
                go(i);
                ++nc;
            }

            vector<pair<int, pii>> es;
            forn(i, n) if (i) {
                int c1 = col[in[i][0]];
                int c2 = col[in[i][1]];
                if (c1 != c2) {
                    int delta = cost(i, 0, 1) + cost(i, 1, 0) - cost(i, 0, 0) - cost(i, 1, 1);
                    assert(delta >= 0);
                    es.emplace_back(delta, pii{c1, c2});
                }
            }
//             cerr << "first total = " << firstTotal << endl;
//             cerr << "add by first: " << start[out[0][0]] << endl;
            int mst = doMst(nc, es);
//             cerr << "nc: " << nc << endl;
//             cerr << "mst: " << mst << endl;

            res = min(res, firstTotal + mst + start[out[0][0]]);

            swap(out[0][0], out[0][1]);
        }
        swap(in[0][0], in[0][1]);
    }

    assert(res < (int)1e9);

    cout << "Case #" << tn << ": " << res+addition << "\n";
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
