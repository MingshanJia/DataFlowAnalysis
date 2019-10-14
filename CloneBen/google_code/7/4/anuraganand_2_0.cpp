#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef vector <int> vi;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define forn(i, a, b) for(int i = (a); i < (b); ++i)
#define ford(i, a, b) for(int i = (a); i >= (b); --i)
#define fore(i, a, b) forn(i, a, b + 1)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define fill(a, v) memset(a, v, sizeof(a))
#define sz(a) ((int)a.size())

#define gl(x) cin >> x
#define gi(x) scanf("%d", &x)
#define pls(x) cout << x << " "
#define pln(x) cout << x << "\n"
#define pis(x) printf("%d ", x)
#define pin(x) printf("%d\n", x)
#define pnl printf("\n")
#define dbn cerr << "\n"
#define dbg(x) cerr << #x << " : " << x << " "
#define dbs(x) cerr << x << " "

#define foreach(c, it) for(__typeof(c.begin()) it = c.begin(); it != c.end(); ++it)

const int N = 10010;
vi adj[N], sorted;
map <string, int> memo;
vector <string> places;
int was[N];

int getHash(string s) {
    if(memo.count(s))
        return memo[s];
    places.pb(s);
    return memo[s] = sz(memo) - 1;
}

void dfs(int u) {
    was[u] = true;
    foreach(adj[u], it) {
        if(!was[*it]) dfs(*it);
    }
    sorted.pb(u);
}

int main() {
    int T; gi(T);
    rep(z, T) {

        places.clear();
        memo.clear();
        sorted.clear();
        rep(i, N) adj[i].clear();

        int n; gi(n);
        rep(i, n) {
            string from, to;
            cin >> from;
            cin >> to;
            int u = getHash(from);
            int v = getHash(to);
            adj[u].pb(v);
        }

        fill(was, 0);
        rep(i, sz(places)) if(!was[i]) dfs(i);
        reverse(all(sorted));

        printf("Case #%d:", z + 1);
        rep(i, sz(sorted) - 1) {
            printf(" ");
            printf("%s-%s", places[sorted[i]].c_str(), places[sorted[i + 1]].c_str());
        }
        pnl;
    }
    return 0;
}