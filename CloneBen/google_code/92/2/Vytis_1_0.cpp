#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define FILE_IN  "B-small-attempt1.in"
#define FILE_OUT "B-small-attempt1.out"

#define MAXR 55
#define LOTS 0x3fffffff

struct pos {
	int row, col;
	int digs, dige;
	pos(): row(0), col(0), digs(0), dige(0) {}
	pos(int row, int col, int digs, int dige): row(row), col(col), digs(digs), dige(dige) {}
	bool operator<(const pos& a) const {
		if (row != a.row)
			return row < a.row;
		if (col != a.col)
			return col < a.col;
		if (digs != a.digs)
			return digs < a.digs;
		return dige < a.dige;
	}
};

typedef set<pos> sp;

bool air[MAXR][MAXR];
int dig[MAXR][MAXR][MAXR][MAXR];

int fall(int row, int col) {
	while (air[row + 1][col])
		++row;
	return row;
}

int& decreaseTo(int &var, int val) { return var = min(var, val); }

void solve() {
	int R, C, F;
	scanf("%d%d%d", &R, &C, &F);
	fill(air[0], air[MAXR], false);
	fill(dig[0][0][0], dig[MAXR][0][0], LOTS);
	for (int i = 1; i <= R; ++i) {
		char c;
		for (int j = 1; j <= C; ++j) {
			scanf(" %c", &c);
			air[i][j] = c == '.';
		}
	}
	dig[1][1][0][0] = 0;
	sp S;
	S.insert(pos(1, 1, 0, 0));
	int best = LOTS;
	while (!S.empty()) {
		pos p = *S.begin();
		S.erase(S.begin());
		int dd = dig[p.row][p.col][p.digs][p.dige];
		//printf("> %d %d %d %d = %d\n", p.row, p.col, p.digs, p.dige, dd);
		if (p.row == R) {
			decreaseTo(best, dd);
			continue;
		}
		if (air[p.row + 1][p.col])
			continue;
		int left = p.col, right = p.col;
		while ((air[p.row][left - 1] || left - 1 >= p.digs && left - 1 < p.dige) && !air[p.row + 1][left - 1])
			--left;
		while ((air[p.row][right + 1] || right + 1 >= p.digs && right + 1 < p.dige) && !air[p.row + 1][right + 1])
			++right;
		if (air[p.row][left - 1] || left - 1 >= p.digs && left - 1 < p.dige) {
			int nrow = fall(p.row, left - 1);
			if (nrow - p.row <= F) {
				S.insert(pos(nrow, left - 1, 0, 0));
				decreaseTo(dig[nrow][left - 1][0][0], dd);
			}
		}
		if (air[p.row][right + 1] || right + 1 >= p.digs && right + 1 < p.dige) {
			int nrow = fall(p.row, right + 1);
			if (nrow - p.row <= F) {
				S.insert(pos(nrow, right + 1, 0, 0));
				decreaseTo(dig[nrow][right + 1][0][0], dd);
			}
		}
		for (int digs = left; digs <= right; ++digs)
			for (int dige = digs; dige <= right; ++dige) {
				int nd = dige - digs + 1;
				if (digs != left) {
					int nrow = fall(p.row + 1, digs);
					if (nrow == p.row + 1) {
						S.insert(pos(nrow, digs, digs, dige + 1));
						decreaseTo(dig[nrow][digs][digs][dige + 1], dd + nd);
					} else if (nrow - p.row <= F) {
						S.insert(pos(nrow, digs, 0, 0));
						decreaseTo(dig[nrow][digs][0][0], dd + nd);
					}
				}
				if (dige != right) {
					int nrow = fall(p.row + 1, dige);
					if (nrow == p.row + 1) {
						S.insert(pos(nrow, dige, digs, dige + 1));
						decreaseTo(dig[nrow][dige][digs][dige + 1], dd + nd);
					} else if (nrow - p.row <= F) {
						S.insert(pos(nrow, dige, 0, 0));
						decreaseTo(dig[nrow][dige][0][0], dd + nd);
					}
				}
			}
	}
	
	if (best == LOTS)
		printf("No\n");
	else
		printf("Yes %d\n", best);
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
