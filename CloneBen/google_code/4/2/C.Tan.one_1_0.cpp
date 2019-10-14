#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

const string file = "B-small-attempt2";

int r, c;
int s[10][10];

bool check(int x){
	int a = 0;
	for (int i = 0; i < r; ++ i){
		for (int j = 0; j < c; ++j){
			s[i][j] = ((x >> a) & 1);
			++a;
		}
	}
	for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j){
			if (s[i][j]){
				if (0 < i && i < r - 1 && (s[i-1][j] && s[i+1][j]))
					return false;
				if (0 < j && j < c - 1 && (s[i][j-1] && s[i][j+1]))
					return false;
			}
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	freopen((file + ".in").c_str(), "r", stdin);
	freopen((file + ".out").c_str(), "w", stdout);
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; ++test){
        cin >> r >> c;
	int ans = 0;
	for (int i = 0; i < (1 << (r * c)); ++i){
		if (check(i)){
			int a = i, x, tmp = 0;
			while (x = (a & -a)){
				a -= x;
				++tmp;
			}
			if (ans < tmp){
				ans = tmp;
			}
		}
	}
	cout << "Case #" << test + 1 << ": " << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
