#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <ctime>

using namespace std;

int n, v[5100000];
char s[5100000];
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int ca = 0;
	int T;
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		scanf(" %s", s);
		int m = strlen(s);
		int sum = 0;
		int best = 0;
		for (int i = 0; i < m; i++) {
			v[i] = s[i] - '0';
			sum += v[i];
			if (i >= (m + 1) / 2)
				sum -= v[i - (m + 1) / 2];
			best = max(sum, best);
		}
		printf("Case #%d: ", ++ca);
		cout << best << endl;
	}
}

