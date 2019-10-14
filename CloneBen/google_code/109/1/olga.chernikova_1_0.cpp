#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int test = 1; test <= t; ++test) {
        int d, k, n;
        scanf("%d%d%d", &d, &k, &n);
        n %= d;
        --k;
        int nk = k;
        if ((k & 1) == 0) {
            nk += n;
            if (nk >= d) {
                nk -= d;
            }
        } else {
            nk -= n;
            if (nk < 0) {
                nk += d;
            } 
        }
        int nx = (nk + 1) % d;
        int pr = (nk - 1 + d) % d;
        int fr = 0, sc = 0;
        for (int i = 0; i < d; ++i) {
            int ni = i;
            if ((i & 1) == 0) {
                ni += n;
                if (ni >= d) {
                    ni -= d;
                }
            } else {
                ni -= n;
                if (ni < 0) {
                    ni += d;
                } 
            }
            if (ni == nx) {
                fr = i + 1;
            }
            if (ni == pr) {
                sc = i + 1;
            }
        }
        printf("Case #%d: ", test);
        printf("%d %d\n", fr, sc);
    }
}