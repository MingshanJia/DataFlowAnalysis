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
#define N 55
int tc, tcn, d,n,row;
char s[55][55];
string t = "I/O/I/O/I/O/I/O";

void makeGrid() {
	memset(s, 0, sizeof(s));
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++)
			s[i][j] = 'O';
	}
	int cnt = 0;

	if (n <= 7)
		row = 1;
	else if (n <= 14) {
		row = 2;
		cnt = 7;
	}
	else {
		row = 2 + (n - 14) / 21;
		if ((n - 14) % 21)
			row++;
		cnt = 14 + 21 * (row - 3);
	}

	for (int i = 0; i < row-1; i++) {
		for (int j = 0; j < t.size(); j++)
			s[i][j] = t[j];
	}
	
	int m = n - cnt;
	for (int i = 1; i < (1 << 15); i++) {
		for (int j = 0; j < t.size(); j++) {
			if (i&(1 << j))
				s[row - 1][j] = t[j];
			else if (t[j] == 'O')
				s[row - 1][j] = '/';
		}
		int sum = 0;
		for (int j = 0; j < t.size(); j++) {
			if (!(i&(1 << j)))
				continue;
			if (s[row - 1][j] == 'O') {
				if (row >= 3) {
					sum += 2;
					if (j == t.size() - 1)
						sum--;
				}
			}
			else if (s[row - 1][j] == '/') {
				if (s[row - 1][j - 1] == 'I' && s[row - 1][j + 1] == 'O')
					sum++;
				if (s[row - 1][j - 1] == 'O' && s[row - 1][j + 1] == 'I')
					sum++;
				
			}
			else {
				if (row >= 3) {
					sum += 2;
					if (j == 0)
						sum--;
				}
			}
		}
		if (sum == m) return;
		for (int j = 0; j < t.size(); j++)
			s[row - 1][j] = 'O';
	}

}

void solve() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d",&d, &n);
		makeGrid();
		printf("Case #%d:\n",++tcn);
		for (int i = 0; i < row; i++) {
			printf("%s\n", s[i]);
		}

	}
}

int main(void) {
	//freopen("CS_input.txt", "r", stdin);
	//freopen("CS_output.txt", "w", stdout);
	solve();
	return 0;
}
