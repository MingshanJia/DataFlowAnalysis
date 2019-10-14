#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FOREACH(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define SZ(x) ((int)(x).size())

typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<string> vs; typedef long long ll;

int n, k;
int x[50], y[50];
int masks[50*50], nmasks;
int best[1<<16];

bool can(int len) {
	nmasks = 0;
	REP(i, n) REP(j, i) {
		int lx = min(x[i], x[j]), ly = min(y[i], y[j]);
		int mask = 0;
		REP(k, n) if (x[k] >= lx && x[k] <= lx + len && y[k] >= ly && y[k] <= ly + len) mask |= 1<<k;
		if (__builtin_popcount(mask) > 1) masks[nmasks++] = mask;
	}
	CLEAR(best, 0x3f);
	best[0] = 0;
	FOR(i, 1, (1<<n)) {
		best[i] <?= best[i & (i-1)] + 1;
		REP(j, nmasks) best[i] <?= best[i & ~masks[j]] + 1;
	}
	return best[(1<<n)-1] <= k;
}

int main() {
	int casos;
	cin >> casos;
	REP(caso, casos) {
		cin >> n >> k;
		REP(i, n) cin >> x[i] >> y[i];
		int l = 1, r = 128000;
		while (l < r) {
			int m = (l+r)/2;
			if (can(m)) {
				r = m;
			} else {
				l = m+1;
			}
		}
		cout << "Case #" << caso+1 << ": " << l << endl;
	}
	return 0;
}
