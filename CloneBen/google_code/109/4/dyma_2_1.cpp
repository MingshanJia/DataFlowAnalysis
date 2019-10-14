#include <bits/stdc++.h>

using namespace std;

const long long base = 1e9 + 7;

const int maxn = 1000;

long long f[maxn][2];

long long solve() {
    long long l, c, v;
    cin >> c >> v >> l;
    for (int i = 0; i <= l + 1; i++)
        f[i][0] = f[i][1] = 0;
    f[1][0] = c % base;
    f[1][1] = v % base;
    for (int i = 2; i <= l; i++) {
        f[i][1] = v * (f[i - 1][1] + f[i - 1][0]) % base;
        f[i][0] = c * (f[i - 1][1]) % base;
    }
    return f[l][1];

}

int main() {
    int test;
    cin >> test;
    for (int i = 1; i <= test; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}