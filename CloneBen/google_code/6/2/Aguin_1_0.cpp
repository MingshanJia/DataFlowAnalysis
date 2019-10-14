#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 10;
int sum[maxn];
char s[maxn];

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; ++kase) {
        int N;
        scanf("%d %s", &N, s + 1);
        for(int i = 1; i <= N; ++i) {
            sum[i] = sum[i - 1] + (s[i] - '0');
        }
        int ans = 0, del = N / 2;
        for(int i = 1; i <= N; ++i) {
            int l = i - 1, r = N - i;
            int dl = (l + 1) / 2, dr = del - dl;
            ans = max(ans, sum[N - dr] - sum[dl]);
            dr = (r + 1) / 2, dl = del - dr;
            ans = max(ans, sum[N - dr] - sum[dl]);
        }
        printf("Case #%d: %d\n", kase, ans);
    }
    return 0;
}