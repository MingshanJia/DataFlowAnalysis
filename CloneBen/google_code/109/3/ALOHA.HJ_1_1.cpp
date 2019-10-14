#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
long long t, n, d,k, l ,r;
int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("bl.out", "w", stdout);
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		printf("Case #%d: ", tt);
		scanf("%lld%lld%lld", &d, &k, &n);
		if (k % 2)
		{
			n %= d;
			k += n;
			if (k == 0) k = d;
			l = (k + 1) % d;
			if (l == 0) l = d;
			r = (k - 1 + d) % d;
			if (r == 0) r = d;
			l = (l + n) % d;
			r = (r + n) % d;
			if (r == 0) r = d;
			if (l == 0) l = d;
			printf("%lld %lld\n", l, r);
		}
		else
		{
			n %= d;
			k =(k-n+d)%d;
			if (k == 0) k = d;

			l = (k + 1) % d;
			if (l == 0) l = d;
			r = (k - 1 + d) % d;
			if (r == 0) r = d;
			l = (l - n + d) % d;
			r = (r - n + d) % d;
			if (r == 0) r = d;
			if (l == 0) l = d;
			printf("%lld %lld\n", l, r);
		}
		
	}
return 0;
}