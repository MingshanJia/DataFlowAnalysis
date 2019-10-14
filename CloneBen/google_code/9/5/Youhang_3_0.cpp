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

long long table[205][105];
long long nn, kk;

long long get(int n, int n2) {
    if (n2 == nn) return 1;
    
    if (table[n][n2] >= 0) return table[n][n2];
    
    if (n - n2 == n2) table[n][n2] = get(n + 1, n2 + 1);
    else table[n][n2] = get(n + 1, n2 + 1) + get(n + 1, n2);
    
    if (table[n][n2] > 1e18) table[n][n2] = 1e18 + 1;
    return table[n][n2];
}

bool getres(vector<char> &v, int n, int n2, long long k) {
    if (n2 == nn) return (k == 1);
    
    long long num = get(n + 1, n2 + 1);
    
    if (num >= k) {
        v.pb('(');
        return getres(v, n + 1, n2 + 1, k);
    }
    else {
        v.pb(')');
        return getres(v, n + 1, n2, k - num);
    }
}

int main() {
    freopen("/Users/youhangtian/Downloads/D-small-attempt0.in.txt", "r", stdin);
    freopen("/Users/youhangtian/Downloads/output.txt", "w", stdout);
    
    int T;
    cin >> T;

    for (int ca = 1; ca <= T; ca ++) {
        cin >> nn >> kk;
        
        mem(table, -1);
        vector<char> v;
        bool res = getres(v, 0, 0, kk);
        
        int count = 0;
        rep(i, sz(v)) {
            if (v[i] == '(') count ++;
            else count --;
            if (count < 0) res = false;
        }
        
        cout << "Case #" << ca << ": ";
        if (res) {
            for (char c: v) cout << c;
            rep(i, count) cout << ')';
            cout << endl;
        }
        else cout << "Doesn't Exist!" << endl;
    }
    
    return 0;
}