#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define FILE_IN  "A-small-attempt0.in"
#define FILE_OUT "A-small-attempt0.out"

#define MAXN 50

void solve() {
	int n;
	scanf(" %d", &n);
	int row[MAXN];
	for (int i = 0; i < n; ++i) {
		row[i] = 0;
		char c;
		for (int j = 1; j <= n; ++j) {
			scanf(" %c", &c);
			if (c == '1')
				row[i] = j;
		}
	}
	int swaps = 0;
	for (int i = 1; i <= n; ++i) {
		int j = 0;
		int c = 0;
		for (; j < n; ++j) {
			if (row[j] < 0)
				continue;
			if (row[j] <= i)
				break;
			++c;
		}
		swaps += c;
		row[j] = -1;
	}
	printf("%d\n", swaps);
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
