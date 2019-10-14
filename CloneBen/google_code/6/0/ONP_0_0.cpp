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

int pre[11000];
int trie[11000][20];
long long ans;
int n, p, tot, now;
char s[1100];
void dfs(int a, int len)
{
	if (pre[a])
		ans -= (1LL << (n - len));
	else 
		for (int i = 0; i < 2; i++)
			if (trie[a][i])
				dfs(trie[a][i], len + 1);
}
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int ca = 0;
	int T;
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &p);
		tot = 0;
		memset(trie, 0, sizeof trie);
		memset(pre, 0, sizeof pre);
		for (int i = 0; i < p; i++) {
			scanf(" %s", s);
			now = 0;
			int m = strlen(s);
			int ne;
			for (int j = 0; j < m; j++) {
				if (s[j] == 'R')
					ne = 0;
				else ne = 1;
				if (!trie[now][ne])
					trie[now][ne] = ++tot;
				now = trie[now][ne];
			}
			pre[now] = 1;
		}
		printf("Case #%d: ", ++ca);
		ans = (1LL << n);
		dfs(0, 0);
		cout << ans << endl;
	}
}

