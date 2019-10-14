#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <memory.h>
using namespace std;

char a[55][55];
int n, m;

bool test(int i, int j)
{
	if (a[i][j] != '#')
		return false;
	if (i - 1 >= 0)
		if (a[i - 1][j] == '#')
			return false;
	if (j - 1 >= 0)
		if (a[i][j - 1] == '#')
			return false;
	if (i + 1 < n && j + 1 < m)
	{
		return a[i + 1][j] == '#' && a[i + 1][j + 1] == '#' && a[i][j + 1] == '#';
	}
	return false;
}

bool solve()
{
	bool was = true;
	while (was)
	{
		was = false;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (test(i, j))
				{
					a[i][j] = '/';
					a[i][j + 1] = '\\';
					a[i + 1][j] = '\\';
					a[i + 1][j + 1] = '/';
					was = true;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (a[i][j] == '#')
				return false;
	return true;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
			scanf("%s", a[i]);
		printf("Case #%d:\n", t + 1);
		if (solve())
		{
			for (int i = 0; i < n; ++i)
				printf("%s\n", a[i]);
		}
		else
			printf("Impossible\n");
	}


	
	return 0;
}