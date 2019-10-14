#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 10005
map<string, int> h;
map<int, string> g;
int a[N];
int d[N];
int n, m;

void print(int x)
{
    while (a[x])
    {
        cout << " " << g[x] << "-" << g[a[x]];
        x = a[x];
    }
}

void solve()
{
    cin >> n;
    memset(d, 0, sizeof(d));
    memset(a, 0, sizeof(a));
    m = 0;
    h.clear();
    g.clear();
    for (int i = 0; i < n; ++i)
    {
        string x, y;
        cin >> x >> y;
        if (!h[x])
        {
            h[x] = ++m;
            g[m] = x;
        }
        if (!h[y])
        {
            h[y] = ++m;
            g[m] = y;
        }
        int xx = h[x];
        int yy = h[y];
        a[xx] = yy;
        ++d[yy];
    }
    for (int i = 1; i <= m; ++i)
        if (d[i] == 0)
        {
            print(i);
            break;
        }
    cout << endl;
}

int main()
{
    int t;
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> t;
    for (int tt = 1; tt <= t; ++tt)
    {
        cout <<"Case #" << tt << ":";
        solve();
    }
    return 0;
}