#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cassert>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <cmath>
#include <bitset>
#include <climits>
#include <iomanip>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <cstring>
#include <numeric>

using namespace std;

#define ll long long
#define N (ll)(1e6+3)
#define INF (ll)(1e18+1)
#define EPS (1e-8)
#define PI (3.14159265358979323846)
#define ld double
#define MOD (ll)(1e9+7)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pdd pair<ld,ld>
#define fi first
#define se second
#define rep(i,a,n) for (ll i = a; i<n; i++)
#define per(i,a,n) for (ll i = n-1; i>=a; i--)
#define pb push_back

char g[50][50], g2[50][50];

void solve() {
    cout << endl;
    ll r, c;
    cin >> r >> c;
    rep(i,0,r) {
        rep(j,0,c) {
            cin >> g[i][j];
            g2[i][j] = g[i][j];
        }
    }

    rep(j,0,c) {
        rep(i,0,r) {
            if (i && g2[i][j] == '?') {
                g2[i][j] = g2[i-1][j];
            }
        }
    }
    rep(j,0,c) {
        per(i,0,r) {
            if (i+1<r && g2[i][j] == '?') {
                g2[i][j] = g2[i+1][j];
            }
        }
    }

    rep(i,0,r) {
        rep(j,0,c) {
            if (j && g2[i][j] == '?') {
                g2[i][j] = g2[i][j-1];
            }
        }
    }

    rep(i,0,r) {
        per(j,0,c) {
            if (j+1<c && g2[i][j] == '?') {
                g2[i][j] = g2[i][j+1];
            }
        }
    }

    rep(i,0,r) {
        rep(j,0,c) {
            cout << g2[i][j];
        }
        cout << endl;
    }


}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    rep(i,0,t) {
       cout << "Case #" << i+1 << ": ";
       solve();
    }
}