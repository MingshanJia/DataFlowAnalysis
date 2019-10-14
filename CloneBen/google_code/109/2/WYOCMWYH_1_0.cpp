#include <bits/stdc++.h>

using namespace std;

void Solve(int test_num) {
    printf("Case #%d:", test_num);
    int d, k, n;
    scanf("%d%d%d", &d, &k, &n);
    --k;
    if (k % 2 == 0) {
        int f = (k + n) % d;
        int l = (f + 1) % d;
        l = (l + n) % d;
        int r = (d + (f - 1) % d) % d;
        r = (r + n) % d;
        printf(" %d %d\n", ++l, ++r);
    } else {
        int f = (d + (k - n) % d) % d; 
        int l = (f + 1) % d;
        l = (d + (l - n) % d) % d;
        int r = (d + (f - 1) % d) % d;
        r = (d + (r - n) % d) % d;
        printf(" %d %d\n", ++l, ++r);
    }
}

int main() {
    freopen("b.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) Solve(i + 1);
}
