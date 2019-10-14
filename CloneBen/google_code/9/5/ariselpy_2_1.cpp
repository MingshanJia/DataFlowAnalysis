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
int a[1000];
int f[200][200];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt, cas = 0, i, j, n, K, k, len, l;
	cin >> tt;
	while (tt --) {
		printf("Case #%d: ", ++cas);
		cin >> n >> K;
		for (i = 1; i <= n; i ++) scanf("%d", a + i);
		for (i = 1; i <= n; i ++)
			for (j = 1; j <= n; j ++)
				if (j < i) f[i][j] = 0;
				else f[i][j] = j - i + 1;
		//for (i = 1; i <= n; i ++) f[i][i] = 1;
		//for (i = 1; i <= n - 1; i ++) f[i][i + 1] = 2;
		for (i = 1; i <= n - 2; i ++)
			if (a[i] + K == a[i + 1] && a[i + 1] + K == a[i + 2]) f[i][i + 2] = 0;
				else f[i][i + 2] = 3;
		for (len = 3; len < n; len ++) {
			for (i = 1; i <= n - len; i ++) {
				j = i + len;
				for (k = i + 1; k < j; k ++)
					if (f[i + 1][k - 1] == 0 && a[i] + K == a[k])
					for (l = k + 1; l <= j; l ++)
						if (f[k + 1][l - 1] == 0 && a[k] + K == a[l])
							f[i][j] = min(f[i][j], f[l + 1][j]);
				f[i][j] = min(f[i][j], f[i + 1][j] + 1);
				f[i][j] = min(f[i][j], f[i][j - 1] + 1);
			}
		}
		cout << f[1][n] << endl;
	}
	return 0;
}
