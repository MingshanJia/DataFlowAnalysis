#include <iostream>
using namespace std;

int loc[500][2];
int counts[50001];

int main() {
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		int N;
		cin >> N;
		memset(counts, 0, sizeof(counts));
		for (int i = 0; i < N; i++) {
			cin >> loc[i][0] >> loc[i][1];
			for (int j = loc[i][0]; j <= loc[i][1]; j++) {
				counts[j]++;
			}
		}
		int P;
		cin >> P;
		cout << "Case #" << cas << ":";
		while (P--) {
			int query;
			cin >> query;
			cout << " " << counts[query];
		}
		cout << endl;
	}
}