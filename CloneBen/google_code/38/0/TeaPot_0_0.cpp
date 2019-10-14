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

void Go(vector<int>& val, int len, int ind, int sum_left, int cur) {
	if (ind == len) {
		if (cur != 0) {
	    	val.pb(cur);
		}
		return;
	}

	for (int i = 0; i <= min(sum_left, len); ++i) {
	    Go(val, len, ind + 1, sum_left - i, cur * 10 + i);
	}
}

int Next(int cur, int len) {
	vector<int> num(10);
	for (int i = 0; i < len; ++i) {
		++num[cur % 10];
		cur /= 10;
	}

	int res = 0;            
	for (int i = 1; i <= len; ++i) {
		res = res * 10 + num[i];
	}

	return res;
}

int main () {
    ios_base::sync_with_stdio(0);
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	vector<vector<int>> val(10);
	for (int len = 1; len < 10; ++len) {
		Go(val[len], len, 0, len, 0);
	}

	vector<int> fact(10);
	fact[0] = 1;
	for (int i = 1; i < 10; ++i) {
		fact[i] = i * fact[i - 1];
	}

	vector<vector<int>> num_from(10);
	for (int len = 1; len < 10; ++len) {
		num_from[len].resize(sz(val[len]));
		for (int i = 0; i < sz(val[len]); ++i) {
			int cur = val[len][i];
			vector<int> num(10);
			for (int j = 0; j < len; ++j) {
				num[len - j] = cur % 10;
				cur /= 10;
			}
			
			num[0] = len;
			for (int j = 1; j <= len; ++j) {
				num[0] -= num[j];
			}

			num_from[len][i] = fact[len];
			for (int j = 0; j <= len; ++j) {
				num_from[len][i] /= fact[num[j]];
			}
		}
	}

    vector<int> fin(10);
    for (int len = 1; len < 10; ++len) {
    	fin[len] = 1;
    	for (int i = 0; i < len - 1; ++i) {
			fin[len] *= 10;
    	}
    }
    
    int tc;
	cin >> tc;
	for (int ti = 0; ti < tc; ++ti) {
		string s;
		cin >> s;

		int len = sz(s);
		int x = stoi(s);

		int res = 0;
		for (int i = 0; i < sz(val[len]); ++i) {
			int cur = val[len][i];
			while (cur != fin[len] && cur != x) {
			    cur = Next(cur, len);
			}

			if (cur == x) {
				res += num_from[len][i];
			}
		}

		if (x != fin[len]) {
			++res;
		}

        cout << "Case #" << ti + 1 << ": " << res << endl;
	}


	return 0;
}
