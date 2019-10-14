#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int main()
{
	int T, R, C, ans, p[3];

	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d%d", &R, &C);
		if (R > C)
			swap(R, C);
		if (R == 1)
		{
			p[0] = p[1] = 1;
			p[2] = 0;
		}
		else if (R == 2)
		{
			p[0] = p[1] = 2;
			p[2] = 0;
		}
		else
		{
			p[0] = p[1] = p[2] = (R / 3) * 2;
			if (R % 3 == 1)
			{
				p[0]++;
				p[1]++;
			}
			else if (R % 3 == 2)
			{
				p[0] += 2;
				p[1]++;
				p[2]++;
			}
		}
		ans = 0;
		for (int i = 0; i < C; i++)
			ans += p[i % 3];
		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}