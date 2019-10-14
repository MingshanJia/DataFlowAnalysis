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


int d[N][N];
double calc() {
	int b;
	cin >> b;
	vector <pair<pair<int, int>, int>> e;
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < b; j++) {
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	}
	for (int i = 1; i < b; i++) {
		for (int j = 0; j < i; j++) {
			int x;
			cin >> x;
			if (x == -1) continue;
			d[i][j] = d[j][i] = x;
			e.push_back(mp(mp(i, j), x));
		}
	}

	for (int k = 0; k < b; k++) {
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < b; j++) {
				d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
			}
		}
	}

	double ans = INF;
	for (int i = 0; i < e.size(); i++) {
		int cost = e[i].second;
		int v = e[i].first.first;
		int u = e[i].first.second;
		double l = 0;
		while (l <= cost) {
			double mx = 0;
			for (int j = 0; j < b; j++) {
				double len = d[v][j] + l;
				len = min(len, d[j][u] + cost - l);
				mx = max(len, mx);
			}
			ans = min(mx, ans);
			l += 0.5;
		}
	}
	return ans;
}
void solve() {
	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
		
		cout.precision(6);
		cout << "Case #" << q + 1 << ": " << fixed << calc() << endl;
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