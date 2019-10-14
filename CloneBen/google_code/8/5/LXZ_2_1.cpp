#include <iostream>
using namespace std;

int input[10];
bool available[1001000];
int clicks[1001000];
bool hasdp[1001000];
int dpvalue[1001000];
int dp(int number) {
	if (hasdp[number]) return dpvalue[number];
	hasdp[number] = true;
	int ans = -1;
	if (available[number]) ans = clicks[number];
	for (int i = 2; i*i <= number; i++) {
		if (number%i) continue;
		int temp1 = dp(i);
		if (temp1 == -1) continue;
		int temp2 = dp(number / i);
		if (temp2 == -1) continue;
		if (ans == -1 || temp1 + temp2 < ans) {
			ans = temp1 + temp2;
		}
	}
	dpvalue[number] = ans;
	return ans;
}

int main() {
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		int target;
		for (int i = 0; i < 10; i++) {
			cin >> input[i];
		}
		cin >> target;
		for (int i = 1; i <= target; i++) {
			int temp = i;
			bool flag = true;
			int click = 0;
			while (temp && flag) {
				if (input[temp % 10] == 0) flag = false;
				temp /= 10;
				click++;
			}
			available[i] = flag;
			clicks[i] = click + 1;
		}
		memset(hasdp, 0, sizeof(hasdp));
		cout << "Case #" << cas << ": ";
		int ans = dp(target);
		if (ans == -1) cout << "Impossible" << endl;
		else cout << ans << endl;
	}
}