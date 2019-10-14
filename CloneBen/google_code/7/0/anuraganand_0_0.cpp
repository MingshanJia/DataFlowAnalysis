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

const int N = 1010;

int a[N][N];

int dx[] = {-1, 0, 0, +1};
int dy[] = {0, -1, +1, 0};

int dp[N][N];

int dfs(int x, int y, int n) {
    int & ret = dp[x][y];
    if(~ret) return ret;
    rep(k, 4) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx >= 0 and nx < n and ny >= 0 and ny < n) {
            if(a[nx][ny] == a[x][y] + 1) return ret = 1 + dfs(nx, ny, n);
        }
    }
    return ret = 1;
}
int main() {
    int T; gi(T);
    rep(z, T) {
        int n; gi(n);
        rep(i, n) rep(j, n) gi(a[i][j]);
        fill(dp, -1);
        int ans = 1, id = 1;
        rep(i, n) rep(j, n) {
            int cur = dfs(i, j, n);
            if(ans < cur) {
                ans = cur;
                id = a[i][j];
            } else if(ans == cur) {
                if(a[i][j] < id) id = a[i][j];
            }
        }
        printf("Case #%d: %d %d\n", z + 1, id, ans);
    }
    return 0;
}