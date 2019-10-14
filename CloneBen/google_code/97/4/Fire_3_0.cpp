#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int MAXS = 30;
const int INF = 0x7f7f7f7f;

const int MOVES[4][2] = {
	{0, -1},
	{0, 1},
	{-1, 0},
	{1, 0}
};

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

int minDis[MAXS][MAXS];
bool tags[MAXS][MAXS];
char grids[MAXS][MAXS + 1];
PII bfs[MAXS * MAXS];

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int si, sj;
		scanf("%d%d", &si, &sj);
		while (getchar() != '\n');
		for (int i = 0; i < si; i++) {
			gets(grids[i]);
			memset(tags[i], false, sizeof(bool) * sj);
			memset(minDis[i], 0xff, sizeof(int) * sj);
		}
		int fnum = 0;
		PII other;
		for (int i = 0; i < si; i++) {
			for (int j = 0; j < sj; j++) {
				if (grids[i][j] == 'T') {
					if (++fnum == 2) {
						other = PII(i, j);
					}
				}
			}
		}
		minDis[0][0] = 0;
		bfs[0] = PII(0, 0);
		int begin = 0, end = 1;
		while (begin < end) {
			const PII & p = bfs[begin++];
			for (int k = 0; k < 4; k++) {
				int ni = p.first + MOVES[k][0];
				int nj = p.second + MOVES[k][1];
				if (0 <= ni && ni < si && 0 <= nj && nj < sj && grids[ni][nj] != '.' && minDis[ni][nj] == -1) {
					minDis[ni][nj] = minDis[p.first][p.second] + 1;
					bfs[end++] = PII(ni, nj);
				}
			}
		}
		int ans;
		if (fnum == 1) {
			ans = 0;
			for (int i = 0; i < si; i++) {
				for (int j = 0; j < sj; j++) {
					if (grids[i][j] != '.') {
						ans += minDis[i][j];
					}
				}
			}
		} else if (fnum == 2) {
			int pi = other.first, pj = other.second;
			ans = 0;
			while (pi != 0 || pj != 0) {
				tags[pi][pj] = true;
				ans += minDis[pi][pj];
				for (int k = 0; ; k++) {
					if (k == 4) {
						puts("Wrong!");
					}
					int ni = pi + MOVES[k][0];
					int nj = pj + MOVES[k][1];
					if (0 <= ni && ni < si && 0 <= nj && nj < sj && grids[ni][nj] != '.' && minDis[ni][nj] == minDis[pi][pj] - 1) {
						pi = ni;
						pj = nj;
						break;
					}
				}
			}
			tags[0][0] = true;
			for (int i = 0; i < si; i++) {
				memset(minDis[i], 0x7f, sizeof(int) * sj);
			}
			bfs[0] = PII(0, 0);
			bfs[1] = other;
			begin = 0;
			end = 2;
			minDis[0][0] = minDis[other.first][other.second] = 0;
			priority_queue<PIII, vector<PIII>, greater<PIII> > heap;
			while (begin < end) {
				const PII & p = bfs[begin++];
				for (int k = 0; k < 4; k++) {
					int ni = p.first + MOVES[k][0];
					int nj = p.second + MOVES[k][1];
					if (0 <= ni && ni < si && 0 <= nj && nj < sj && grids[ni][nj] == '#') {
						if (tags[ni][nj]) {
							if (minDis[ni][nj] == INF) {
								minDis[ni][nj] = minDis[p.first][p.second] + 1;
								bfs[end++] = PII(ni, nj);
							}
						} else {
							if (minDis[ni][nj] > minDis[p.first][p.second] + 1) {
								minDis[ni][nj] = minDis[p.first][p.second] + 1;
								heap.push(PIII(minDis[ni][nj], PII(ni, nj)));
							}
						}
					}
				}
			}
			while (!heap.empty()) {
				const PIII p = heap.top();
				heap.pop();
				const PII & pos = p.second;
				if (!tags[pos.first][pos.second]) {
					if (minDis[pos.first][pos.second] != p.first) {
						puts("Wrong distance!");
					}
					tags[pos.first][pos.second] = true;
					ans += p.first;
					for (int k = 0; k < 4; k++) {
						int ni = pos.first + MOVES[k][0];
						int nj = pos.second + MOVES[k][1];
						if (0 <= ni && ni < si && 0 <= nj && nj < sj && grids[ni][nj] == '#' && !tags[ni][nj] && minDis[ni][nj] > p.first + 1) {
							minDis[ni][nj] = p.first + 1;
							heap.push(PIII(minDis[ni][nj], PII(ni, nj)));
						}
					}
				}
			}
		} else {
			puts("WRONG INPUT!");
			ans = -1;
		}
		printf("Case #%d: %d\n", caseIndex, ans);
	}

	return 0;
}
