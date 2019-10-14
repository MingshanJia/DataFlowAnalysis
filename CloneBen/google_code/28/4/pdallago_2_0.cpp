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

const int MOD = 9901;
int cnt = 0;
int n, k;

bool seen[20];
bool forbid[400][400];

void dfs(int x, int t) {
	if (t == n-1) {
		if (!forbid[x][0]) cnt++;
	} else {
		seen[x] = true;
		REP(y, n) if (!seen[y] && !forbid[x][y]) dfs(y, t+1);
		seen[x] = false;
	}
}

int main() {
	int casos;
	cin >> casos;
	REP(caso, casos) {
		cin >> n >> k;
		CLEAR(forbid, false);
		REP(i, k) {
			int a, b;
			cin >> a >> b; a--; b--;
			forbid[a][b] = forbid[b][a] = true;
		}
		cnt = 0;
		CLEAR(seen, false);
		dfs(0, 0);
		cnt /= 2;
		cout << "Case #" << caso+1 << ": " << (cnt%MOD) << endl;
	}
	return 0;
}
