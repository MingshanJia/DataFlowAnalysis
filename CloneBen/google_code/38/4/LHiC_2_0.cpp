#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}
int n;
vector<tuple<int, int, int> > eds[1200];
int was[1200][2];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        eds[i].clear();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            int e, l, d;
            cin >> e >> l >> d;
            --e;
            eds[i].push_back(make_tuple(e, l, d));
        }
    }
    int ans = 1e9;
    for (int it = 0; it < (1 << n); ++it) {
        int now = 0;
        int cur = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            was[i][0] = was[i][1] = 0;
        while (true) {
            if (was[cur][0] && was[cur][1]) {
                break;
            }
            else if (was[cur][0]) {
                while (now % 24 != get<1>(eds[cur][1]))
                    ++now;
                was[cur][1] = 1;
                now += get<2>(eds[cur][1]);
                ++cnt;
                cur = get<0>(eds[cur][1]);
            }
            else if (was[cur][1]) {
                while (now % 24 != get<1>(eds[cur][0]))
                    ++now;
                was[cur][0] = 1;
                now += get<2>(eds[cur][0]);
                ++cnt;
                cur = get<0>(eds[cur][0]);
            }
            else {
                if ((it >> cur) & 1) {
                    while (now % 24 != get<1>(eds[cur][0]))
                        ++now;
                    was[cur][0] = 1;
                    now += get<2>(eds[cur][0]);
                    ++cnt;
                    cur = get<0>(eds[cur][0]);
                }
                else {
                    while (now % 24 != get<1>(eds[cur][1]))
                        ++now;
                    was[cur][1] = 1;
                    now += get<2>(eds[cur][1]);
                    ++cnt;
                    cur = get<0>(eds[cur][1]);
                }
            }
        }
        if (cnt == 2 * n) {
            ans = min(ans, now);
        }
    }
    cout << ans << "\n";
}

int main() {
    int tt;
    cin >> tt;
    for (int i = 0; i < tt; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}


