#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mk make_pair
#define pb push_back
#define sz(a) (int)(a).size()
#define rep(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)

typedef complex<ld> cplex;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int inf = 1000000007;
const int N = 10000 + 7;
const int multipleTest = 1;

int n;

int dp[N];

void init() {
    dp[0] = 0;
    
    for (int i = 1; i < N; ++i) {
        dp[i] = inf;
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
}

void solve() {
    cin >> n;
    cout << dp[n] << '\n';
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    init();
    
    int Test = 1;
    if (multipleTest) {
        cin >> Test;
    }
    for(int i = 0; i < Test; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }
#ifdef _LOCAL_
//    cout<<"\n" << 1.0 * clock() / CLOCKS_PER_SEC << endl;
#endif
}
