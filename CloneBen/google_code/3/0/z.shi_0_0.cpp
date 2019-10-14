#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define drep(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define pb(x) push_back(x)
#define mp(x, y) (make_pair(x, y))
#define clr(x) memset(x, 0, sizeof(x))
#define xx first
#define yy second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int inf = ~0U >> 1;
const ll INF = ~0ULL >> 1;
template <class T> inline void read(T &n) {
    char c; int flag = 1;
    for (c = getchar(); !(c >= '0' && c <= '9' || c == '-'); c = getchar()); if (c == '-') flag = -1, n = 0; else n = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0'; n *= flag;
}
//***************************

const int maxn = 1000;
ull h[maxn], base[maxn];
int dp[400][400][400], n;
char s[maxn];

int getHash(int l, int r) {
    if (l == 0 && r == 0) return 0;
    return h[r] - h[l - 1] * base[r - l + 1];
}

void work() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    base[0] = 1;
    rep(i, 1, n) base[i] = base[i - 1] * 233;
    rep(i, 1, n) h[i] = h[i - 1] * base[1] + s[i];
    rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) dp[i][j][k] = inf;
    dp[0][0][0] = 0;
    rep(i, 0, n - 1) {
        int tmp = inf;
        rep(l, 0, i) rep(r, l, i) tmp = min(tmp, dp[i][l][r]);
        if (tmp != inf)
            rep(l, 0, i) rep(r, l, i) 
                dp[i][l][r] = min(dp[i][l][r], tmp + 1);
        rep(l, 0, i)
            rep(r, l, i) {
                if (l == 0 && r > 0) continue;
                if (dp[i][l][r] == inf) continue;
                dp[i + 1][l][r] = min(dp[i + 1][l][r], dp[i][l][r] + 1);
                if (i + r - l + 1 <= n && getHash(l, r) == getHash(i + 1, i + r - l + 1))
                    dp[i + r - l + 1][l][r] = min(dp[i + r - l + 1][l][r], dp[i][l][r] + 1);
                tmp = min(tmp, dp[i][l][r]);
            }
    }
    int ans = inf;
    rep(l, 0, n) rep(r, l, n) 
        ans = min(ans, dp[n][l][r]);
    printf("%d\n", ans);
}

int main(int argc, char *argv[]) {
	int cases;
    scanf("%d", &cases);
    rep(_, 1, cases) {
        printf("Case #%d: ", _);
        work();
    }
	return 0;
}
