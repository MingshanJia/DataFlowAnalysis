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
int L[maxn], pre[maxn];

ll L2[maxn], sum[maxn];
map<int, int> cnt;

ll query(ll least) {
    int id = lower_bound(L2 + 1, L2 + n + 1, least) - L2;
    return sum[id];
}

void work() {
    cnt.clear();
    ll ans = 0;
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &L[i]), cnt[L[i]]++;
    sort(L + 1, L + n + 1);
    rep(i, 1, n) L2[i] = (ll) L[i] * L[i];
    sum[n + 1] = 0;
    drep(i, n, 1) {
        int j = i + 1;
        while (j <= n && L[i] == L[j]) ++j;
        sum[i] = sum[j] + (ll) (j - i) * (j - i - 1) / 2;
    }
    rep(i, 1, n) 
        if (L[i] == L[i - 1]) pre[i] = pre[i - 1] + 1;
        else pre[i] = 1;
    rep(a, 1, n) rep(b, a + 1, n) {
            if (L[a] < L[b]) {
                ll least = (ll) (L[b] - L[a]) * (L[b] - L[a]) / 4 + 1;
                ans += query(least);
                
                if (L2[a] >= least) {
                    ll c = cnt[L[a]];
                    ans -= c * (c - 1) / 2;
                    c -= pre[a];
                    ans += c * (c - 1) / 2;
                }
                if (L2[b] >= least) {
                    ll c = cnt[L[b]];
                    ans -= c * (c - 1) / 2;
                    c -= pre[b];
                    ans += c * (c - 1) / 2;
                }       
            }
        }
    printf("%lld\n", ans);
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
