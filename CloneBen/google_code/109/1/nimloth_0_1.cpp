#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;

vector<int> regular;

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++) {
        regular.clear();
        int n;
        cin >> n;
        cout << "Case #" << test + 1 << ": ";
        int k = -1;
        for (int i = 0; i < 2 * n; ++i) {
            int a;
            cin >> a;
            if (k != -1 && a == regular[k]) {
                k++;
            } else {
                regular.push_back((a / 3) * 4);
                if (k == -1) k = 0;
                cout << a << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}