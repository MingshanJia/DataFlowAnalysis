#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m;
int ans, res[8];
int g[8][8], x[8], p[10], q[10];
vvi w;

int go (int i, int j) {
	if (i == n) {
		int ok = 1;
		for (int k = 0; k < sz (w); k++) {
			int mask = 0;
			for (int l = 0; l < sz (w[k]); l++)
				mask |= 1 << x[w[k][l]];
			if (mask + 1 != (1 << j)) { ok = 0; break; }
		}
		if (ok && j > ans) {
			ans = j;
			for (int k = 0; k < n; k++) res[k] = x[k];
		}
		re 0;
	}
	for (int k = 0; k <= j; k++) {
		x[i] = k;
		go (i + 1, j + int (k == j));
	}
	re 0;
}

int main() {
	int tt;
	scanf ("%d", &tt);
	for (int it = 1; it <= tt; it++) {
	        scanf ("%d%d", &n, &m);
	        for (int i = 0; i < m; i++) { scanf ("%d", &p[i]); p[i]--; }
	        for (int i = 0; i < m; i++) { scanf ("%d", &q[i]); q[i]--; }
	        for (int i = 0; i < n; i++)
	        	for (int j = 0; j < n; j++)
	        		g[i][j] = 0;
	        for (int i = 0; i < n; i++)
	        	g[i][(i + 1) % n] = g[(i + 1) % n][i] = 1;
	       	for (int i = 0; i < m; i++)
	       		g[p[i]][q[i]] = g[q[i]][p[i]] = 1;
	       	w.clear ();
	        for (int i = 1; i < (1 << n); i++) {
	        	vi v;
	        	for (int j = 0; j < n; j++)
	        		if ((i >> j) & 1)
	        			v.pb (j);
	        	if (sz (v) > 2) {
	        		int ok = 1;
	        		for (int j = 0; j < sz (v); j++)
	        			ok &= int (g[v[j]][v[(j + 1) % sz (v)]]);
	        		for (int j = 0; j < sz (v); j++)
	        			for (int k = j + 2; k < sz (v); k++)
	        				if ((k + 1) % sz (v) != j)
	        					ok &= int (g[v[j]][v[k]] == 0);
	        		if (ok) w.pb (v);
	        	}
	        }
	        ans = 0;
	        go (0, 0);
		printf ("Case #%d: %d\n", it, ans);
		for (int k = 0; k < n; k++) {
			if (k > 0) printf (" ");
			printf ("%d", res[k] + 1);
		}
		printf ("\n");
	}
	return 0;
}