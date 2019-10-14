#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	int nt, it;
	
	cin >> nt;
	for (it = 1; it <= nt; it++) {
		string s;
		int i, t = 0;
		map<char, int> m;
		long long r = 0;
		
		cin >> s;
		for (i = 0; i < s.size(); i++) {
			if (m.find(s[i]) == m.end()) m[s[i]] = t++;
		}
		if (t == 1) m[0] = t++;
		for (i = 0; i < s.size(); i++) {
			r = r * t + (m[s[i]] < 2 ? !m[s[i]] : m[s[i]]);
		}
		
		cout << "Case #" << it << ": " << r << '\n';
	}
	
	return 0;
}
