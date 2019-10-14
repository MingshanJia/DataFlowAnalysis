#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

#define L 55
#define N 20005

int n, tot;
vector < int > v[N];
unordered_map < string, int > mp;
string na[N];
int in[N], out[N];

int main() {
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    char a[L], b[L];
    int t, cas = 0;
    auto getID = [&](char *s) {
        if (mp.count(s)) return mp[s];
        na[tot] = s;
        return mp[s] = tot++;
    };
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        fill(v, v + N, vector < int >());
        mp.clear();
        tot = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s %s", a, b);
            int ai = getID(a), bi = getID(b);
            ++in[bi];
            ++out[ai];
            v[ai].push_back(bi);
            if (in[ai] > 1 || out[bi] > 1)
                fprintf(stderr, "error\n");
        }
        int x = -1;
        for (int i = 0; i < tot; ++i)
            if (0 == in[i]) {
                if (-1 != x)
                    fprintf(stderr, "error\n");
                x = i;
            }
        printf("Case #%d:", ++cas);
        while (v[x].size()) {
            printf(" %s-%s", na[x].c_str(), na[v[x].front()].c_str());
            x = v[x].front();
        }
        puts("");
    }
    return 0;
}
