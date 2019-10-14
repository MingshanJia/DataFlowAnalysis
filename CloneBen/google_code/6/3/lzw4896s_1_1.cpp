#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define N 5000010

char str[N];
int s[N];


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("B.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas)
	{
		int n;
		scanf("%d", &n);
		scanf("%s", str + 1);
		for (int i = 1; i <= n; ++i)
			s[i] = s[i - 1] + str[i] - '0';
		int ans = 0, m = (n + 1) / 2;
		for (int i = m; i <= n; ++i)
			ans = max(ans, s[i] - s[i - m]);
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
