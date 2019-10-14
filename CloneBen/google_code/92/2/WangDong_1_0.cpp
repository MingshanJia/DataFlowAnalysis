#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int	n , m , F;
char	mat	[52][52];
int	opt	[52][52][52];

void	init()
{
	scanf("%d%d%d", &n , &m , &F);

	for (int i = 0; i < n; i ++)
		scanf("%s", mat[i]);
}

inline	bool	is_empty(int i, int j, int k, int p)
{
	if (min(j,k) <= p && p <= max(j,k)) return 1;
	return mat[i][p] == '.';
}

inline	bool	way_exist(int i, int j, int k, int st, int ed)
{
	int	aa = min(st, ed);
	int	bb = max(st, ed);
	for (int xx = aa; xx <= bb; xx ++)
	{
		if (! is_empty(i,j,k,xx)) return 0;
		if (xx != ed && mat[i + 1][xx] == '.') return 0;
	}
	return 1;
}

inline	void	renew(int& x, int x0)
{
	if (x0 < x) x = x0;
}

void	solve()
{
	memset(opt, 0x3f, sizeof(opt));
	opt[0][0][0] = 0;

	int	i, j, k;
	
	int	p, x, dig;

	for (i = 0; i + 1 < n; i ++)
	{
		for (j = 0; j < m; j ++)
			for (k = 0; k < m; k ++)
			{
				if (opt[i][j][k] >= 2500) continue;
				
				for (p = 0; p < m; p ++)
					if (way_exist(i, j, k, j, p))
					{
						int tar = i + 1;
						while (tar + 1 < n && mat[tar + 1][p] == '.')
							tar ++;
						if (tar - i > F) continue;
						if (mat[i+1][p] == '.')
							renew(opt[tar][p][p],  opt[i][j][k]);
						else {
							if ((p > 0 && is_empty(i,j,k,p-1) && mat[i+1][p-1] == '#')
								|| (p < m - 1 && is_empty(i,j,k,p+1) && mat[i+1][p+1] == '#'))
							{
								renew(opt[tar][p][p],1 + opt[i][j][k]);
							}
						}

						if (tar == i + 1 && mat[i + 1][p] == '#')
						{
							if (p != m - 1 && is_empty(i, j, k, p+1) && mat[i+1][p+1] == '#')
							{
								dig = 2;
								for (x = p; x - 1 >= 0; x --, dig ++)
								{
									if (! is_empty(i, j, k, x)) break;
									if (mat[i+1][x] == '.') break;
									if (! is_empty(i, j, k, x-1)) break;
									renew(opt[tar][p][x - 1], opt[i][j][k] + dig);
								}
							}
							if (p != 0 && is_empty(i, j, k, p-1) && mat[i+1][p - 1] == '#')
							{
								dig = 2;
								for (x = p; x + 1 < m; x ++, dig ++)
								{
									if (! is_empty(i, j, k, x)) break;
									if (mat[i+1][x] == '.') break;
									if (! is_empty(i, j, k, x+1)) break;
									renew(opt[tar][p][x+1], opt[i][j][k] + dig);
								}
							}
						}
					}
			}
	}

	int	ans = 2500;

	for (j = 0; j < m; j ++)
		for (k = 0; k < m; k ++)
		{
			ans = min(ans, opt[n - 1][j][k]);
		}


	if (ans < 2500) printf("Yes %d\n", ans);
	else printf("No\n");
}

int	main()
{
	freopen("B-small-attempt2.in", "r", stdin);
//	freopen("in.txt", "r", stdin);
	freopen("B-small-2.out", "w", stdout);

	int	T;
	scanf("%d", &T);
	
	for (int t = 1; t <= T; t ++)
	{
		printf("Case #%d: ", t);

		init();
		solve();
	}

	return 0;
}
