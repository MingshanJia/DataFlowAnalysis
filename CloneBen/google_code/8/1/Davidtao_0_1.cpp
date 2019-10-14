#include <iostream>
#include <stdio.h>
using namespace std;

void proc(int iTest);

int main() {
	int test;
	cin >> test;
	for (int iTest = 1; iTest <= test; ++iTest){
		proc(iTest);
	}
	return 0;
}

int isMine(int **board, int x, int y, int size) {
	if (x < 0 || x >= size || y < 0 || y >= size) {
		return 0;
	} else {
		return board[x][y] == '*';
	}
}

int isZero(int **board, int x, int y, int size) {
	if (   isMine(board, x, y, size) 
		|| isMine(board, x, y+1, size)
		|| isMine(board, x, y-1, size)
		|| isMine(board, x+1, y, size)
		|| isMine(board, x+1, y+1, size)
		|| isMine(board, x+1, y-1, size)
		|| isMine(board, x-1, y, size)
		|| isMine(board, x-1, y+1, size)
		|| isMine(board, x-1, y-1, size)) {
		return 0;
	} else {
		return 1;
	}

}

void expand(int **board, int x, int y, int size) {
	if (x < 0 || x >= size || y < 0 || y >= size) {
		return;
	}
	if (board[x][y] == -1) {
		return;
	}
	board[x][y] = -1;
	if (isZero(board, x, y, size)) {
		expand(board, x-1, y-1, size);
		expand(board, x-1, y, size);
		expand(board, x-1, y+1, size);
		expand(board, x, y-1, size);
		expand(board, x, y+1, size);
		expand(board, x+1, y-1, size);
		expand(board, x+1, y, size);
		expand(board, x+1, y+1, size);
	}
}

void proc(int iTest) {
	int size;
	cin >> size;

	int **board = new int *[size];
	for (int i=0; i<size; i++) {
		board[i] = new int[size];
		for (int j=0; j<size; j++) {
			char c;
			cin >> c;
			board[i][j] = c;
		}
	}
	int n_click = 0;
	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			if (board[i][j] != -1 && isZero(board, i, j, size)) {
				n_click++;
				expand(board, i, j, size);
				// cout << i << ' ' << j << endl;
			}
		}
	}
	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			if (board[i][j] == '.') {
				n_click++;
			}
		}
		delete[] board[i];
	}
	delete[] board;
	// for (int i=0; i<size; i++) {
	// 	for (int j=0; j<size; j++) {
	// 		cout << (char) board[i][j];
	// 	}
	// 	cout << endl;
	// }

	cout << "Case #" << iTest << ": " << n_click << endl;	
}