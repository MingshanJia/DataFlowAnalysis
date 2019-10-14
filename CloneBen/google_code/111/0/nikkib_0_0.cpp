#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int count;

	cin >> count;
	string temp;
	getline(cin, temp);
	for (int i = 1; i <= count; ++i) {
		cout << "Case #" << i << ":" << endl;
		string s;
		getline(cin, s);
		cout << "+-";
		for (int j = 0; j < s.length(); ++j) cout << "-";
		cout << "-+\n";
		cout << "| " << s << " |" << endl;
		cout << "+-";
		for (int j = 0; j < s.length(); ++j) cout << "-";
		cout << "-+\n";
	}
	return 0;
}
