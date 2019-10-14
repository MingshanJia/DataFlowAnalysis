#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const double EPS = 1e-9;

void solve() {
    int n, k;
    double U;
    cin >> n >> k >> U;
    vector<double> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    A.push_back(1);
    n++;
    while (U > EPS) {
        int pos = -1;
        for (int i = 1; i < n; ++i) {
            if (A[i] > A[0] + EPS) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            break;
        }
        double add = min(U / pos, (A[pos] - A[0]) / pos);
        for (int i = 0; i < pos; ++i) {
            A[i] += add;
        }
        U -= add * pos;
    }
    double ans = 1;
    for (int i = 0; i < n; ++i) {
        ans *= A[i];
    }
    cout << ans << '\n';
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    cout << setprecision(13) << fixed;

    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
}
