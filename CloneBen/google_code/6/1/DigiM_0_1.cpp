#include <bits/stdc++.h>
using namespace std;

vector<string> arr;
vector<bool> use;

bool isPrefix(string &a, string &b) {
    if (a.length() > b.length()) return false;

    for (int i = 0; i < (int)a.length(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void solve() {
    arr.clear();
    use.clear();

    int n, p;
    cin >> n >> p;

    for (int i = 0; i < p; i++) {
        string s;
        cin >> s;

        arr.push_back(s);
        use.push_back(true);
    }

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            if (i != j) {
                if (isPrefix(arr[j], arr[i])) {
                    use[i] = false;
                    break;
                }
            }
        }
    }

    long long tmp = pow(2, n);
    for (int i = 0; i < p; i++) {
        if (use[i]) {
            tmp -= pow(2, n-arr[i].length());
        }
    }
    cout << tmp << endl;
}

int main() {
    int qt;
    cin >> qt;

    for (int q = 0; q < qt; q++) {
        cout << "Case #" << q+1 << ": ";
        solve();
    }
}