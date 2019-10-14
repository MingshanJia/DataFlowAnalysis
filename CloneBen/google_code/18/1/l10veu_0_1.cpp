#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int ps[3][3];
long long as[3];
long long bs[3];

int main()
{
	int t;
	scanf("%d", &t);
	for (int c=1; c<=t; ++c)
	{
		long long n;
		scanf("%lld %lld %lld %lld %lld %lld %lld", &n, &as[0], &as[1], &as[2], &bs[0], &bs[1], &bs[2]);
		for (int i=0; i<3; ++i)
		{
			for (int j=0; j<3; ++j)
				scanf("%d", &ps[i][j]);
		}

		int p1[3] = {0, 1, 2};
		int p2[3] = {0, 1, 2};

		long long ans = LLONG_MIN;
		
		do
		{
			do
			{
				int i1 = 0;
				int i2 = 0;
				long long res = 0;

				long long ta[3] = {as[p1[0]], as[p1[1]], as[p1[2]]};
				long long tb[3] = {bs[p2[0]], bs[p2[1]], bs[p2[2]]};

				while (i1 < 3 && i2 < 3)
				{
					if (ta[i1] > tb[i2])
					{
						res += ps[p1[i1]][p2[i2]] * tb[i2];
						ta[i1] -= tb[i2++];
					}
					else if (ta[i1] < tb[i2])
					{
						res += ps[p1[i1]][p2[i2]] * ta[i1];
						tb[i2] -= ta[i1++];
					}
					else
					{
						res += ps[p1[i1]][p2[i2]] * tb[i2];
						ta[i1++] = tb[i2++] = 0;
					}
				}

				if (res > ans)
					ans = res;

			} while(next_permutation(p2, p2+3));
		} while(next_permutation(p1, p1+3));
		
		printf("Case #%d: %lld\n", c, ans);
	}
	
	return 0;
}