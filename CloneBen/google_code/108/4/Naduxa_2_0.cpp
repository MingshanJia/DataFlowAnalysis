#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
#include <algorithm>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <string>
#include <queue>
#include <random> 
#include <map>
#include <numeric>
using namespace std;
typedef long long li;
#define mp make_pair
#define sz(a) (int)a.size()
const int N = 1e3 + 5;
const int INF = 1e9 + 7;
char c[N];
string s[N];

void calc() {
	int n, d;
	cin >> d >> n;
	vector <string> ans;
	for (int i = 0; i < d; i++) {
		string s = "";
		if (i % 2 == 1) {
			for (int j = 0; j < d; j++) {
				s += "I";
			}
			ans.push_back(s);
			continue;
		}
		for (int j = 0; j < d; j += 3) {
			if (j + 3 >= d) {
				for (int k = 0; k < d - j; k++) {
					s += "I";
				}
				continue;
			}
			if (n > 0) {
				s += "I/O";
				n--;
			}
			else {
				s += "III";
			}
			
		}
		ans.push_back(s);
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}
void solve() {
	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
		
		cout << "Case #" << q + 1 <<  ":" <<endl;
		calc();
 	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout.sync_with_stdio(false);
	cin.tie(0);
	srand(time(NULL));
	solve();

	return 0;
}