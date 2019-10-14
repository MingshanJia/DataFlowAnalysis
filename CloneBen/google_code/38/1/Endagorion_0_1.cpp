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

map<vi, i64> cnt;

i64 fact[10];

vi step(vi v) {
    int l = v.size();
    vi u(l);
    for (int x: v) if (x) ++u[x - 1];
    return u;
}

i64 weight(vi v) {
    int l = v.size();
    i64 ans = fact[l];
    for (int x: v) ans /= fact[x], l -= x;
    ans /= fact[l];
    if (v == step(v)) --ans;
    return ans;
}

void process(vi v) {
    set<vi> vis;
/*    cerr << "From: ";
    for (int x: v) cerr << x << ' ' ;
    cerr << '\n';*/
    i64 w = weight(v);
    while (!vis.count(v)) {
//        for (int x: v) cerr << x << ' ' ;
//        cerr << '\n';
        cnt[v] += w;
        vis.insert(v);
        v = step(v);
    }
}

void rec(int l, int i, int s, vi &v) {
    if (i == l) {
//        for (int x: v) cerr << x << ' ' ;
//        cerr << '\n';
        process(v);
        return;
    }
    forn(j, l + 1 - s) {
        v[i] = j;
        rec(l, i + 1, s + j, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    fact[0] = 1;
    for1(i, 9) fact[i] = i * fact[i - 1];

    for1(l, 9) {
        vi v(l);
        rec(l, 0, 0, v);
    }

    int t;
    cin >> t;
    for1(tc, t) {
        string s;
        cin >> s;
        int l = s.size();
        vi v(l);
        forn(i, l) v[i] = s[i] - '0';
        int ans = 1;
        if (cnt.count(v)) ans += cnt[v];
        cout << "Case #" << tc << ": " << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
