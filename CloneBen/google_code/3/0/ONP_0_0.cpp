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

char s[1100];
int f[310];
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int ca = 0;
	int T;
	for (scanf("%d", &T); T; T--) {
		printf("Case #%d: ", ++ca);
		scanf("%s", s);
		int n = strlen(s);
		memset(f, -1, sizeof f);
		f[0] = 1;
		for (int i = 0; i < n; i++) {
			if (f[i] == -1) continue;
			if (f[i + 1] == -1 || f[i + 1] > f[i] + 1) {
				f[i + 1] = f[i] + 1;
			}
			for (int j = 0; j < i; j++)
				for (int k = j + 1; k <= i; k++) {
					int del = i + 1, len = k - j + 1;
					int cost = 2;
					while (true) {
						int flag = 1;
					//	cerr << flag << endl;
						for (int x = 0; x < len; x++)
							if (del + x >= n || s[del + x] != s[j + x]) {
								flag = 0;
								break;
							}
						if (!flag) {
							break;
						}
						if (f[del + len - 1] == -1 || f[del + len - 1] > f[i] + cost) {
							f[del + len - 1] = f[i] + cost;
						}
						del += len;
						cost++;
					}
				}
		}
		printf("%d\n", f[n - 1]);
	}
}

