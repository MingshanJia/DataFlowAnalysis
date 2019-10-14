#include <bits/stdc++.h>

#define sz(x) (int((x).size()))

const int maxn = 5005;

int T, n, a[maxn];

long long f(long long x) {
    return x * (x-1) / 2;
}

long long g(long long x) {
    return x * (x-1) * (x-2) / 6;
}

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", a+i);
        std::sort(a, a+n);

        long long ans = 0;

        int s = 0;
        while (s < n) {
            int e = s+1;
            while (e < n && a[e] == a[s]) e++;

            if (e - s >= 2) {
                int x = 0, y = 0;
                for (int i = 0; i < n; i++) {
                    while (x < n && a[x] <= a[i] - 2*a[s]) x++;
                    while (y < n && a[y] < a[i]) y++;
                    if (a[i] != a[s]) {
                        int other = y - x;
                        if (a[x] <= a[s] && a[s] < a[y]) {
                            other -= e-s;
                        }
                        assert(other >= 0);
                        ans += f(e-s) * other;

                        if (a[x] <= a[s] && a[s] < a[y]) {
                            assert(a[i] > a[s]);
                            ans += g(e-s);
                        }
                    } else {
                        int other = y-x;
                        assert(a[y] <= a[s]);
                        assert(s <= i && i < e);
                        if (i - s >= 2) {
                            ans += f(i - s) * other;
                        }
                    }
                }
            }

            s = e;
        }
        printf("Case #%d: %lld\n", t, ans);
    }
}

