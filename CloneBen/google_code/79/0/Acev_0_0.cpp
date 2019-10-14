#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>

#define MAX 1024

using namespace std;
FILE *in; FILE *out;

int n, m;
char a[MAX][MAX];

void eval(int testNum)
{
	fscanf(in, "%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		fscanf(in, "%s", a[i]);
	
	int flag = 1;
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < m; col++)
		{
			if (a[row][col] == '#')
			{
				if (row + 1 >= n || col + 1 >= m)
					{flag = 0; break;}
				if (a[row][col + 1] != '#' || a[row + 1][col] != '#' || a[row + 1][col + 1] != '#')
					{flag = 0; break;}
				
				a[row][col] = '/';
				a[row][col + 1] = '\\';
				a[row + 1][col] = '\\';
				a[row + 1][col + 1] = '/';
			}
		}
		if (!flag) break;
	}
	if (!flag) fprintf(out, "Impossible\n");
	else
	{
		for (int i = 0; i < n; i++)
			fprintf(out, "%s\n", a[i]);
	}
}

int main(void)
{
	unsigned sTime = clock();
	in = fopen("SquareTiles.in", "rt");
	out = fopen("SquareTiles.out", "wt");
	
	int numTests;
	fscanf(in, "%d", &numTests);
	for (int test = 1; test <= numTests; test++)
	{
		fprintf(stderr, "Currently executing testcase %d...\n", test);
		fprintf(out, "Case #%d:\n", test);
		eval(test);
	}
	
	fprintf(stderr, "Total execution time %.3lf seconds.\n", (double)(clock() - sTime) / (double)CLOCKS_PER_SEC);
	system("pause");
	return 0;
}
