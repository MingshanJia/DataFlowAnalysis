#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <cmath>
#include <cctype>
#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 1024 * 1024;
int dp[N];
int s[1024][1024];
int a[N];

int haha(int x) {
	return (x < 0)?(-x):x;
}

int main() {

	freopen("A-large.in","r",stdin);
	freopen("a-large.txt","w",stdout);

int zz;
	scanf("%d",&zz);
	for (int z = 1; z <= zz; ++z) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d",&s[i][j]);
				a[s[i][j]] = i * n + j;
			}
		}
		int m = n * n;
		dp[m] = 1;
		for (int i = m - 1; i; --i) {
			int x1 = a[i + 1] / n, y1 = a[i + 1] % n, x2 = a[i] / n, y2 = a[i] % n;
			if (haha(x1 - x2) + haha(y1 - y2) == 1) {
				dp[i] = dp[i + 1] + 1;
			}
			else {
				dp[i] = 1;
			}
		}
		int answer = 1;
		for (int i = 2; i <= m; ++i) {
			if (dp[i] > dp[answer]) {
				answer = i;
			}
		}
		printf("Case #%d: %d %d\n",z,answer,dp[answer]);	
	}
	return 0;
}

