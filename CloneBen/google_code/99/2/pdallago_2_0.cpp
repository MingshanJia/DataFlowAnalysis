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

int Q, M;
  bool seen[40][5][20000];
double memo[40][5][20000];
double prob[100][4];

double best(int qu, int opt, int left) {
	double &res = memo[qu][opt][left];
	if (!seen[qu][opt][left]) {
		seen[qu][opt][left] = true;
		if (qu == Q) return left==1?(res = 1.0):0;
		if (left == 0) return (res = 0.0);
		res = 0.0;
		if (opt < 3) {
			for (int use = 0; use <= left; use++) {
				res = max(res, prob[qu][opt]*best(qu+1, 0, use) + best(qu, opt+1, left-use));
			}
		} else {
			res = prob[qu][opt]*best(qu+1, 0, left);
		}
		//printf("%d %d %d %f\n", qu, opt, left, res);
	}
	return res;
}

int main() {
	int casos;
	cin >> casos;
	REP(caso, casos) {
		cin >> M >> Q;
		REP(i, Q) cin >> prob[i][0] >> prob[i][1] >> prob[i][2] >> prob[i][3];
		CLEAR(seen, false);
		if (M > (1<<(2*Q))) M = 1<<(2*Q);
		cout << "Case #" << caso+1 << ": " << fixed << setprecision(6) << best(0, 0, M) << endl;
		//return 0;
	}
	return 0;
}
