#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long int64;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

int Diff(int h1, int h2) {
	int res = h2 - h1;
	if (res < 0) {
		res += 24;
	}
	return res;
}

int Get(vector<int>& p, int v) {
	if (p[v] == v) {
		return v;
	}
	p[v] = Get(p, p[v]);
	return p[v];
}

void Unite(vector<int>& p, vector<int>& rk, int v1, int v2) {
	v1 = Get(p, v1);
	v2 = Get(p, v2);

	if (v1 == v2) {
		return;
	}

	if (rk[v1] < rk[v2]) {
		swap(v1, v2);
	}

	p[v2] = v1;
	if (rk[v1] == rk[v2]) {
		++rk[v1];
	}
}

int main () {
    ios_base::sync_with_stdio(0);
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

    int tc;
	cin >> tc;
	for (int ti = 0; ti < tc; ++ti) {
		int n;
		cin >> n;

		vector<vector<pair<int, int>>> st(n);
		vector<vector<pair<int, int>>> fin(n);
		
		int res = 0;
		for (int i = 0; i < 2 * n; ++i) {
			int v1 = i / 2;
			int v2, h, d;
			cin >> v2 >> h >> d;

			res += d;
			
			--v2;
			st[v1].pb(mp(i, h));
			fin[v2].pb(mp(i, (h + d) % 24));
		}

		vector<int> p(2 * n);
		vector<int> rk(2 * n, 0);
		for (int i = 0; i < 2 * n; ++i) {
			p[i] = i;
		}

		vector<pair<int, pair<int, int>>> edg(n);
		for (int i = 0; i < n; ++i) {
			int diff00 = Diff(fin[i][0].sc, st[i][0].sc);
			int diff01 = Diff(fin[i][0].sc, st[i][1].sc);
			int diff10 = Diff(fin[i][1].sc, st[i][0].sc);
			int diff11 = Diff(fin[i][1].sc, st[i][1].sc);

	        int add0 = diff00 + diff11;
	        int add1 = diff01 + diff10;
	        if (i == 0) {
	        	add0 = min(diff00 + st[i][1].sc, diff11 + st[i][0].sc);
	        	add1 = min(diff01 + st[i][0].sc, diff10 + st[i][1].sc);
	        }
		
		    if (add0 < add1) {
		    	res += add0;
		    	Unite(p, rk, st[i][0].fs, fin[i][0].fs);
		    	Unite(p, rk, st[i][1].fs, fin[i][1].fs);
		    	edg.pb(mp(add1 - add0, mp(st[i][0].fs, fin[i][1].fs)));
		    } else {
		    	res += add1;
		    	Unite(p, rk, st[i][0].fs, fin[i][1].fs);
		    	Unite(p, rk, st[i][1].fs, fin[i][0].fs);
		    	edg.pb(mp(add0 - add1, mp(st[i][0].fs, fin[i][0].fs)));
		    }
		}

		sort(edg.begin(), edg.end());
		for (int i = 0; i < sz(edg); ++i) {
			if (Get(p, edg[i].sc.fs) != Get(p, edg[i].sc.sc)) {
				res += edg[i].fs;
				Unite(p, rk, edg[i].sc.fs, edg[i].sc.sc);
			}
		}


		cout << "Case #" << ti + 1 << ": " << res << endl;
	}


	return 0;
}
