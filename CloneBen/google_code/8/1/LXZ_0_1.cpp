#include <iostream>
using namespace std;

char map[310][310];
int num[310][310];
int N;

void dfs(int i, int j) {
	if (i < 0 || i >= N || j < 0 || j >= N) return;
	if (num[i][j] == 0) {
		num[i][j] = -1;
		for (int di = -1; di <= 1; di++) {
			for (int dj = -1; dj <= 1; dj++) {
				int newi = i + di;
				int newj = j + dj;
				if (newi < 0 || newi >= N || newj < 0 || newj >= N) continue;
				dfs(newi, newj);
			}
		}
	}
	num[i][j] = -1;
}

int main() {
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> map[i];
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == '*') {
					num[i][j] = -1;
					continue;
				}
				int counts = 0;
				for (int di = -1; di <= 1; di++) {
					for (int dj = -1; dj <= 1; dj++) {
						int newi = i + di;
						int newj = j + dj;
						if (newi < 0 || newi >= N || newj < 0 || newj >= N) {
							continue;
						}
						if (map[newi][newj] == '*') {
							counts++;
						}
					}
				}
				num[i][j] = counts;
			}
		}
		int counts = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (num[i][j] == -1) continue;
				if (num[i][j] == 0) {
					counts++;
					dfs(i, j);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (num[i][j] != -1) counts++;
			}
		}
		cout << "Case #" << cas << ": " << counts << endl;
	}
}