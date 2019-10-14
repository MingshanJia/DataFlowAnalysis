#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<string> vs;
	string name;
	for(int cs = 1; cs <= n; ++cs) {
		int n;
		cin >> n;
		getline(cin, name);
		vs.clear();
		for(int i = 0; i < n; ++i) {
			getline(cin, name);
			vs.push_back(name);
		}
		int cnt = 0;
		for(int i = 1; i < n; ++i) {
			if(vs[i] < vs[i - 1])
				++cnt;
			int j = i;
			while(j > 0 && vs[j] < vs[j - 1]) {
				swap(vs[j], vs[j - 1]);
				--j;
			}
		}
		cout << "Case #" << cs << ": " << cnt << endl;
	}
	return 0;
}
