#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <fstream>
#include <string> 

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define forit(it, s) for (__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(),a.end()

const int inf = (int)1e9;
const int mod = (int)1e9 + 7;

string a, b, c;

pair<char, char> get(string a, string b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) return mp(a[i], b[i]);
	}
}

bool can(string a, string b, string c) {
	pair<char, char> x = get(a, b);
	pair<char, char> y = get(b, c);
	//cout << a << " " << b << " " << c << endl;
	//cout << x.f << " " << x.s << " = " << y.f << " " << y.s << endl;
	if (x.f == y.s && x.s == y.f) return false;
	return true;
}

void solve(string a, string b, string c) {
	if (can(b, a, c) || can(c, a, b)) cout << " YES";
	else cout << " NO";
}

void solve(int case_num) {
	int n;
	cin >> n >> a >> b >> c;
	cout << "Case #" << case_num << ":";
	//cout << can(b, a, c) << endl;
	//exit(0);
	solve(a, b, c);
	solve(b, a, c);
	solve(c, a, b);
	cout << endl;
}

int main() {

	int t;

	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(i);
	}

	return 0;
}
