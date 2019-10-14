#include <vector>
#include<cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <set>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <cassert>
#endif
#include <ctime>
#include <queue>
#include <stack>
#include<iomanip>
#include <sstream>
#include <cmath>
using namespace std;
typedef pair<int, int> PII;
typedef unsigned long long ll;

void dfs(int idx, int n, vector<int>& d, vector<int>& mark, ll a, ll b) {
    while (idx < n && mark[idx] == 1) idx ++;
    if (idx == n) return;
    ll c = 1LL << d[idx];
    if (c <= a && c <= b) {
        mark[idx] = 1;
        dfs(idx + 1, n, d, mark, max(b - c, c), min(b - c, c));
        dfs(idx + 1, n, d, mark, max(a - c, b), min(a - c, b));
    } else {
        dfs(idx + 1, n, d, mark, a, b);
    }
}

int check(int x, ll m, vector<int>& d) {
    int n = d.size();
    vector<int> mark(n, 0);
    for(int i = 0; i < x; i ++) {
        dfs(0, n, d, mark, m,  m);
    }
    for(int i = 0; i < n; i ++) {
        if (mark[i] == 0) {
            return 0;
        }
    }
    return 1;
}
void solve(int ncase) {
    int n;
    ll m;
    cin >> n >> m;
    vector<int> d(n);
    for(int i = 0; i < n; i ++) cin >> d[i];
    sort(d.begin(), d.end(), greater<int>());
    int l = 0, r = n;
    while(l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid, m, d)) r = mid;
        else l = mid;
    }
    cout << "Case #" << ncase << ": " << r << endl;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << setprecision(16) << endl;
#ifdef _zzz_
   freopen("D-large.in", "r", stdin);
   freopen("out.txt", "w", stdout);
#endif
    int T = 1;
    //scanf("%d", &T);
    cin >> T;
    int ncase = 0;
    while(T --) {
        solve(++ ncase);
    }
}
