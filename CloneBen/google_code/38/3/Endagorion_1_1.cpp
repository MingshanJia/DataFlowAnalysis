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

const int maxn = 1100, maxm = 5100;

vector<pii> es;
vi e[maxn];
vi cover[maxm];
int vis[maxn];

void addEdge(int x, int y) {
    e[x].pb(es.size());
    es.pb({x, y});
}

int forb = -1;

bool dfs(int v, int t, int c) {
    if (v == t) return true;
    if (vis[v]) return false;
    vis[v] = 1; 
    for (int w: e[v]) {
        if (w / 2 == forb) continue;
        if (dfs(es[w].se, t, c)) {
//            cerr << w << ' ';
            cover[w].pb(c);
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    for1(tc, T) {
        cerr << tc << '\n';
        int n, m;
        cin >> n >> m;
        cerr << n << ' ' << m << '\n';
        forn(i, m) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            addEdge(x, y);
            addEdge(y, x);
        }

        forn(i, n) random_shuffle(all(e[i]));

        bool ok = true;

        cout << "Case #" << tc << ": ";

    {
            int cc = 0;
            bool ok = true;
            vi ord;
            forn(i, m) ord.pb(i);
            random_shuffle(all(ord));
            for (int i: ord) {
                if (!cover[2 * i].empty() || !cover[2 * i + 1].empty()) continue;
                forb = i;
                cover[2 * i].pb(cc);
                forn(j, n) vis[j] = 0;
//                cerr << 2 * i << ' ';
                if (!dfs(es[2 * i].se, es[2 * i].fi, cc++)) {
                    ok = false;
                    break;
                }
//                cerr << '\n';
                forb = -1;
            }

            if (!ok) {
                cout << "IMPOSSIBLE\n";
            } else {


            cerr << "finding weights\n";
            int Z = n * n / cc + 100;
            while (1) {
                vi vals(cc);
                forn(i, cc) vals[i] = rand() % (2 * Z + 1) - Z;
                vi totals(m);
                forn(i, 2 * m) {
                    for (int v: cover[i]) totals[i / 2] += vals[v] * (i % 2 ? -1 : 1);
                }
                bool ok = true;
                forn(i, m) {
                    ok &= totals[i] != 0;
                    ok &= abs(totals[i]) <= n * n;
                }

                vi bal(n);
                forn(i, m) {
                    bal[es[2 * i].fi] += totals[i];
                    bal[es[2 * i].se] -= totals[i];
                }

                forn(i, n) assert(bal[i] == 0);

                if (!ok) continue;
                forn(i, m) cout << totals[i] << ' ';
                cout << '\n';
                break;
            }
            }
        }
        forn(i, 2 * m) cover[i].clear();
        forn(i, n) e[i].clear();
        es.clear();
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
