#include <iostream>
#include <string>
using namespace std;

int map[30][30];

int main() {
	freopen("B-small-attempt0.in","r",stdin);
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		int n;
		cin >> n;
		string dir;
		cin >> dir;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		if (dir == "right") {
			for (int i = 0; i < n; i++) {
				int cur = 0;
				int pos = n - 1;
				for (int j = n - 1; j >= 0; j--) {
					if (map[i][j] == 0) continue;
					int temp = map[i][j];
					map[i][j] = 0;
					if (temp == cur) {
						cur *= 2;
						map[i][pos] = cur;
						pos--;
						cur = 0;
					}
					else if (cur) {
						map[i][pos] = cur;
						pos--;
						cur = temp;
					}
					else {
						cur = temp;
					}
				}
				if (cur) {
					map[i][pos] = cur;
				}
			}
		}
		else if (dir == "left") {
			for (int i = 0; i < n; i++) {
				int cur = 0;
				int pos = 0;
				for (int j = 0; j < n; j++) {
					if (map[i][j] == 0) continue;
					int temp = map[i][j];
					map[i][j] = 0;
					if (temp == cur) {
						cur *= 2;
						map[i][pos] = cur;
						pos++;
						cur = 0;
					}
					else if (cur) {
						map[i][pos] = cur;
						pos++;
						cur = temp;
					}
					else {
						cur = temp;
					}
				}
				if (cur) {
					map[i][pos] = cur;
				}
			}
		}
		else if (dir == "up") {
			for (int j = 0; j < n; j++) {
				int cur = 0;
				int pos = 0;
				for (int i = 0; i < n; i++) {
					if (map[i][j] == 0) continue;
					int temp = map[i][j];
					map[i][j] = 0;
					if (temp == cur) {
						cur *= 2;
						map[pos][j] = cur;
						pos++;
						cur = 0;
					}
					else if (cur) {
						map[pos][j] = cur;
						pos++;
						cur = temp;
					}
					else {
						cur = temp;
					}
				}
				if (cur) {
					map[pos][j] = cur;
				}
			}
		}
		else if (dir == "down") {
			for (int j = 0; j < n; j++) {
				int cur = 0;
				int pos = n - 1;
				for (int i = n - 1; i >= 0; i--) {
					if (map[i][j] == 0) continue;
					int temp = map[i][j];
					map[i][j] = 0;
					if (temp == cur) {
						cur *= 2;
						map[pos][j] = cur;
						pos--;
						cur = 0;
					}
					else if (cur) {
						map[pos][j] = cur;
						pos--;
						cur = temp;
					}
					else {
						cur = temp;
					}
				}
				if (cur) {
					map[pos][j] = cur;
				}
			}
		}
		cout << "Case #" << cas << ":" << endl;
		for (int i = 0; i < n; i++) {
			cout << map[i][0];
			for (int j = 1; j < n; j++) {
				cout << " " << map[i][j];
			}
			cout << endl;
		}
	}
}
