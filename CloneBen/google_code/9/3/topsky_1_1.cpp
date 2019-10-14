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
const int MAXN = 400 + 20;

int b, l, n; 
double cup[MAXN][MAXN*MAXN];

int lev(int n) {
	int res = 1, tot = 0;
	while (true) {
		tot += res;
		if (tot >= n) {
			return res;
		}
		res++;
	}
	return -1;
}

void solve() {
	cin >> b >> l >> n;
	cup[1][1] = b*750;
	for (int i = 1; i <= l; ++i) {
		for (int j = 1; j <= (i+2)*(i+1)/2; ++j) {
			cup[i+1][j] = 0;
		}
		for (int j = 1; j <= (i+1)*i/2; ++j) {
			if (cup[i][j] > 250) {
				cup[i+1][j] += (cup[i][j] - 250) / 3;
				int level = lev(j);
				// cout << level << endl;
				cup[i+1][j+level] += (cup[i][j] - 250) / 3;
				cup[i+1][j+level+1] += (cup[i][j] - 250) / 3;
				cup[i][j] = 250;
			} 
		}
	}
	if (cup[l][n] < 0) printf("%.7lf\n", 0.0);
	else printf("%.7lf\n", cup[l][n]);
}

int main(){
	int T; cin >> T;
	FOR(cas, T){
		printf("Case #%d: ", cas + 1);
		solve();
	}
}