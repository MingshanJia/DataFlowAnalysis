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
const int N = 55 + 5;
double p[N];
const int INF = 1e9 + 5;
int n;
int a[N][N];

double opt = 0.0;

double tern(int from, int to, double we1, double we2) {
	double mx = 0.0;
	for (int i = 0; i < n; i++) {
		double tek = min(a[from][i] + we1, a[to][i] + we2);
		mx = max(mx, tek);
	}
	opt = min(opt, mx);
	return mx;
}

int main() {
#ifdef _DEBUG
#endif
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	cout.sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int test = 0; test < t; test++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)
					a[i][j] = 0;
				else 
					a[i][j] = INF;
			}
		}
		vector<pair<pair<int, int>, int>> w;
		for (int i = 1; i <= n - 1; i++) {
			for (int j = 0; j < i; j++) {
				int x;
				cin >> x;
				if (x == -1) continue;
				a[j][i] = a[i][j] = x;
				w.push_back(make_pair(make_pair(i, j), x));
			
				//cout << "re" <<  i + 1 << " " << j + 1 << " " << x << endl;
			}
		}

		for (int i = 0; i < n; i++)
			a[i][i] = 0;

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
				}
			}
		}

		opt = 1e9;

		for (int i = 0; i < w.size(); i++) {
			int from = w[i].first.first;
			int to = w[i].first.second;
			double len = w[i].second;
			double l = 0.0;
			double r = len;

			for (int it = 0; it < 300; it++) {
				double mid1 = l + (r - l) / 3;
				double mid2 = r - (r - l) / 3;

				if (tern(from, to, mid1, len - mid1) < tern(from, to, mid2, len - mid2)) {
					r = mid2;
				}
				else {
					l = mid1;
				}
			}

			double mid = (l + r) / 2;
			tern(from, to, mid, len - mid);
		}

		cout.precision(6);
		cout << "Case #" << test + 1 << ": " << fixed << opt << endl;
		
	}
	return 0;
}