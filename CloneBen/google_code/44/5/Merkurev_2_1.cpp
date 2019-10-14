#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int DX[4] = {0, -1, 0, 1};
const int DY[4] = {-1, 0, 1, 0};

const int N = 205;
int color[N];
char f[N][N];

int r, c;

void getPos(int from, int &sx, int &sy, int &sd)
{
	if (from < c)
	{
		sx = 0;
		sy = from;
		sd = 1;
	}
	else if (from < r + c)
	{
		sx = from - c;
		sy = c - 1;
		sd = 2;
	}
	else if (from < r + c + c)
	{
		sx = r - 1;
		sy = c - 1 - (from - r - c);
		sd = 3;
	}
	else
	{
		sx = r - 1 - (from - r - c - c);
		sy = 0;
		sd = 0;
	}
}

bool inF(int x, int y)
{
	return x >= 0 && x < r && y >= 0 && y < c;
}

bool makePath(int from, int to)
{
//	eprintf("%d -> %d\n", from, to);
	int sx, sy, sd;
	getPos(from, sx, sy, sd);
	int tx, ty, td;
	getPos(to, tx, ty, td);
	sx += DX[sd];
	sy += DY[sd];
	sd = (sd + 2) % 4;

	int it = 0;
	while (sx != tx || sy != ty || sd != td)
	{
		it++;
		if (it > r * c * 2)
			return false;
		sx += DX[sd];
		sy += DY[sd];
		sd = (sd + 2) % 4;
//		eprintf("%d %d %d - %d %d %d\n", sx, sy, sd, tx, ty, td);
		if (!inF(sx, sy) )
			return false;

		if (f[sx][sy] == 0)
		{
			int nd = (sd + 1) % 4;
			if (sx == tx && sy == ty)
				nd = td;
			if (nd == (sd ^ 1) )
				f[sx][sy] = '/';
			else
				f[sx][sy] = '\\';
//			eprintf("%d %d : %c\n", sx, sy, f[sx][sy] );
		}

		if (f[sx][sy] == '/')
			sd ^= 1;
		else
			sd ^= 3;
//		eprintf("%d %d %d - %d %d %d\n\n", sx, sy, sd, tx, ty, td);
	}
	return true;
}

void solve()
{
	memset(f, 0, sizeof f);
	scanf("%d%d", &r, &c);
	for (int i = 0; i < (r + c); i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		color[a] = i;
		color[b] = i;
	}
	for (int it = 0; it < (r + c); it++)
	{
		vector <pair <int, int> > v;
		for (int i = 0; i < 2 * (r + c); i++)
			if (color[i] != -1)
				v.emplace_back(i, color[i] );
		int fnd = -1;
		for (int i = 0; i + 1 < (int) v.size(); i++)
			if (v[i].second == v[i + 1].second)
			{
				fnd = i;
				break;
			}
		if (fnd == -1)
		{
			printf("IMPOSSIBLE\n");
			return;
		}
		int a = v[fnd].first;
		int b = v[fnd + 1].first;
		if (!makePath(a, b) )
		{
			printf("IMPOSSIBLE\n");
			return;
		}
		color[a] = color[b] = -1;
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (f[i][j] == 0)
				f[i][j] = '\\';
			printf("%c", f[i][j] );
		}
		printf("\n");
	}
}

void multitest()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("Case #%d:\n", i);
		eprintf("Case #%d .. %d\n", i, n);
		solve();
	}


}

int main(int argc, char **)
{
	if (argc == 1)
		multitest();
	else
		solve();

	return 0;
}


