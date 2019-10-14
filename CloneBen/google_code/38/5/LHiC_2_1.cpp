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
vector<pair<int, int> > eds[1200];
vector<pair<int, int> > beds[1200];
vector<int> geds[1200];
int was[1200][2];
int ad[1200];
int p[1200];
int go[1200];
vector<int> pt[1200];

int df(int a, int b) {
    if (a >= b)
        return a - b;
    else
        return a - b + 24;
}

int get(int a) {
    if (p[a] == a)
        return a;
    return p[a] = get(p[a]);
}

int un(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b)
        return 0;
    p[a] = b;
    return 1;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        eds[i].clear(), beds[i].clear(), geds[i].clear();
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            int e, l, d;
            cin >> e >> l >> d;
            ans += d;
            --e;
            eds[i].push_back(make_pair(e, l));
            geds[i].push_back(beds[e].size());
            beds[e].push_back(make_pair(i, (l + d) % 24));
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            int x11 = df(eds[i][0].second, 0) + df(eds[i][1].second, beds[i][1].second);
            int x12 = df(eds[i][0].second, beds[i][0].second) + df(eds[i][1].second, 0);
            int x21 = df(eds[i][0].second, 0) + df(eds[i][1].second, beds[i][0].second);
            int x22 = df(eds[i][0].second, beds[i][1].second) + df(eds[i][1].second, 0);
            int x1 = min(x11, x12);
            int x2 = min(x21, x22);
            ad[i] = abs(x1 - x2);
            ans += min(x1, x2);
            if (x1 <= x2)
                go[i] = 0;
            else
                go[i] = 1;
        }
        else {
            int x1 = df(eds[i][0].second, beds[i][0].second) + df(eds[i][1].second, beds[i][1].second);
            int x2 = df(eds[i][0].second, beds[i][1].second) + df(eds[i][1].second, beds[i][0].second);
            ad[i] = abs(x1 - x2);
            ans += min(x1, x2);
            if (x1 <= x2)
                go[i] = 0;
            else
                go[i] = 1;
        }
    }
    for (int i = 0; i < n; ++i)
        was[i][0] = was[i][1] = 0, pt[i].clear();
    int cc = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (was[i][j])
                continue;
            int cur = i;
            int nx = j;
            while (was[cur][nx] == 0) {
                pt[cur].push_back(cc);
                was[cur][nx] = 1;
                int tmp = geds[cur][nx];
                cur = eds[cur][nx].first;
                tmp ^= go[cur];
                nx = tmp;
            }
            ++cc;
        }
    }
    for (int i = 0; i < cc; ++i)
        p[i] = i;
    vector<tuple<int, int, int>> ed;
    for (int i = 0; i < n; ++i) {
        if (pt[i].size() < 2) {
            continue;
        }
        ed.push_back(make_tuple(ad[i], pt[i][0], pt[i][1]));
    }
    sort(ed.begin(), ed.end());
    for (int i = 0; i < ed.size(); ++i) {
        int a, b, c;
        tie(c, a, b) = ed[i];
        if (un(a, b))
            ans += c;
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


