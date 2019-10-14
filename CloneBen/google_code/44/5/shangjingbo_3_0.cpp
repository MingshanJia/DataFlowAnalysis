#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 25;

vector<int> adj[MAXN + MAXN];
bool mark[MAXN + MAXN];

void flood(int u, int n, int &a, int &b)
{
    if (u < n) {
        ++ a;
    } else {
        ++ b;
    }
    mark[u] = true;
    for (int i = 0; i < adj[u].size(); ++ i) {
        int v = adj[u][i];
        if (!mark[v]) {
            flood(v, n, a, b);
        }
    }
}

int solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n + n; ++ i) {
        adj[i].clear();
    }
    int already = 0;
    for (int i = 0; i < n; ++ i) {
        char s[MAXN + 1];
        scanf("%s", s);
        for (int j = 0; j < n; ++ j) {
            if (s[j] == '1') {
                ++ already;
                adj[i].push_back(n + j);
                adj[n + j].push_back(i);
            }
        }
    }
    int base = 0;
    vector<pair<int, int>> comp;
    memset(mark, false, sizeof(mark));
    for (int i = 0; i < n + n; ++ i) {
        if (!mark[i]) {
            int a = 0, b = 0;
            flood(i, n, a, b);
            if (a == b) {
                base += a * b;
            } else {
//fprintf(stderr, "a = %d, b = %d\n", a, b);
                comp.push_back(make_pair(a, b));
            }
        }
    }
    vector<int> f(1 << comp.size(), n * n);
    f[0] = 0;
    int all = (1 << comp.size()) - 1;
    for (int mask = 0; mask < 1 << comp.size(); ++ mask) {
        int remain = all ^ mask;
        for (int sub = remain; sub > 0; sub = (sub - 1) & remain) {
            int a = 0, b = 0;
            for (int i = 0; i < comp.size(); ++ i) {
                if (sub >> i & 1) {
                    a += comp[i].first;
                    b += comp[i].second;
                }
            }
            if (a == b) {
                f[mask | sub] = min(f[mask | sub], f[mask] + a * b);
            }
        }
    }

    int answer = f[all];

    return base + answer - already;
}

int main()
{
    int test = 1, tests;
    for (scanf("%d", &tests); test <= tests; ++ test) {
        printf("Case #%d: %d\n", test, solve());
    }
    return 0;
}
