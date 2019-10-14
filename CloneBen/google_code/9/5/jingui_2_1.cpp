#include <iostream>
#include <cstdio>
using namespace std;
int a[500], f[420][420];
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t, T = 0, n, dif, k, i, j, ll, l;
	cin >> t;
	while (t --) {
		cin >> n >> dif;
		for (i = 1; i <= n; i ++)
			scanf("%d", a + i);

		for (i = 1; i <= n; i ++)
			for (j = 1; j <= n; j ++)
				if (j < i)
                    f[i][j] = 0;
				else
				f[i][j] = j - i + 1;

		for (ll = 2; ll < n; ll ++) {
			for (i = 1; i <= n - ll; i ++) {
				j = i + ll;
				for (k = i + 1; k < j; k ++)
					if (a[i] + dif == a[k] && f[i + 1][k - 1] == 0)
					for (l = k + 1; l <= j; l ++)
						if (a[k] + dif == a[l] && f[k + 1][l - 1] == 0)
							if (f[l + 1][j] < f[i][j])
                                f[i][j] = f[l + 1][j];
				f[i][j] = min(f[i][j], f[i + 1][j] + 1);
			}
		}
		printf("Case #%d: ", ++T);
		cout << f[1][n] << endl;
	}
	return 0;
}
