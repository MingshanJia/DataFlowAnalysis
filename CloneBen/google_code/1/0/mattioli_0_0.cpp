#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

ll naive(vector<ll> v) {
    int n = (int) v.size();
    ll ans = 0;
    fori(i, 0, n) {
        fori(j, i + 1, n) {
            fori(k, j + 1, n) {
                vector<ll> f {v[i], v[j], v[k]};
                sort(f.begin(), f.end());
                ans += (f[0] * f[1] == f[2]) || (f[1] * f[2] == f[0]) || (f[0] * f[2] == f[1]);
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int kase = 1;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        ll ones = 0;
        ll zeros = 0;
        map<ll, int> cnt;
        fori(i, 0, n) {
            cin >> v[i];
            ones += v[i] == 1;
            zeros += v[i] == 0;
            cnt[v[i]]++;
        }
        map<ll, int> app;
        fori(i, 0, n) {
            fori(j, i + 1, n) {
               if(v[i] <= 1 || v[j] <= 1) {
                   continue;
               }
               app[v[i] * v[j]]++; 
            }
        }
        ll ans = 0;
        fori(i, 0, n) {
            if(v[i] > 1) {
                ans += app[v[i]];
            }
        }
        for(auto &each : cnt) {
            if(each.first <= 1) {
                continue;
            }
            ll c = each.second;
            ans += ((c * (c - 1)) / 2) * ones;
        }
        ans += (1LL * ones * (ones - 1) * (ones - 2)) / 6;
        ll non_zeros = n - zeros;
        ans += ((zeros * (zeros - 1)) / 2) * non_zeros;
        ans += (zeros * (zeros - 1) * (zeros - 2))/ 6;
        cout << "Case #" << kase++ << ": " << ans << '\n';
    }
    return 0;
}
