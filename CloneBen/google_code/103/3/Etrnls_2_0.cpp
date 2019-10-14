#include <iostream>

using	namespace	std;

const	int	maxn = 1000;
const	int	maxm = 100;
const	int	moder = 1000000007;

int	n, cases;
int	a[maxm + 1];
int	x[maxn + 1];
int	f[maxn + 1];

void	init()
{
	int	m;
	long long X, y, z;
	scanf("%d%d%lld%lld%lld", &n, &m, &X, &y, &z);
	for (int i = 0; i < m; ++i)	scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i)
	{
		x[i] = a[i % m];
		a[i % m] = (X * a[i % m] + y * (i + 1)) % z;
	}
}

void	solve()
{
	f[0] = 1;
	for (int i = 1; i < n; ++i)
	{
		f[i] = 1;
		for (int j = 0; j < i; ++j)
			if (x[j] < x[i])
			{
				f[i] = static_cast<long long>(f[i] + f[j]) % moder;
			}
	}
	long long	ans = 0;
	for (int i = 0; i < n; ++i)
		ans = (ans + f[i]) % moder;
	printf("Case #%d: %lld\n", ++cases, ans);
}


int	main()
{
	int	t;
	scanf("%d", &t);
	while (t--)
	{
		init();
		solve();
	}
	return	0;
}

