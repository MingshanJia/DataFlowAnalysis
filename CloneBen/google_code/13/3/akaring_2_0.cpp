//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cctype>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#define REP(i,n) for (int i=0,n_=int(n); i<n_; ++i)
#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(),(c).end()
using namespace std; typedef long long lint;
template<typename T> inline void checkMin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (a < b) a = b; }

const int MAXL = 105;

vector<int> tov(string a) {
	while (!a.empty() && a[0] == ' ') {
		a.erase(a.begin());
	}
	while (!a.empty() && a.back() == ' ') {
		a.pop_back();
	}
	vector<int> x;
	for (char c: a) {
		int v;
		if (c == ' ') {
			v = 0;
		} else if (isupper(c)) {
			v = c - 'A' + 1;
		} else if (islower(c)) {
			v = c - 'a' + 27;
		} else {
			cerr << "invalid" << endl;
			exit(0);
		}
		x.push_back(v);
	}
	return x;
}

bool lex_less(string a, string b) {
	vector<int> x = tov(a), y = tov(b);
	REP (i, min(x.size(), y.size())) {
		if (x[i] != y[i]) {
			return x[i] < y[i];
		}
	}
	return x.size() < y.size();
}

int main() {
	char line[MAXL];
	int n_case;
	fgets(line, MAXL, stdin);
	sscanf(line, "%d", &n_case);
	for (int index = 1; index <= n_case; ++index) {
		int n;
		fgets(line, MAXL, stdin);
		sscanf(line, "%d", &n);
		string maxs;
		int ans = 0;
		REP (i, n) {
			fgets(line, MAXL, stdin);
			line[strlen(line) - 1] = '\0';
			if (lex_less(string(line), maxs)) {
				++ans;
			} else {
				maxs = string(line);
			}
		}
		printf("Case #%d: %d\n", index, ans);
	}
	return 0;
}
