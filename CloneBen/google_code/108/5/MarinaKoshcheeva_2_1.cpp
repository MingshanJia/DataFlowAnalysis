#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 15;
const int MAXC = 288;
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

char premap[MAXC][MAXN][MAXN];
bool isCalc[MAXC];

char board[MAXN][MAXN];
int d;
int n;

void solve() {
	scanf("%d%d", &d, &n);
	for (int i = 0; i < d; ++i) {
		cout << endl;
		for (int j = 0; j < d; ++j)
			cout << premap[n][i][j];
	}
}
void saveCalcMap(int n) {
	isCalc[n] = true;
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; ++j)
			premap[n][i][j] = board[i][j];
}

bool inBoard(int x, int y) {
	return (0 <= x && x < MAXN && 0 <= y && y < MAXN);
}

int countIO() {
	int result = 0;
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < MAXN; ++j) if (board[i][j] == 'I') {
			for (int k = 0; k < 8; ++k) {
				if (inBoard(i + dx[k], j + dy[k]) && inBoard(i + 2 * dx[k], j + 2 * dy[k]) &&
						board[i + dx[k]][j + dy[k]] == '/' && board[i + 2 * dx[k]][j + 2 * dy[k]] == 'O')
					result++;
			}
		}
	return result;
}

void fillBoard(int n) {
	d = MAXN;
	string mask = "O/I/O/I/O/I/O/I";
	for (int i = 0; i < d; ++i)
		for (int j = 0; j < d; ++j)
			board[i][j] = mask[i];
	int posI[4] = { 2, 6, 10, 14 };
	for (int t = 0; t < 4; ++t) {
		int row = posI[t];
		for (int dir = -1; dir <= 1; dir += 2) {
			if (n >= 41) {
				n -= 41;
				continue;
			}
			for (int i = 0; i < d; ++i)
				board[row + dir][i] = 'O';

			if (n == 0) {
				continue;
			}

			int cnt = 0;
			if (n % 3 >= 1)
				board[row + dir][0] = '/';
			if (n % 3 == 2)
				board[row + dir][d - 1] = '/';
			n -= (n % 3);
			for (int i = 0; i < n / 3; ++i)
				board[row + dir][i + 1] = '/';
			n = 0;
		}
	}
}

void precalc() {
	for (int c = 0; c < MAXC; ++c) {
		fillBoard(c);
		int cnt = countIO();
		if (cnt != c)
			cout << endl << "ERRRROOOORRRRRRRR!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		saveCalcMap(c);
	}
}

int main()
{
	precalc();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
}
