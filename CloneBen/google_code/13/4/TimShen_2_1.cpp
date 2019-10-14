#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int ca = 1; ca <= T; ca++) {
		int n;
		cin >> n;
		cin.get();
		string s;
		vector<string> v;
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			v.push_back(s);
		}
		int ans = 0;
		for (int i = 1; i < n; i++) {
			if (v[i] < v[i-1]) {
				ans++;
				v[i] = v[i-1];
			}
		}
		cout << "Case #" << ca << ": " << ans << "\n";
	}
	return 0;
}
