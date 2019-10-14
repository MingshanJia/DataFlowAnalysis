// Nurbakyt Madibek or just NICK
// Look at my code! IT'S AWESOME

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <bitset>
#include <unordered_set>

using namespace std;

#define pb push_back
#define pp pop_back
#define f first
#define s second
#define mp make_pair
#define sz(a) (int)((a).size())
#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif
#define fname "."

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pi;
typedef pair < int, ull > pu;
typedef pair < ll, ll > pl;

const int inf = (int)2e5 + 123;
const int MAX_N = (int)4e5 + 123;

int n, m, e;
pi start, finish;
int v[105][105];

int d[105][105];
set < pair < int, pi > > q;

int moves[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void solve(int testId) {
    scanf("%d %d %d %d %d %d %d", &n, &m, &e, &start.f, &start.s, &finish.f, &finish.s);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &v[i][j]);
            assert(v[i][j] <= 0);
            v[i][j] = 0 - v[i][j];
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            d[i][j] = inf;
        }
    d[start.f][start.s] = 0;
    q.clear();
    q.insert(mp(0, start));
    
    while(!q.empty()) {
        int x = q.begin() -> s.f;
        int y = q.begin() -> s.s;
        q.erase(q.begin());
        for (int i = 0; i < 4; i++) {
            int nx = x + moves[i][0], ny = y + moves[i][1];
            if (nx > 0 && nx <= n && ny > 0 && ny <= m && v[nx][ny] != 100000 && d[nx][ny] > d[x][y] + v[nx][ny]) {
                q.erase(mp(d[nx][ny], mp(nx, ny)));
                d[nx][ny] = d[x][y] + v[nx][ny];
                q.insert(mp(d[nx][ny], mp(nx, ny)));
            }
        }
    }
    int minimumCost = d[finish.f][finish.s];
//    cout << minimumCost << endl;
    int ans = (minimumCost > e ? -1 : e - minimumCost);
    printf("Case #%d: %d\n", testId, ans);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int numberOfTests;
    scanf("%d", &numberOfTests);
    int it = 0;
    while(numberOfTests--) {
        it++;
        solve(it);
    }
    return 0;
}
