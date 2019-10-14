#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define FOR(i,n) for(int i = 0 ; i < n ; i++)
#define FORL(i,i0,n) for(int i = i0 ; i < n ; i++)
#define FORIT(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define ALL(x) x.begin(), x.end()
#define SZ(x) int(x.size())
#define LEN(x) int(x.length())
#define PB push_back
#define MP make_pair
#define FST(x) (x).first
#define SEC(x) (x).second
#define LL long long
#define mem(x, n) memset(x, n, sizeof(x))
#define ni() ({int t;scanf("%d",&t);t;})
#define SRAND() srand(time(NULL))
#define RAND(mod, offset) ((rand() % (mod)) + (offset))
#if 1
#define DBG(z) cerr << #z << ": " << (z) << endl
#else
#define DBG(z)
#endif
using namespace std;
int a[20];
int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int t = ni();
	int kase = 1;
	while (t--) {
		int M = ni();
		FOR(i, 12)
			a[i] = ni();
		int ans = -1000000000, bi = -1, bj = -1;
		FOR(i, 12) {
			FORL(j, i + 1, 12) {
				int have = M / a[i];
				int rem = M % a[i];
				int sell = have * a[j];
				int profit = sell - M + rem;

				if (ans < profit || (ans == profit && a[bi] > a[i]))
					ans = profit, bi = i, bj = j;
			}
		}
		if (ans <= 0)
			printf ("Case #%d: IMPOSSIBLE\n", kase++);
		else
			printf("Case #%d: %d %d %d\n", kase++, bi+1, bj+1, ans);
	}

}

