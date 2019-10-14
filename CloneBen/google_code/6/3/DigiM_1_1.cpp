#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int x = (n+1)/2;

    int ans = 0;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr+= s[i]-'0';
        if (i >= x) {
            curr-= s[i-x]-'0';
        }

        ans = max(ans, curr);
    }

    cout << ans << endl;
}

int main() {
    int qt;
    cin >> qt;

    for (int q = 0; q < qt; q++) {
        cout << "Case #" << q+1 << ": ";
        solve();
    }
}