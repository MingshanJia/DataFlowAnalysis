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

struct point {
    int x, y, z;
} p[10];
bool operator<(const point &a, const point &b) {
    return a.x < b.x;
}

void work() {
    rep(i, 1, 3) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
    sort(p + 1, p + 4);
    double r = (p[3].x - p[1].x) / 6.;
    printf("%.10lf\n", r);
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
