#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define PB push_back
#define MP make_pair
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define CLR(x, a) memset(x, a, sizeof(x))
//#define L(x) ((x) << 1)
#define R(x) (((x) << 1) + 1)
#define LB(x) ((x)&(-(x)))
#define SL(x) (1 << (x))
#define X first
#define Y second
const int MAXN = 1000 + 20;

int n, m; 
int a[MAXN];

int gao(int len) {
	int nl = 0;
	for (int i = 0; i < len; ++i) {
		if (i+2 < len && a[i+1] - a[i] == m && a[i+2] - a[i+1] == m) {
			// cancel
			i += 2;
		} else {
			a[nl++] = a[i];
		}
	}
	return nl;
}

void solve() {
	cin >> n >> m;
	FOR (i, n) {
		cin >> a[i];
	}
	int res = n;
	while (true) {
		int tmp = gao(res);
		if (tmp == res) break;
		else  res = tmp;
	}
	cout << res << endl;
}

int main(){
	int T; cin >> T;
	FOR(cas, T){
		printf("Case #%d: ", cas + 1);
		solve();
	}
}