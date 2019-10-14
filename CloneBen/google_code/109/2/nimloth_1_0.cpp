#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++) {
        cout << "Case #" << test + 1 << ": ";
        int d, k, n;
        cin >> d >> k >> n;
        if (k % 2 == 0) {
            int pos = (((k - n) % d ) + d) % d;
            if (pos == 0) pos = d;
            int l = pos + 1;
            if (l ==  d + 1) l = 1;
            int kl = (l - n) % d;
            kl = (kl + d) % d;
            if (kl == 0) kl = d;
            int r = pos - 1;
            if (r == 0) r = d;
            int kr = (r - n) % d;
            kr = (kr + d) % d;
            if (kr == 0) kr = d;
            cout << kl << " " << kr;
        } else {
            int pos = (k + n) % d;
            if (pos == 0) pos = d;
            int l = pos + 1;
            if (l ==  d + 1) l = 1;
            int kl = (n + l) % d;
            if (kl == 0) kl = d;
            int r = pos - 1;
            if (r == 0) r = d;
            int kr = (n + r) % d;
            if (kr == 0) kr = d;
            cout << kl << " " << kr;
        }
        cout << "\n";
    }
    return 0;
}