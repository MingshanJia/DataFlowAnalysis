#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
long long t, n, p[105];
int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("asmall.out", "w", stdout);
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		printf("Case #%d: ", tt);
		map<int, int> m;
		scanf("%lld", &n);
		n <<= 1;
		for (int i = 0; i < n; i++)
			scanf("%lld", p + i);
		for (int i = 0; i < n; i++)
		{
			if (m[p[i]])
			{
				m[p[i]]--;
			}
			else
			{
				m[(p[i] * 4) / 3]++;
				printf("%lld ", p[i]);
			}
		}
		printf("\n");
	}
return 0;
}