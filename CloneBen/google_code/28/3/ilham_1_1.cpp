#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i,n) for (i = 0; i < (n); i++)
#define FORI(i,a,b) for (i = (a); i <= (b); i++)
#define FORD(i,a,b) for (i = (a); i >= (b); i--)
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, -1, sizeof(a))
#define DBG(a) cerr << a << endl;
#define DEBUG 1

int tc, n, K;
int tab[16][1<<16];
int x[16], y[16];

int calc(int mask)
{
	int xmin, xmax, ymin, ymax, i;
	xmin = ymin = 64001; xmax = ymax = 0; 
	FOR(i, n)
	{
		if (mask & (1 << i))
		{
			ymin = min(ymin, y[i]);
			ymax = max(ymax, y[i]);
			xmin = min(xmin, x[i]);
			xmax = max(xmax, x[i]);
		}
	}
	return max(xmax - xmin, ymax - ymin);
}

int main()
{
	int i,j,k,t,m;

	scanf("%d", &tc);
	FOR(t, tc)
	{
		scanf("%d %d", &n, &K);
		m = 1 << n;
		FOR(i, n) scanf("%d %d", &x[i], &y[i]);
		FOR(i, K)
		{
			if (i == 0) FOR(j, m) tab[0][j] = calc(j);
			else
			{
				FOR(j, m) 
				{
					tab[i][j] = 64001;
					for(k = (j - 1) & j; k > 0; k = (k - 1) & j)
						tab[i][j] = min(tab[i][j], max(tab[0][k], tab[i-1][j^k]));
				}
			}
		}
		printf("Case #%d: ", t+1);
		printf("%d\n", tab[K-1][m-1]);
	}
	return 0;
}

