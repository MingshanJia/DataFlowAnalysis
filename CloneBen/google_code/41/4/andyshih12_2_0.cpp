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

void solve() {
    ll hd, ad, hk, ak, b, d;
    cin >> hd >> ad >> hk >> ak >> b >> d;
    ll ans = INF;

    rep(i,0,100) {
        rep(j,0,100) {
            ll numDebuf = i, numBuf = j;
            ll turns = 0;
            ll chd = hd, cad = ad, chk = hk, cak = ak;

            while (numDebuf && turns < 1000) {
                if (chd > cak-d) {
                    cak -= d;
                    chd -= cak;
                    numDebuf--;
                }
                else {
                    chd = hd;
                    chd -= cak;
                }
                turns++;
                //cout << "debuf " << i << " " << j << endl;
            }
            if (turns >= 1000) continue;
            while (numBuf && turns < 1000) {
                if (chd > cak) {
                    cad += b;
                    chd -= cak;
                    numBuf--;
                }
                else {
                    chd = hd;
                    chd -= cak;
                }
                turns++;
                //cout << "buf " << i << " " << j << endl;
            }
            if (turns >= 1000) continue;

            while (chk > 0 && turns < 1000) {
                if (chk <= cad) {
                    turns++;
                    break;
                }
                if (chd > cak) {
                    chk -= cad;
                    chd -= cak;
                }
                else {
                    chd = hd;
                    chd -= cak;
                }
                turns++;
            }
            if (turns >= 1000) continue;

            ans = min(ans, turns);
        }
    }
    if (ans >= 1000) {
        cout << "IMPOSSIBLE" << endl;
    }
    else
        cout << ans << endl;
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