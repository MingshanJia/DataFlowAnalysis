#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <climits>
#include <limits>
using namespace std;
#define LL long long
#define DL long double
typedef pair<int, int> ii;
typedef pair<LL, LL> pll;
#define N 44
int tc, tcn, n;
double p[N],re;

void solve() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int i = 0; i < 2 * n; i++) {
			scanf("%lf", &p[i]);
		}
		sort(p, p + 2*n);
		re = 1.0;
		for (int i = 0; i < n; i++) {
			re *= (1 - p[i] * p[2*n - 1 - i]);
		}
		printf("Case #%d: %.9lf\n", ++tcn, re);
	}
}

int main(void) {
	//freopen("BS_input.txt", "r", stdin);
	//freopen("BS_output.txt", "w", stdout);
	solve();
	return 0;
}
