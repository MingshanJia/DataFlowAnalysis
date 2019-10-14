#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define N 45010

int flag[120]; 
string s[120];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas)
	{
		printf("Case #%d: ", cas);
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= m; ++i)
			cin >> s[i], flag[i] = 0;
		LL ans = 1LL << n;
		sort(s + 1, s + m + 1);
		for (int i = 1; i <= m; ++i)
			for (int j = i + 1; j <= m; ++j)
			{
				int len = s[i].size(), ff = 0;
				for (int k = 0; k < len; ++k)
					if (s[i][k] != s[j][k]) ff = 1;
				if (!ff) flag[j] = 1;
			}
		for (int i = 1; i <= m; ++i)
			if (!flag[i]) ans -= 1LL << (n - s[i].size());
		cout << ans << "\n";
	}
	return 0;
}
