#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

const string file = "B-large";

int ans;
int r, c;

void dfs(int x){
	int i = 0, j = x, tmp = 0;
	while (1){
		if (j > c) break;
		tmp += min(r - i, c - j);
		j += 3;
	}
	j = 0, i = 3 - x;
	while (1){
		if (i > r) break;
		tmp += min(r - i, c - j);
		i += 3;
	}
	ans = min(ans, tmp);
}

int main(){
	ios::sync_with_stdio(false);
	freopen((file + ".in").c_str(), "r", stdin);
	freopen((file + ".out").c_str(), "w", stdout);
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; ++test){
		cin >> r >> c;
		if (min(r, c) <= 2){
            int x = max(r, c);
            ans = (x / 3 * 2 + x % 3) * min(r, c);
            cout << "Case #" << test + 1 << ": " << ans << endl;
            continue;
		}
		ans = r * c;
		for (int i = 0; i < 3; ++i){
			dfs(i);
		}
		cout << "Case #" << test + 1 << ": " << r * c - ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
