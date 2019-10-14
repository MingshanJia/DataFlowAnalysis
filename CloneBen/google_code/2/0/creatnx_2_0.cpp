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
const int N = 100 + 7;
const int multipleTest = 1;


int n, p, m;
int dp[N][N];

double expected[N][N * 2];
double L[N][N * 2];

void solve() {
    cin >> n >> m >> p;
    rep(i, 1, n + 1) rep(j, 1, n + 1) {
        dp[i][j] = inf;
        dp[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        dp[u][v] = dp[v][u] = min(dp[u][v], c);
    }
    for (int k = 1; k <= n; ++k) {
        for (int v = 1; v <= n; ++v) {
            for (int u = 1; u <= n; ++u) dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]);
        }
    }
    
    double pr = 1.0 / (n - 1);
    L[1][0] = 1.0;
    
    for (int len = 1; len <= p; ++len) {
        for (int i = 1; i <= n; ++i) {
            expected[i][len] = L[i][len] = 0;
            for (int j = 1; j <= n; ++j) if (i != j) {
                expected[i][len] += expected[j][len - 1] * pr + pr * L[j][len - 1] * dp[j][i];
                L[i][len] += L[j][len - 1] * pr;
            }
        }
        
//        rep(i, 1, n + 1) cout << L[i][len] << ' ';
//        puts("");
        
    }
    double res = 0;
    rep(i, 1, n + 1) res += expected[i][p];
    printf("%.6lf\n", res);
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
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
