#include <iostream>
using namespace std;

int loc[1000001][2];

int main() {
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		int S;
		cin >> S;
		for (int i = 0; i < S; i++) {
			for (int j = 0; j < S; j++) {
				int map;
				cin >> map;
				loc[map][0] = i;
				loc[map][1] = j;
			}
		}
		int ans = -1, step = -1;
		int prex = -100, prey = -100;
		int tempans = 0;
		for (int i = S*S; i >= 1; i--) {
			int x = loc[i][0];
			int y = loc[i][1];
			if (abs(x - prex) + abs(y - prey) == 1) {
				tempans++;
			}
			else {
				tempans = 1;
			}
			if (tempans >= step) {
				step = tempans;
				ans = i;
			}
			prex = x;
			prey = y;
		}
		cout << "Case #" << cas << ": " << ans << " " << step << endl;
	}
}