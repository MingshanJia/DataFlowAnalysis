#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

const int MAXN = 110;

int fx[MAXN];
int fy[MAXN];
bool used[MAXN];

void solve() {
	int s;
	int n;
	memset(fx, 0, sizeof(fx));
	memset(fy, 0, sizeof(fy));

	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &fx[i], &fy[i]);
	}

	int result = 0;
	for (int row = 1; row <= s; ++row) {
		memset(used, 0, sizeof(used));
		int curFriends = 0;
		for (int i = 0; i < n; ++i) {
			if (fx[i] == row && !used[fy[i]]) {
				used[fy[i]] = true;
				curFriends++;
				continue;
			}
			if (fy[i] == row && !used[fx[i]]) {
				used[fx[i]] = true;
				curFriends++;
				continue;
			}
		}
		result = max(result, curFriends);
	}
	printf("%d", result);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
}
