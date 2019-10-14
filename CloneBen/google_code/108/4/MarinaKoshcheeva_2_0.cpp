#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 50;

char board[MAXN][MAXN];
int d;
int n;

void fillCell(int x, int y, int k) {
	for (int i = x - 2; i <= x + 2; ++i)
		for (int j = y - 2; j <= y + 2; ++j)
			board[i][j] = 'O';
	for (int i = x - 1; i <= x + 1; ++i)
		for (int j = y - 1; j <= y + 1; ++j) {
			if (i == x && j == y)
				board[i][j] = 'I';
			else {
				if (k > 0) {
					board[i][j] = '/';
					k--;
				}
			}
		}
}

void solve() {
	scanf("%d%d", &d, &n);
	memset(board, 0, sizeof(board));

	int period = 5;
	for (int i = 0; i < d / period; i++)
		for (int j = 0; j < d / period; ++j) {
			fillCell(i * period + 2, j * period + 2, min(8, n));
			if (n >= 8)
				n -= 8;
			else
				n = 0;
		}

	for (int i = 0; i < d; ++i) {
		cout << endl;
		for (int j = 0; j < d; ++j)
			cout << board[i][j];
	}
}

int main()
{
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
