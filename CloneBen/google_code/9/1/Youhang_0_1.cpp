#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i ++)
#define mem(s, v) memset(s, v, sizeof(s))
#define sz(v) (int)v.size()
#define pb push_back
#define mp make_pair

int mod = 1e9 + 7;
int m, n;

int table[105][105];

int getres(int p, long long num) {
    if (p == n) {
        if (num == m) return 1;
        else return 0;
    }
    if (table[p][num] >= 0) return table[p][num];
    
    long long res = 0;
    if (num > 0) res += num * getres(p + 1, num);
    if (num < m) res += (m - num) * getres(p + 1, num + 1);
    res %= mod;
    table[p][num] = (int)res;
    return table[p][num];
}

int main() {
    freopen("/Users/youhangtian/Downloads/A-large.in-2.txt", "r", stdin);
    freopen("/Users/youhangtian/Downloads/output.txt", "w", stdout);
    
    int T;
    cin >> T;
    
    for (int ca = 1; ca <= T; ca ++) {
        cin >> m >> n;
        mem(table, -1);
        int res = getres(0, 0);
        cout << "Case #" << ca << ": " << res << endl;
    }
    
    return 0;
}