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
double ans0[500][500], ans1[500][500];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt, cas = 0, B, L, N, i, j, k;
	cin >> tt;
	while (tt --) {
		printf("Case #%d: ", ++cas);
		cin >> B >> L >> N;
		ans0[1][1] = B * 750;
		for (i = 1; i < L; i ++) {
			for (j = 1; j <= i + 1; j ++)
				for (k = 1; k <= j; k ++) ans1[j][k] = 0;

			for (j = 1; j <= i; j ++)
				for (k = 1; k <= j; k ++)
					if (ans0[j][k] > 250) {
						ans1[j][k] += (ans0[j][k] - 250) / 3;
						ans1[j + 1][k] += (ans0[j][k] - 250) / 3;
						ans1[j + 1][k + 1] += (ans0[j][k] - 250) / 3;
						ans0[j][k] = 250;
					}
			for (j = 1; j <= i + 1; j ++)
				for (k = 1; k <= j; k ++) ans0[j][k] = ans1[j][k];
		}
		for (i = 1; i <= L; i ++)
			if (N <= i) break;
			else N-= i;
		if (ans0[i][N] > 250) ans0[i][N] = 250;
		printf("%.7lf\n", ans0[i][N]); 
	}
	return 0;
}
