#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 5005

int s[N];

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        memset(s, 0, sizeof(s));
        for (int i = 0; i < n; ++i) {
            int l, r;
            scanf("%d %d", &l, &r);
            if (l > r) swap(l, r);
            for (int j = l; j <= r; ++j)
                ++s[j];
        }
        printf("Case #%d:", ++cas);
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            printf(" %d", s[x]);
        }
        puts("");
    }
    return 0;
}
