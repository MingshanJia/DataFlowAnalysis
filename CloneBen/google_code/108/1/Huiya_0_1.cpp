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
int tc, tcn, f, s,a[101],b[101],re,ch[101];

void solve() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &f, &s);
		for (int i = 0; i < f; i++) {
			scanf("%d %d", &a[i], &b[i]);
		}
		re = 0;
		for (int i = 1; i <= s; i++) {
			int cnt = 0;
			memset(ch, 0, sizeof(ch));
			for (int j = 0; j < f; j++) {
				if (a[j] == i && !ch[b[j]]) {
					cnt++;
					ch[b[j]] = 1;
				}
				else if (b[j] == i && !ch[a[j]]) {
					cnt++;
					ch[a[j]] = 1;
				}
			}
			re = max(re, cnt);
		}
		printf("Case #%d: %d\n", ++tcn, re);
	}
	
}

int main(void) {
	//freopen("AL_input.txt", "r", stdin);
	//freopen("AL_output.txt", "w", stdout);
	solve();
	return 0;
}
