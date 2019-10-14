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
int a[N], b[N];

int main() {
#ifdef _DEBUG
	freopen("ASMALL.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout.sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int test = 0; test < t; test++) {
		int f, s;
		cin >> f >> s;
		set<pair<int, int>> q;
		for (int i = 0; i < f; i++) {
			cin >> a[i] >> b[i];
			q.insert(make_pair(a[i], b[i]));
			q.insert(make_pair(b[i], a[i]));
		}

		int ans = 0;
		for (int i = 1; i <= s; i++) {
			int temp_ans = 0;
			for (int j = 1; j <= s; j++) {
				if (q.count(make_pair(i, j)) > 0)
					temp_ans++;
			}
			ans = max(ans, temp_ans);
		}
		cout << "Case #" << test + 1 << ": " << ans << endl;
	}
	return 0;
}