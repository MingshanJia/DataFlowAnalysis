#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define ll long long
#define pb push_back 
#define mp make_pair
#define FOR(x, l, r) for(x = (l); x <= (r); x++)
#define FORD(x, r, l) for(x = (r); x >= (l); x --)
using namespace std;
ll c[300][300], f[300][300];
int mo = 1000000007;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt, n, m, i, j, k, cas = 0;
	c[0][0] = 1;
	for (i = 1; i <= 200; i ++) {
		c[i][0] = 1;
		for (j = 1; j <= 200; j ++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mo;
	}
	for (i = 1; i <= 200; i ++) f[1][i] = 1;
	for (i = 2; i <= 200; i ++)
		for (j = i; j <= 200; j ++) {
			for (k = 1; k <= j - i + 1; k ++)
				f[i][j] = (f[i][j] + f[i - 1][j - k] * c[j][k]) % mo;
		}
	cin >> tt;
	while (tt --) {
		printf("Case #%d: ", ++cas);
		cin >> n >> m;
		cout << f[n][m] << endl;
	}
	return 0;
}
