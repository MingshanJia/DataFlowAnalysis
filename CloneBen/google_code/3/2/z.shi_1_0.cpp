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

const int maxn = 6000;
int n;
int L[maxn];

void work() {
    int ans = 0;
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &L[i]);
    sort(L + 1, L + n + 1);
    rep(a, 1, n) rep(b, a + 1, n) {
        rep(c, 1, n) rep(d, c + 1, n) {
            if (L[a] < L[b] && c != a && c != b && d != a && d != b && L[c] == L[d]) {
                if (L[c] == L[b] && c < b) continue;
                if (L[c] == L[a] && c < a) continue;
                if (4ll * L[c] * L[c] > (ll)(L[b] - L[a]) * (L[b] - L[a])) {
                    ans++;
                    //printf("%d %d %d %d\n", L[a], L[b], L[c], L[d]);
                }
            }
        }
    }
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
