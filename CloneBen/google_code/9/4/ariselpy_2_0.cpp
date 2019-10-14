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
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt, cas = 0, i, j, n, flag, K;
	cin >> tt;
	while (tt --) {
		printf("Case #%d: ", ++cas);
		cin >> n >> K;
		for (i = 1; i <= n; i ++) scanf("%d", a + i);
		flag = 1;
		while (flag) {
			flag = 0;
			for (i = 1; i <= n - 2; i ++)
				if (a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
					for (j = i; j <= n - 3; j ++) a[j] = a[j + 3];
					n -= 3;  flag = 1; break;
				}
		}
		cout << n << endl;
	}
	return 0;
}
