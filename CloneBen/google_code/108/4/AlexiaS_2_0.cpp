#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <queue>
#include <numeric>
using namespace std;
typedef long long li;
#define mp make_pair
#define sz(a) (int)a.size()
const int N = 1e5 + 5;
double p[N];
int n;

int main() {
#ifdef _DEBUG
	freopen("C-small-attempt1.in",  "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout.sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int test = 0; test < t; test++) {
		int d, n;
		cin >> d >> n;
		vector<string> s(d);
		for (int i = 0; i < d; i++) {
			if (i & 1) {
				while (n > 0 && s[i].size() + 3 <= d) {
					s[i] += "I/O";
					n--;
				}
				while (s[i].size() + 1 <= d) {
					s[i] += "O";
				}
			}
			else {
				while (s[i].size() + 1 <= d) {
					s[i] += "I";
				}
			}
		}
		assert(n == 0);
		cout << "Case #" << test + 1 << ":" << endl;
		for (int i = 0; i < d; i++) {
			cout << s[i] << endl;
		}
	}
	return 0;
}