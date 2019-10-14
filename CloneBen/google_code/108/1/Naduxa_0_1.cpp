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

void solve() {
	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
		int f, s;
		cin >> f >> s;
		set<pair<int, int>> st;
		for (int i = 0; i < f; i++) {
			pair<int, int > a;
			cin >> a.first >> a.second;
			st.insert(a);
			st.insert(mp(a.second, a.first));
		}

		int mx = 0;
		for (int i = 1; i <= s; i++) {
			int t = 0;
			for (int j = 1; j <= s; j++) {
				if (st.count(mp(i, j))) {
					t++;
				}
			}
			mx = max(t, mx);
		}

		cout << "Case #" << q + 1 << ": " << mx << endl;
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