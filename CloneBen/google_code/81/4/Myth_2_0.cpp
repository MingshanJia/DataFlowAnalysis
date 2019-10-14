#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100;

int t1, n, m, c[maxn], s[maxn], t[maxn];
bool v[maxn];

bool cmp(int a, int b)
{
    return s[a] > s[b];
}

int main()
{
    freopen("c1.in", "r", stdin);
    freopen("c1.out", "w", stdout);
    
    cin >> t1;
    for (int t2 = 1; t2 <= t1; ++t2) {
        memset(v, 0, sizeof(v));
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> c[i] >> s[i] >> t[i];
        cin >> m;
        for (int i = 1; i <= m; ++i)
            cin >> c[n + i] >> s[n + i] >> t[n + i];
        int bS = 0, S = 0, C = 0, T = 1;
        while (T) {
            bool ok = false;
            for (int i = 1; i <= n + C; ++i)
                if (!v[i] && t[i]) {
                    ok = true;
                    v[i] = true;
                    T += t[i];
                    --T;
                    C += c[i];
                    if (C > m) C = m;
                    S += s[i];
                }
            if (ok) continue;
            vector<int> s1, s2;
            for (int i = 1; i <= n + C; ++i)
                if (!v[i]) (c[i] ? s1 : s2).push_back(i);
            sort(s1.begin(), s1.end(), cmp);
            sort(s2.begin(), s2.end(), cmp);
            int tS = S;
            for (int i = 0; i < s2.size() && i < T; ++i)
                tS += s[s2[i]];
            if (tS > bS) bS = tS;
            if (s1.empty()) break;
            --T;
            int x = s1[0];
            v[x] = true;
            C += c[x];
            if (C > m) C = m;
            S += s[x];
        }
        if (S > bS) bS = S;
        cout << "Case #" << t2 << ": " << bS << endl;
    }
    
    return 0;
}
