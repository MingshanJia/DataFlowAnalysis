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

int res;
int W, H, sx, sy;
int dx[2], dy[2];
bool mark[200][200];

void go(int x, int y) {
	if (x < 0 || x >= W || y < 0 || y >= H) return;
	if (mark[x][y]) return;
	mark[x][y] = true; res++;
	go(x + dx[0], y + dy[0]);
	go(x + dx[1], y + dy[1]);
}

int main() {
	int casos;
	cin >> casos;
	REP(caso, casos) {
		res = 0;
		cin >> W >> H;
		REP(i,2) cin >> dx[i] >> dy[i];
		cin >> sx >> sy;
		CLEAR(mark, false);
		go(sx, sy);
		cout << "Case #" << caso+1 << ": " << res << endl;
	}
	return 0;
}
