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

vector<int> vv[10];
vector<int> ans[10];
ll cnk[30][30];
map<int, int> mm[10];

ll solve() {
    string s;
    cin >> s;
    int l = s.size();
    int x = 0;
    for (int i = 0; i < s.size(); ++i)
        x = x * 10 + s[i] - '0';
    if (mm[l].count(x)) {
        return ans[l][mm[l][x]];
    }
    else {
        return 1;
    }
}

void go(int x, int k, int sm, int now) {
    if (x == k) {
        if (sm > 0 && sm <= 9) {
            vv[k].push_back(now);
        }
        return;
    }
    for (int j = 0; j <= k && sm + j <= 9; ++j)
        go(x + 1, k, sm + j, now * 10 + j);
}

int gets(int a) {
    int x = 0;
    while (a) {
        x += a % 10;
        a /= 10;
    }
    return x;
}

bool cmp(int a, int b) {
    int x = gets(a);
    int y = gets(b);
    if (x != y) {
        return x < y;
    }
    else {
        return a > b;
    }
}
int cc[20];

int get(int x, int k) {
    for (int i = 0; i < 10; ++i)
        cc[i] = 0;
    while (x) {
        ++cc[x % 10];
        x /= 10;
    }
    for (int i = 1; i <= k; ++i) {
        x = x * 10 + cc[i];
    }
    return mm[k][x];
}

int get2(int x, int k) {
    int ans = 1;
    for (int i = k; i >= 1; --i) {
        int c = x % 10;
        x /= 10;
        ans = (ans * cnk[k][c]);
        k -= c;
        if (k < 0)
            break;
    }
    return ans;
}

void init(int k) {
    vv[k].clear();
    go(0, k, 0, 0);
    sort(vv[k].begin(), vv[k].end(), cmp);
    ans[k].resize(vv[k].size());
    for (int i = 0; i < vv[k].size(); ++i)
        mm[k][vv[k][i]] = i;
    for (int i = vv[k].size() - 1; i >= 0; --i) {
        ans[k][i] += get2(vv[k][i], k);
        if (i != 0) {
            ans[k][get(vv[k][i], k)] += ans[k][i];
            ans[k][i] += 1;
        }
    }
}

int main() {
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < 20; ++j) {
            if (i == j || j == 0)
                cnk[i][j] = 1;
            else if (j > i)
                cnk[i][j] = 0;
            else
                cnk[i][j] = cnk[i - 1][j] + cnk[i - 1][j - 1];
        }
    for (int i = 1; i <= 9; ++i) {
        init(i);
    }
    int tt;
    cin >> tt;
    for (int i = 0; i < tt; ++i) {
        printf("Case #%d: %lld\n", i + 1, solve());
    }
    return 0;
}


