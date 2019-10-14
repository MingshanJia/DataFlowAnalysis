#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;

vector <long long> ans;

const long long P = 1e9 + 7;

int main() {
    freopen("C-small-2-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++) {
        ans.clear();
        cout << "Case #" << test + 1 << ": ";
        long long c, v, l;
        cin >> c >> v >> l;
        ans.push_back(1);
        ans.push_back(v);
        for (int i = 2; i <= l; ++i) {
            int res = (ans[i - 1] * v) % P;
            res = res + (((ans[i - 2] * v) % P) * c) % P;
            res = res % P;
            ans.push_back(res);
        }
        cout << ans[l];
        cout << "\n";
    }
    return 0;
}